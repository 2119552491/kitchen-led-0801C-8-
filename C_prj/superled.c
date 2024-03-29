//==============================================================================
//==============================================================================
#include "XL_common.h"
//==============================================================================
//==============================================================================
    
void main(void)
{           
	FSR = 0;
	INTEN = 0;
	INTFLAG = 0; 

	PORTA = 0x00;  //
	IOSTA = 0x00;//(T_Key1_mode | output_key1_mode | T_Key2_mode);  // 11 1000 PB0 is out,PB1,2,3,4is input	//PB3要加上拉

	PORTB = GPIO_INIT_;  //  
	IOSTB = GPIO_INIT_;//0011-1001     1 input  0 output 
	PHCON = ~0x18; // GPIO_INIT_ 0x33   0x00;//   PB1,2,3,4上拉打开
	//PDCON = ~0x80;      
//	PCON  = 0x00;   // 开低电压检测，看门狗
                    

#if XL_Sleep_IC
	WUCON = GPIO_INIT_;//GPIO_INIT_; 
#endif 
	asm { 
           MOVIA     30H
           MOVAR     10H                           
           MOVIA     11H         
           MOVAR     0X4     
CLRR_RAM_LOOP:                                            
           CLRR      0X0                                                         
           INCR      0X4,1
           DECRSZ    0X10,1               
           GOTO      CLRR_RAM_LOOP                 
           CLRR      10H      
           CLRR      0X4
	}

	OPTION = 0x00;
	TMR0 = 0XFF - 98 + 1;  

	short_mode_init_F = 1;// a 
	short_mode_init_F = 1;
#if XL_parameter | XL_24C02          
//	Delay10us();
//	Delay10us();  
 //	Delay10us();
	read_comval(); 
	read_comval(); 
    
	if(g_comval.setflag != 0xA5 )  ///g_comval. g_comval.
#endif 
	{
#if XL_parameter | XL_24C02   
		g_comval.setflag = 0xA5;
#endif 
       		g_comval.IR_LED_ON_F= 1;
#if RGB_color

		g_comval.led_mode   =  Color_mode_Max  + 2;//Color_mode_RGB_Max  g_comval.led_mode Color_mode_Max + Color_mode_Max + +  RTC_mode_Max + 1 7 RTC_mode_Max + 3
		g_comval.led_speed  = led_speed_Mid      ; //    led_speed_Max   
		g_comval.led_level  = led_level_Max;//
#endif
	}
         
#if PMW
	FSR_.RP0 = 1;   
	
	0x0f=0X80;
	T1C = 00;
	T1R = 00;
	PWM0R = 00;
	PWM1R = 00;
	PWM2R = 00;
	PWMCON = 0X00;   
     
        FSR_.RP0 = 0; 
#endif    
         
	INTEN = 0x81;  // 0x81 开TMR0 INT & Global INT
            
#if GPC_LVD   // #endif
	PCON  = 0x39;   //001 100101 开低电压检测，看门狗 
	0x05  = 0x08;      
#endif 
            
	while (1)
	{         /*
	if (PORTB_.IOB1 == 0 )  //> LED_duty
		PORTB_.IOB1 = 1;
	else
		PORTB_.IOB1 = 0;  */
#if XL_Wuxian		   
		IR_DECODE();
		IR_KEY_DEAL();
#endif	   
		time_50us_tick_function();
	}

}
#if XL_parameter | XL_24C02          
byte       for_save_temp;
#endif 


void interrupt HW_isr(void) @HWINT_BASE // 中断服务 中断周期8ms       8MHZ/2T/DIV256 倍频
{                 
#if XL_parameter | XL_24C02          
	for_save_temp  = FSR ;  
#endif 
 
	FSR = 0;
#if XT_Clock
	if (INTFLAG_.T1IF)
	{       
		INTFLAG_.T1IF = 0;
#else
	if (INTFLAG_.T0IF)
	{       
		INTFLAG_.T0IF = 0;  
		TMR0 = 0XFF - 90 + 1;   
#endif
#if XL_Wuxian	
		ir_tick++;
	//	IR_DECODE();
	//	IR_KEY_DEAL();
#endif
#if RGB_color            
                
		if ( LED_G == LED_OFF ) 
			LED_G = LED_ON;
		else
			LED_G = LED_OFF; 

	#if PMW      
			FSR_.RP0 = 1;  
			
			if ( g_comval.IR_LED_ON_F == 1) // kaiji  
			{            
				         /*  
				if( LED_B_PWM_temp == 0xff )
				{
					PWMCON_.PWM2OE = 0;   //b2 
					LED_B = 1; 
				}
				else
				{       
					PWM2R          = LED_B_PWM_temp;
					PWMCON_.PWM2OE = 1;   //b2  
				} 
				        
				if( LED_R_PWM_temp == 0xff ) 
				{
					PWMCON_.PWM1OE = 0;   //b1 
					LED_R = 1; 
				}
				else
				{        
					PWM1R          = LED_R_PWM_temp;
					PWMCON_.PWM1OE = 1;   //b1
				}
				         */
			//	if( LED_G_PWM_temp == 0xff )
				{
			//		PWMCON_.PWM0OE = 0;   //b0 
			//		LED_G = 1;  
				}
			//	else
				{               
				//	0x09 = 0X84;   //PWMCON
				//	0x0d          = LED_R_PWM_temp;
					PWMCON = 0X84; 
					PWM2R          = LED_R_PWM_temp;
				//	PWMCON_.PWM2OE = 1;   //b0 
				}    
			}       
			else  // guanji
			{         
				PWMCON = 0X00; 
				PWM2R = 0; 
			//	LED_R = 0;   
			//	LED_G = 0;
				LED_R = LED_OFF;  
			//	LED_R = 0;   
			//	LED_G = 0;
			//	LED_B = 0;  
			//	PWMCON_.PWM2OE = 0;
			//	PWMCON_.PWM1OE = 0;
			//	PWMCON_.PWM0OE = 0; 
			}  
			
			FSR_.RP0 = 0;   
	#else  
                          
		if (LED_duty >= led_level_Max )//100 led_level_Max
			LED_duty = 0; 
		if (LED_R_PWM_temp > LED_duty) 
	//	if ( LED_R == LED_OFF ) 
			LED_R = LED_ON;
		else
			LED_R = LED_OFF; 
			

/*
		if (LED_G_PWM_temp > LED_duty)
			LED_G = 1;
		else
			LED_G = 0;

		if (LED_B_PWM_temp > LED_duty)
			LED_B = 1;
		else
			LED_B = 0; */
		LED_duty++;  
	#endif	   
#endif
		time_50us_tick++;
	}

#if XT_Clock
	if (INTFLAG_.T0IF)
	{       
		INTFLAG_.T0IF = 0;  
#if XL_Sleep_time 
		Sleep_time_1s_tick++;//sleep_time_deal_function();     
		
		if( Sleep_time_warning_F )
		{	        
			Sleep_time_warning_F--;
			if( T_Key1_Signal ) 
				T_Key1_Signal = 0;
			else
				T_Key1_Signal = 1;  
		}
		else    T_Key1_Signal = 0;
		        
#endif  	
	}
#else
	INTFLAG = 0; // 清所有断标志
#endif

		
//	INTFLAG = 0; // 清所有断标志
#if XL_parameter | XL_24C02          
	FSR   = for_save_temp ; 
#endif 


}


