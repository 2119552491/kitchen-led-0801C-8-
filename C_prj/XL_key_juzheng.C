
#include "XL_common.h"

void Key_scan();

#if XL_Key_juzheng

#if XL_key_1
	byte key1_tick;
	bit KEY_long_time_F1;
#endif

#if XL_key_2
	byte key2_tick;
	bit KEY_long_time_F2;
#endif

#if XL_key_3
	byte key3_tick;
	bit KEY_long_time_F3;
#endif

#if XL_key_4
	byte key4_tick;
	bit KEY_long_time_F4;
#endif

#if XL_key_5
	byte key5_tick;
	bit KEY_long_time_F5;
#endif

byte juzheng_key_scan_step;
byte key_F;

void Key_scan()
{
	switch( juzheng_key_scan_step )
	{
		case 0: //   
		{
		//	IOSTB = 0x38;//(T_Key1_mode  | T_Key2_mode);  // | output_key1_mode   11 1000 PB0 is out,PB1,2,3,4is input	//PB3鐟曚礁濮炴稉濠冨 
		//	PHCON = ~0x38; // output_key1_mode | PB1,2,3,4娑撳﹥濯洪幍鎾崇磻 

			Delay10us();
			Delay10us();
			Delay10us();
			juzheng_key_scan_step = 1;
			output_key1 = 1;
			{
				if ( T_Key1_Signal == 0 || T_Key2_Signal == 0 )//
				{
						key2_tick = 0;
						//key3_tick = 0;
						
						if ( key1_tick >= key_short_time )
						{               
							juzheng_key_scan_step = 0;
							if (  T_Key1_Signal  == 0   ) 		  // 
							{
								key_F = 2;
#if long_key_
								if ( key1_tick >= key_short_time )
								{
									key1_tick = key_short_time;
								}
#endif
							}
							else if ( T_Key2_Signal  == 0 )
							{
								key_F = 4;
#if long_key_
								if ( key1_tick >= key_long_time )
								{
									key1_tick = key_long_time;
									KEY_long_time_F1 = 1;
									IR_KEY_L_deal = 201;
								}
#endif
							}  /*
							else if ( output_key1  == 0 )
							{
								key_F = 4;
								if ( key1_tick >= key_long_time )
								{
									key1_tick = key_long_time;
									KEY_long_time_F1 = 1;
									IR_KEY_L_deal = 203;
								}
							}*/
						}
				}
				else
				{
					if ( key1_tick >= key_short_time  ) // || key2_tick >= key_short_time
					{
						short_mode_init_F =1;
						switch( key_F )
						{
							case 2: //   
#if long_key_
								if( KEY_long_time_F1 == 0 )
#endif
								{
									short_key_sub();
									IR_KEY_L_deal = 0;
								}
								break;
							case 4:// add
								if( g_comval.IR_LED_ON_F == 0  )
									g_comval.IR_LED_ON_F = 1;
								else
								{
									g_comval.IR_LED_ON_F = 0;
								//	Time_mode   = 0;
								}
								break;
							default:
								break;
						}
						#if XL_24C02 | XL_parameter
						    save_comval();
						#endif
					}
				//	key_F = 0;
					KEY_long_time_F1 = 0;
					key1_tick = 0;
				//	key2_tick = 0;
				//	key3_tick = 0;
				}
			}
		}
		break;                
		case 1:
		{       
			//IOSTB = 0x28;//(T_Key1_mode  | T_Key2_mode);  // | output_key1_mode   11 1000 PB0 is out,PB1,2,3,4is input	//PB3鐟曚礁濮炴稉濠冨 
			//PHCON = ~0x28; // output_key1_mode | PB1,2,3,4娑撳﹥濯洪幍鎾崇磻 

			Delay10us();
			Delay10us();
			Delay10us();
			juzheng_key_scan_step = 0;
			output_key1 = 0;
			{
				if ( T_Key1_Signal == 0 || T_Key2_Signal == 0  )//
				{
				//	key3_tick = 0;
					if ( key2_tick >= key_short_time )
					{           
						key1_tick = 0;
						juzheng_key_scan_step = 1;
						key2_tick = key_short_time;
						if (  T_Key1_Signal  == 0   ) 		  // 
						{
							key_F = 1;
						}
						else if (  T_Key2_Signal  == 0   )
						{
							key_F = 3;
						}
					}
				}
				else
				{
					if ( key2_tick >= key_short_time )// ||  key4_tick >= key_short_time
					{
						short_mode_init_F = 1;
						
						switch( key_F )
						{
							case 1: //   
#if long_key_
								if( KEY_long_time_F1 == 0 )
#endif
								{
									short_key_add();
									IR_KEY_L_deal = 0;
								}
								break;
							case 3:
								g_comval.led_mode++;
								break;
							default:
								break;
						}
						#if XL_24C02 | XL_parameter
						    save_comval();
						#endif
					}
				//	key_F = 0;
				//	key1_tick = 0;
					key2_tick = 0;
				//	key3_tick = 0;
				}
			}
		}
		break;
		default:
			break;
	}
}

#endif