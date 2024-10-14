#pragma once

#include "defs.h"

extern volatile unsigned long long ticks;

void clock_init(void);

void clock_set_next_event(void);

uint64_t get_cycles(void);