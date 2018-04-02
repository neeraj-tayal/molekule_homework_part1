#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool create_event(uint32_t start_time, void (*action));
void evaluate_and_execute_events(uint32_t cur_time);

#endif
