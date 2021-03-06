/*
* Copyright 2020 NimoLabs Ltd.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* File: atsamd21.c
* Description: SAMD21 delay / SysTick device driver
*/

#include <sam.h>
#include <printf.h>
#include "delay.h"

void delaySetup(unsigned int baseTimer)
{
    unsigned long divisor;
    switch (baseTimer)
    {
    case DELAY_BASE_MICRO_SEC:
        divisor = 1000000;
        break;
    case DELAY_BASE_MILLI_SEC:
        divisor = 1000;
        break;
    default:
        printf("Error: delaySetup()\r\n");
        return;
        break;
    }
    SysTick_Config(UP_CLK / divisor);
}

void irq_handler_sys_tick(void)
{
    sysTickTicks++;
}