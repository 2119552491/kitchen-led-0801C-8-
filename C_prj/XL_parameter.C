#include "XL_common.h"
//==============================================================================
//============================================================================== 
 
g_comval_t g_comval;
#define	COMVAL_VALID	0xA5 
   /*
u8 IR_LED_ON_F;
byte led_level;
byte led_mode;
byte setflag;    
*/
#if XL_parameter   
/*
	u8 led_mode;                        
	u8 IR_LED_ON_F; 
	u8 led_level;	
//	u8 led_num;			//灯的模式  
	u8 led_speed;     
*/
       
void save_comval()
{
	FSR_.RP0=1;			//bank1  

	E2PADR=0;								E2PCON_.SER=1;	while(E2PCON_.SER);	//等擦除16byte结束
	E2PDIN=g_comval.setflag;				E2PCON_.WR=1;	while(E2PCON_.WR); 
	E2PADR++;E2PDIN=g_comval.led_mode;		E2PCON_.WR=1;	while(E2PCON_.WR); 
	E2PADR++;E2PDIN=g_comval.IR_LED_ON_F;	E2PCON_.WR=1;	while(E2PCON_.WR);   
	E2PADR++;E2PDIN=g_comval.led_level;		E2PCON_.WR=1;	while(E2PCON_.WR); 
	E2PADR++;E2PDIN=g_comval.led_speed;		E2PCON_.WR=1;	while(E2PCON_.WR); 

	FSR_.RP0=0;			//bank0
}     

void read_comval()
{
	FSR_.RP0=1;		//bank1

	E2PADR=0;E2PCON_.RD=1;g_comval.setflag		= E2PDAT;
	E2PADR++;E2PCON_.RD=1;g_comval.led_mode		= E2PDAT;
	E2PADR++;E2PCON_.RD=1;g_comval.IR_LED_ON_F	= E2PDAT; 
	E2PADR++;E2PCON_.RD=1;g_comval.led_level	= E2PDAT;
	E2PADR++;E2PCON_.RD=1;g_comval.led_speed	= E2PDAT;

	FSR_.RP0=0;		//bank0
}  

#endif