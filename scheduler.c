#include "scheduler.h"

#define MAX_SCHEDULED_EVENTS 64

uint32_t scheduled_times[MAX_SCHEDULED_EVENTS];
void (*scheduled_actions[MAX_SCHEDULED_EVENTS])();
static uint8_t event_count=0;


bool create_event(uint32_t start_time, void (*action)){
	//static uint8_t event_count=0;
	if (event_count>=MAX_SCHEDULED_EVENTS){
		return false;
	}
	scheduled_times[event_count]=start_time;
	scheduled_actions[event_count]=action;
	//printf("Event %d created\n",event_count);
	event_count+=1;
	//printf("Event %d created",event_count);
	return true;
}

void evaluate_and_execute_events(uint32_t cur_time){
	for(uint8_t i=0; i<event_count; i++){
		if(scheduled_times[i] == cur_time){
			(*scheduled_actions[i])();
		}
	}
}

