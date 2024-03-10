                      
                      
typedef unsigned char byte;
typedef unsigned long word;      

/*
	  +			 -
 B5	  key		B	B0
 B4	  IR			B1
 B3	  G			R	B2
*/
#define LED_ON		        1 
#define LED_OFF      		0   

#define shenya 	   		PORTB_.IOB0       
      

#define LED_B  			         PORTB_.IOB0 //PORTA_.IOA3 // 13 PORTA_.IOA5 // 13 
#define LED_G  			         PORTB_.IOB1 //PORTA_.IOA5 //  pow_led
#define LED_R  			         PORTB_.IOB2 //PORTA_.IOA4 //  jdq  

#define IR_in      			 PORTB_.IOB4//PB.1PB.6    //4
#define IR_in_mode   		 	 0x10//PAC.5    //4

#define GPIO_INIT_  	 	0x39	//0x33//T_Key1_mode | T_Key2_mode | T_Key3_mode | T_Key4_mode |T_Key5_mode
//#define GPIO_INIT_  	 	0x38	//0x33//T_Key1_mode | T_Key2_mode | T_Key3_mode | T_Key4_mode |T_Key5_mode
//#define GPIO_INIT_sleep  	0x38	//0x33//T_Key1_mode | T_Key2_mode | T_Key3_mode | T_Key4_mode |T_Key5_mode
          
#define XL_key_3 		1        
#define XL_key_4 		1         
#if    XL_key_3
	#define T_Key3_Signal 	   	PORTB_.IOB4//PORTA_.IOA1     1
	#define T_Key3_mode 	   	   0x01//PORTB_.IOB3//0x02 
#endif 

#if    XL_key_4                                            
	#define T_Key4_Signal 	   	PORTB_.IOB5    
	#define T_Key4_mode 	   	0x02
#endif  


#if 0   
#if    XL_key_5   
	#define T_Key5_Signal 	   	PORTB_.IOB3	//PORTA_.IOA1   2
	#define T_Key5_mode 	   	   0x08		//PORTB_.IOB3//0x02                                           
#endif

#define XL_key_1 		1
#if    XL_key_1//
	#define T_Key1_Signal 	   	PORTB_.IOB3           // 0
	#define T_Key1_mode 	    0x20  
#endif 

#define XL_key_2 		1
#if    XL_key_2//        
	#define XL_key_2_long   	1 
	#define T_Key2_Signal 	   	PORTB_.IOB5         // 1
	#define T_Key2_mode 	   	   0x20
#endif 

#define fa_she      		   			PORTA_.IOA0//PA.7    //4
#define fa_she_mode   					~0x01//PAC.5    //4 

#define AD_power      		   			PORTB_.IOB7//PA.6    //4
#define AD_power_mode   				~0x80//PAC.5    //4 


#define SMG_6_mode 		   ~0x40//PORTB_.IOB6//PA.50x20//PA.3
#define SMG_5_mode 		   ~0x20//PA.4 // pb.3
#define SMG_4_mode		   ~0x10//PA.0//PA.7
#define SMG_3_mode 		   ~0x04//PA.5  //
#define SMG_2_mode 		   ~0x02//PA.7
#define SMG_1_mode 		   ~0x01//PA.6
/*
#define SMG_6_modeC       PAC.5// 0x20//PA.7
#define SMG_5_modeC       PBC.4// 0x20//PA.7
#define SMG_4_modeC       PBC.5// 0x20//PA.7
#define SMG_3_modeC       PBC.2// 0x20//PA.7
#define SMG_2_modeC       PBC.0// 0x20//PA.7
#define SMG_1_modeC       PBC.1// 0x20//PA.7
*/
#define SMG_6 		   	   PORTB_.IOB6//PA.5
#define SMG_5 		   	   PORTB_.IOB5//PB.4 
#define SMG_4 		   	   PORTB_.IOB4//PB.5  // 
#define SMG_3		   	   PORTB_.IOB2//PB.2//PA.7
#define SMG_2 		   	   PORTB_.IOB1//PB.0 // pb.3
#define SMG_1 		   	   PORTB_.IOB0//PB.1



#define XL_key_2 		0
#define XL_key_3 		0
#define XL_key_4 		0
#define XL_key_5 		0
      
#define XL_key_1_long   0

#define XL_key_3_long   0
#define XL_key_4_long   0
#define XL_key_5_long   0

//#define WS2812_IO          	PORTB_.IOB2 // 13   

#define output_key1		   	     PORTB_.IOB3
#define output_key1_mode	     0x08//PAC.6

#define IR_in 					PORTB_.IOB5 // 13 
#define IR_in_mode 				0x20 // 13     

#define LED_W 			         PORTB_.IOB3 //PORTA_.IOA3 // 13 PORTA_.IOA5 // 13 

//#define LED_W 			         PORTB_.IOB3 //PORTA_.IOA3 // 13 PORTA_.IOA5 // 13                            


      
                                             

#define SMG_a                         PORTA_.IOA0//
#define SMG_b 		   	      PORTA_.IOA1//PA.5
#define SMG_c 		   	      PORTA_.IOA2//PB.7  // 
#define SMG_d		   	      PORTA_.IOA3//PB.4//PA.7   

#define SMG_e 		   	      PORTB_.IOB0//PA.3// PORTA_.IOA4//PA.0 // pb.3
#define SMG_f 		   	      PORTB_.IOB1//PA.3 //PORTA_.IOA5//PA.4 
#define SMG_g 		   	      PORTB_.IOB2//PA.3                     

#define SMG_gewei 		      PORTB_.IOB7//PB.3  // 
#define SMG_shiwei		      PORTB_.IOB6//PB.1//PA.7   

#define output_key1		   	PORTB_.IOB4 
#define output_key1_mode	   0x10//PAC.6          

#define GLJC 			PORTA_.IOA1 // 13 
#define GLJC_in_mode 		0x02 // 13  
       
               
                       
#define IN_mode_init 	   	0xCF         
#define Jingzheng_IN_mode_init 	0x38 
           
#define SCL     	   	PORTB_.IOB0//PORTA_.IOA1     
#define SCL_mode   	   	0x01//0x02    //4  SCL_mode  SDA_C  
               
#define U1_2 	           	PORTA_.IOA0             
#define U1_2mode 	        0x01  

#define SDA       		PORTA_.IOA2//PORTA_.IOA4
#define SDA_C    		0x04//0x10   //3
                                      
#define Motor 			PORTB_.IOB0 // 13   

#define MOS 		   	PORTB_.IOB3                             
                             
 
#endif
     
     
/*
#define LED_Y PORTB_.IOB2 // 1   3
#define LED_W PORTB_.IOB0 // 3   2
*/


