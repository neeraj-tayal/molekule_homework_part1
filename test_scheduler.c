#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "scheduler.h"

void turnOnSprinklerA(){
        printf("Sprinkler A turned on\r\n");
}

void turnOnSprinklerB(){
        printf("Sprinkler B turned on\r\n");
}

void init(){
	create_event(1, &turnOnSprinklerA);
	create_event(2, &turnOnSprinklerB);
}

uint32_t get_time(){
	static uint32_t time=0;
	return time++;
}

void test_evaluate_and_execute_events(){
	printf("Testing action triggers\r\n");	
        init();	
        for(uint32_t time=get_time(); time<10; time=get_time()){
		printf("Time is %u\r\n", time);
                evaluate_and_execute_events(time);
        }
	printf("\r\n");

}

void test_max_event_creation(){
	printf("Testing max event creation response\r\n");
	for(uint8_t i=2; i<66; i++){
		bool create_event_response = create_event(5, &turnOnSprinklerA);
		if(i>=62) printf("Event %u returned: %s\r\n", i, create_event_response ? "true":"false");
	}
	printf("\r\n");
}

int main(){
	test_evaluate_and_execute_events();
	test_max_event_creation();	
}


