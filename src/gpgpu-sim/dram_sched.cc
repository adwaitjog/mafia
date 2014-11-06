// Copyright (c) 2009-2011, Tor M. Aamodt, Ali Bakhoda, George L. Yuan,
// The University of British Columbia
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// Redistributions in binary form must reproduce the above copyright notice, this
// list of conditions and the following disclaimer in the documentation and/or
// other materials provided with the distribution.
// Neither the name of The University of British Columbia nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "dram_sched.h"
#include "gpu-misc.h"
#include "gpu-sim.h"
#include "../abstract_hardware_model.h"
#include "mem_latency_stat.h"
extern int gpu_sms;
extern int gpu_mode3;
extern int gpu_sms_app1;

frfcfs_scheduler::frfcfs_scheduler( const memory_config *config, dram_t *dm, memory_stats_t *stats )
{
   m_config = config;
   m_stats = stats;
   m_num_pending = 0;
   m_dram = dm;
   m_queue = new std::list<dram_req_t*>[m_config->nbk];
   last_core_id = new unsigned[m_config->nbk]; //new
   m_bins = new std::map<unsigned,std::list<std::list<dram_req_t*>::iterator> >[ m_config->nbk ];
   m_last_row = new std::list<std::list<dram_req_t*>::iterator>*[ m_config->nbk ];
   curr_row_service_time = new unsigned[m_config->nbk];
   row_service_timestamp = new unsigned[m_config->nbk];
   for ( unsigned i=0; i < m_config->nbk; i++ ) {
      m_queue[i].clear();
      m_bins[i].clear();
      m_last_row[i] = NULL;
	  //last_core_id[i] = 200; //new
      curr_row_service_time[i] = 0;
      row_service_timestamp[i] = 0;
   }

}

int frfcfs_scheduler::find_app(int sid) 
{		
	assert(gpu_sms >= m_config->gpgpu_num_groups);
	//printf("gsm = %d, sid=%d\n", gpu_sms,  sid);
	assert(sid < gpu_sms);
	
	int group_size;
	if(gpu_mode3){
		group_size =(int)gpu_sms/m_config->gpgpu_num_groups;
		int group_number = (int)sid/group_size;
		return (group_number + 1);
		
	}	
	else{
		group_size =gpu_sms_app1;
		
		if(sid < group_size){
			return 1;
		}else
			return 2;
		
	}
}

void frfcfs_scheduler::add_req( dram_req_t *req )
{
   m_num_pending++;
   m_queue[req->bk].push_front(req);
   std::list<dram_req_t*>::iterator ptr = m_queue[req->bk].begin();
   m_bins[req->bk][req->row].push_front( ptr ); //newest reqs to the front
}

void frfcfs_scheduler::data_collection(unsigned int bank)
{
   if (gpu_sim_cycle > row_service_timestamp[bank]) {
      curr_row_service_time[bank] = gpu_sim_cycle - row_service_timestamp[bank];
      if (curr_row_service_time[bank] > m_stats->max_servicetime2samerow[m_dram->id][bank])
         m_stats->max_servicetime2samerow[m_dram->id][bank] = curr_row_service_time[bank];
   }
   curr_row_service_time[bank] = 0;
   row_service_timestamp[bank] = gpu_sim_cycle;
   if (m_stats->concurrent_row_access[m_dram->id][bank] > m_stats->max_conc_access2samerow[m_dram->id][bank]) {
      m_stats->max_conc_access2samerow[m_dram->id][bank] = m_stats->concurrent_row_access[m_dram->id][bank];
   }
   m_stats->concurrent_row_access[m_dram->id][bank] = 0;
   m_stats->num_activates[m_dram->id][bank]++;
	m_stats->num_activates_w[m_dram->id][bank]++;

	if (find_app(last_core_id[bank]) == 1) {
		m_stats->num_activates_w1[m_dram->id][bank]++;
		m_stats->num_activates_1[m_dram->id][bank]++;
	}

	if ((find_app(last_core_id[bank]) == 2)) {
		m_stats->num_activates_w2[m_dram->id][bank]++;
		m_stats->num_activates_2[m_dram->id][bank]++;
	}
	if ((find_app(last_core_id[bank]) == 3)) {
		m_stats->num_activates_w3[m_dram->id][bank]++;
		m_stats->num_activates_3[m_dram->id][bank]++;
	}
   

}

dram_req_t *frfcfs_scheduler::schedule( unsigned bank, unsigned curr_row )
{
   if ( m_last_row[bank] == NULL ) {
      if ( m_queue[bank].empty() )
         return NULL;

      std::map<unsigned,std::list<std::list<dram_req_t*>::iterator> >::iterator bin_ptr = m_bins[bank].find( curr_row );
      if ( bin_ptr == m_bins[bank].end()) {
         dram_req_t *req = m_queue[bank].back();
         bin_ptr = m_bins[bank].find( req->row );
         assert( bin_ptr != m_bins[bank].end() ); // where did the request go???
         m_last_row[bank] = &(bin_ptr->second);
         data_collection(bank);
		 last_core_id[bank] = req->data->get_sid(); //new
      } else {
         m_last_row[bank] = &(bin_ptr->second);

      }
   }
   std::list<dram_req_t*>::iterator next = m_last_row[bank]->back();
   dram_req_t *req = (*next);

   m_stats->concurrent_row_access[m_dram->id][bank]++;
   m_stats->row_access[m_dram->id][bank]++;
   m_last_row[bank]->pop_back();
   
	if (find_app(last_core_id[bank]) == 1) {
		m_stats->row_access_w1[m_dram->id][bank]++;
		m_stats->row_access_1[m_dram->id][bank]++;
		//printf("in row_access_1\n");
	}

	if (find_app(last_core_id[bank]) == 2) {
		m_stats->row_access_w2[m_dram->id][bank]++;
		m_stats->row_access_2[m_dram->id][bank]++;
	}
	
	if (find_app(last_core_id[bank]) == 3) {
		m_stats->row_access_w3[m_dram->id][bank]++;
		m_stats->row_access_3[m_dram->id][bank]++;
	}

   m_queue[bank].erase(next);
   if ( m_last_row[bank]->empty() ) {
      m_bins[bank].erase( req->row );
      m_last_row[bank] = NULL;
   }
#ifdef DEBUG_FAST_IDEAL_SCHED
   if ( req )
      printf("%08u : DRAM(%u) scheduling memory request to bank=%u, row=%u\n", 
             (unsigned)gpu_sim_cycle, m_dram->id, req->bk, req->row );
#endif
   assert( req != NULL && m_num_pending != 0 ); 
   m_num_pending--;

   return req;
}


void frfcfs_scheduler::print( FILE *fp )
{
   for ( unsigned b=0; b < m_config->nbk; b++ ) {
      printf(" %u: queue length = %u\n", b, (unsigned)m_queue[b].size() );
   }
}

void dram_t::scheduler_frfcfs()
{
   unsigned mrq_latency;
   frfcfs_scheduler *sched = m_frfcfs_scheduler;
   while ( !mrqq->empty() && (!m_config->gpgpu_frfcfs_dram_sched_queue_size || sched->num_pending() < m_config->gpgpu_frfcfs_dram_sched_queue_size)) {
      dram_req_t *req = mrqq->pop();

      // Power stats
      //if(req->data->get_type() != READ_REPLY && req->data->get_type() != WRITE_ACK)
      m_stats->total_n_access++;

      if(req->data->get_type() == WRITE_REQUEST){
    	  m_stats->total_n_writes++;
      }else if(req->data->get_type() == READ_REQUEST){
    	  m_stats->total_n_reads++;
      }

      req->data->set_status(IN_PARTITION_MC_INPUT_QUEUE,gpu_sim_cycle+gpu_tot_sim_cycle);
      sched->add_req(req);
   }

   dram_req_t *req;
   unsigned i;
   for ( i=0; i < m_config->nbk; i++ ) {
      unsigned b = (i+prio)%m_config->nbk;
      if ( !bk[b]->mrq ) {

         req = sched->schedule(b, bk[b]->curr_row);

         if ( req ) {
            req->data->set_status(IN_PARTITION_MC_BANK_ARB_QUEUE,gpu_sim_cycle+gpu_tot_sim_cycle);
            prio = (prio+1)%m_config->nbk;
            bk[b]->mrq = req;
            if (m_config->gpgpu_memlatency_stat) {
               mrq_latency = gpu_sim_cycle + gpu_tot_sim_cycle - bk[b]->mrq->timestamp;
			   
               if (find_app(req->data->get_sid()) == 1){ //mrq
                   
				//printf ("mrq1\n");
				m_stats->mrqs_latency[0] += mrq_latency;
                   m_stats-> mrq_num[0] ++;
                   
               }
               if (find_app(req->data->get_sid()) == 2){
                   //printf("mrq2\n");
				m_stats->mrqs_latency[1] += mrq_latency;
                   m_stats-> mrq_num[1] ++;
               }
               if (find_app(req->data->get_sid()) == 3){
                   //printf("mrq2\n");
				m_stats->mrqs_latency[2] += mrq_latency;
                   m_stats-> mrq_num[2] ++;
               }
               bk[b]->mrq->timestamp = gpu_tot_sim_cycle + gpu_sim_cycle;
               m_stats->mrq_lat_table[LOGB2(mrq_latency)]++;
               if (mrq_latency > m_stats->max_mrq_latency) {
                  m_stats->max_mrq_latency = mrq_latency;
               }
            }

            break;
         }
      }
   }
}
