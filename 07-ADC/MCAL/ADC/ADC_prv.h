/*
 * ADC_prv.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Hythm Saad Khalifa
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

#define            	ADMUX	                		*((volatile u8*)(0x27))
#define             ADCSRA	                		*((volatile u8*)(0x26))
#define             ADC	                		*((volatile u16*)(0x24))
#define             SFIOR	                		*((volatile u8*)(0x50))

#define             ADC_PRE_SC_2		            0
#define             ADC_PRE_SC_2		            1
#define             ADC_PRE_SC_4		            2
#define             ADC_PRE_SC_8		            3
#define             ADC_PRE_SC_16		            4
#define             ADC_PRE_SC_32		            5
#define             ADC_PRE_SC_64		            6
#define             ADC_PRE_SC_128		            7

#define             ADC_V_REF_AREFF		        	0x00
#define             ADC_V_REF_AVCC		        	0x01
#define             ADC_V_REF_INT_2.56	        	0x11

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

#define             ADC_MODE_FR_RUN		        	0
#define             ADC_MODE_ANA_COM	       		1
#define             ADC_MODE_EXT_INT_REQ       		2
#define             ADC_MODE_TI0_COM	       		3
#define             ADC_MODE_TI0_OV		        	4
#define             ADC_MODE_TI1_COMB	        	5
#define             ADC_MODE_TI1_OV		        	6
#define             ADC_MODE_TI1_CP_EVT	        	7


#endif /* MCAL_ADC_ADC_PRV_H_ */
