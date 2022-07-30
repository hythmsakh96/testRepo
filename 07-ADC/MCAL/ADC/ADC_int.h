/*
 * ADC_int.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_
#define             ADC_CH0  		                0
#define             ADC_CH1  		                1
#define             ADC_CH2  		                2
#define             ADC_CH3  		                3
#define             ADC_CH4  		                4
#define             ADC_CH5  		                5
#define             ADC_CH6  		                6
#define             ADC_CH7  		                7
#define             ADC_10_CH0_CH0	                8
#define             ADC_10_CH1_CH0   	            9
#define             ADC_200_CH0_CH0  	            10
#define             ADC_200_CH1_CH0  	            11
#define             ADC_10_CH2_CH2   	            12
#define             ADC_10_CH3_CH2   	            13
#define             ADC_200_CH2_CH2  	            14
#define             ADC_200_CH3_CH2		            15
#define             ADC_CH0_CH1	    	            16
#define             ADC_CH1_CH1	    	            17
#define             ADC_CH2_CH1	    	            18
#define             ADC_CH3_CH1	    	            19
#define             ADC_CH4_CH1	    	            20
#define             ADC_CH5_CH1	    	            21
#define             ADC_CH6_CH1	    	            22
#define             ADC_CH7_CH1	    	            23
#define             ADC_CH0_CH2	    	            24
#define             ADC_CH1_CH2	    	            25
#define             ADC_CH2_CH2	    	            26
#define             ADC_CH3_CH2	    	            27
#define             ADC_CH4_CH2	    	            28
#define             ADC_CH5_CH2	    	            29
#define             ADC_1.22_V	    	            30
#define             ADC_0V_GND	    	            31

void MADC_vInit(void);
u16  MADC_u16AnalRead(A_u8ChannelNo);
#endif /* MCAL_ADC_ADC_INT_H_ */
