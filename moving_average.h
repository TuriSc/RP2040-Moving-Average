/**
  ******************************************************************************
  * @file    moving_average.h
  * @author  Mohammad Hussein Tavakoli Bina, Sepehr Hashtroudi.
  * @brief   This file contains function prototype of moving average filter.
  * @remark  2023-01-07 - Edited by Turi Scandurra, optimizing
  *          data types for use with Raspberry Pi Pico.
  ******************************************************************************
  *MIT License
  *
  *Copyright (c) 2018 Mohammad Hussein Tavakoli Bina
  *
  *Permission is hereby granted, free of charge, to any person obtaining a copy
  *of this software and associated documentation files (the "Software"), to deal
  *in the Software without restriction, including without limitation the rights
  *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  *copies of the Software, and to permit persons to whom the Software is
  *furnished to do so, subject to the following conditions:
  *
  *The above copyright notice and this permission notice shall be included in all
  *copies or substantial portions of the Software.
  *
  *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  *SOFTWARE.
  */

#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H


/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Definitions ---------------------------------------------------------------*/
#define FILTER_WINDOW_SIZE 10

/**
  * @struct FilterTypeDef
  * @brief Data structure for the moving average filter.
  */
typedef struct{
	/**
	 * @brief Array to store values of filter window.
	 */
	uint16_t History[FILTER_WINDOW_SIZE];
	
	/**
	 * @brief Sum of filter window's elements.
	 */
	uint16_t Sum;
	
	/**
	 * @brief Pointer to the first element of window.
	 */
	uint16_t WindowPointer;
}FilterTypeDef;

/* Function prototypes -------------------------------------------------------*/
void Moving_Average_Init(FilterTypeDef* filter_struct);
uint16_t Moving_Average_Compute(uint16_t raw_data, FilterTypeDef* filter_struct);

#ifdef __cplusplus
}
#endif

#endif
