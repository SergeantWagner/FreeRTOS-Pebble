#ifndef __SNOWY_RTC_H
#define __SNOWY_RTC_H
/* 
 * This file is part of the RebbleOS distribution.
 *   (https://github.com/pebble-dev)
 * Copyright (c) 2017 Barry Carter <barry.carter@gmail.com>.
 * 
 * RebbleOS is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as   
 * published by the Free Software Foundation, version 3.
 *
 * RebbleOS is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.

 */
#include <time.h>
#include "rebble_time.h"

void rtc_init(void);
void rtc_config(void);
void hw_get_time_str(char *buf);
struct tm *hw_get_time(void);

// make sure we use the external osc
#define RTC_CLOCK_SOURCE_LSE

void rtc_set_timer_interval(TimeUnits tick_units);
void rtc_disable_timer_interval(void);
#endif
