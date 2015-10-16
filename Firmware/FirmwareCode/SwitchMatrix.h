/*
 * Copyright (c) 2015, Caleb Kemere
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * --/COPYRIGHT--
 *
 *******************************************************************************
 *
 *                       Rodent Stimulation Module (RSM) Firmware
 *
 * This file contains the code which controls the switch matrix that creates the
 * biphasic current pulse.
 *
 *   Input Current --------  S_IN1 \----------/ S_OUT1 ----|
 *                     |                 |                 |
 *                     |                 V                 |
 *                     |               BRAIN               |
 *                     |                 ^                 |
 *                     |                 |                 |
 *                     |---  S_IN2 \-----|----/ S_OUT2 ----|------ GND
 *
*/
#ifndef RATDBS_FIRMWARE_SWITCHMATRIX_H_
#define RATDBS_FIRMWARE_SWITCHMATRIX_H_

#include <msp430.h>
#include "Firmware.h"
#include "BatteryStatus.h"

typedef enum {FORWARD, REVERSE, GROUNDED, OFF} stimulationStateEnum;
extern stimulationStateEnum NextStimulationState;

extern volatile int disableStimulationFlag;

extern unsigned int jitterTableCounter;
extern const unsigned int jitterValueTable[];
extern const unsigned int jitterTableLength;

void SetupSwitchMatrix(void);
inline void DisableStimulation (void);
inline void EnableStimulation(void);
inline void SetPulseIntervals(uint16_t Period, uint16_t PulseWidth);
inline void SetJitterOffset(uint8_t JitterLevel);

#endif
