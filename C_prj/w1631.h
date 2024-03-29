#ifndef	_W1631_H
#define	_W1631_H
//--------------Misc instruction define---------------------------------------
#define		SLEEP()		asm("SLEEP")
#define		NOP()		asm("NOP")
#define		CLRWDT()	asm("CLRWDT")
#define		EN_IRQ()		INTEN_.GIE=1
#define		DIS_IRQ()		INTEN_.GIE=0
//--------------Interrupt vector address--------------------------------------
#define	SWINT_BASE		0x002
#define	HWINT_BASE		0x008
//--------------Control by IOST & OPTION Maps---------------------------------
unsigned char	OPTION : OPTION;
unsigned char	IOSTA @	0x05 : IOST;	//This register is only write, ignore volatile tag
unsigned char	IOSTB @	0x06 : IOST;	//This register is only write, Ignore volatile tag
//--------------Operation Registers Maps bank0 --------------------------------------
#if 0
#define		INDF		(*(unsigned char volatile *)0x00)
#define		TMR0		(*(unsigned char volatile *)0x01)
#define		PCL			(*(unsigned char volatile *)0x02)
#define		STATUS		(*(unsigned char volatile *)0x03)
#define		FSR			(*(unsigned char volatile *)0x04)
#define		PORTA		(*(unsigned char volatile *)0x05)
#define		PORTB		(*(unsigned char volatile *)0x06)
#define		PCON		(*(unsigned char volatile *)0x08)
#define		WUCON		(*(unsigned char volatile *)0x09)
#define		PCHBUF		(*(unsigned char volatile *)0x0A)
#define		PDCON		(*(unsigned char volatile *)0x0B)
#define		ODCON		(*(unsigned char volatile *)0x0C)
#define		PHCON		(*(unsigned char volatile *)0x0D)
#define		INTEN		(*(unsigned char volatile *)0x0E)
#define		INTFLAG		(*(unsigned char volatile *)0x0F)

//for w1631
#define		T1M			(*(unsigned char volatile *)0x07)	//bank1
#define		T1C			(*(unsigned char volatile *)0x08)	//bank1
#define		T1R			(*(unsigned char volatile *)0x09)	//bank1
#define		PWMCON		(*(unsigned char volatile *)0x0A)	//bank1
#define		PWM0R		(*(unsigned char volatile *)0x0B)	//bank1
#define		PWM1R		(*(unsigned char volatile *)0x0C)	//bank1
#define		PWM2R		(*(unsigned char volatile *)0x0D)	//bank1
#define		SYSM		(*(unsigned char volatile *)0x0E)	//bank1

//for W801
#define		E2PCON		(*(unsigned char volatile *)0x07)	//bank1
#define		E2PADR		(*(unsigned char volatile *)0x08)	//bank1
#define		E2PDIN		(*(unsigned char volatile *)0x09)	//bank1
#define		E2PDAT		(*(unsigned char volatile *)0x0A)	//bank1
#endif

#define		FSR			(*(unsigned char volatile *)0x04)


volatile unsigned char	INDF		@0x00;
volatile unsigned char	TMR0		@0x01;
volatile unsigned char	PCL			@0x02;
volatile unsigned char	STATUS		@0x03;
//volatile unsigned char	FSR			@0x04;
volatile unsigned char	PORTA		@0x05;
volatile unsigned char	PORTB		@0x06;
volatile unsigned char	PCON		@0x08;
volatile unsigned char	WUCON		@0x09;
volatile unsigned char	PCHBUF		@0x0A;
volatile unsigned char	PDCON		@0x0B;
volatile unsigned char	ODCON		@0x0C;
volatile unsigned char	PHCON		@0x0D;
volatile unsigned char	INTEN		@0x0E;
volatile unsigned char	INTFLAG		@0x0F;

//for w1631
volatile unsigned char	T1M			@0x07;	//bank1
volatile unsigned char	T1C			@0x08;	//bank1
volatile unsigned char	T1R			@0x09;	//bank1
volatile unsigned char	PWMCON		@0x0A;	//bank1
volatile unsigned char	PWM0R		@0x0B;	//bank1
volatile unsigned char	PWM1R		@0x0C;	//bank1
volatile unsigned char	PWM2R		@0x0D;	//bank1
volatile unsigned char	SYSM		@0x0E;	//bank1

//for W801
volatile unsigned char	E2PCON		@0x07;	//bank1
volatile unsigned char	E2PADR		@0x08;	//bank1
volatile unsigned char	E2PDIN		@0x09;	//bank1
volatile unsigned char	E2PDAT		@0x0A;	//bank1

//-------------------------------
#define	sfrb	unsigned char volatile
//-------------------------------
typedef	struct	{
		sfrb C		:1;
		sfrb DC		:1;
		sfrb Z		:1;
		sfrb PD		:1;
		sfrb TO		:1;
		sfrb LVDF	:1;
		sfrb GP1	:1;
		sfrb RST	:1;
		}ts_STATUS;

typedef	struct	{
		sfrb IOA0	:1;
		sfrb IOA1	:1;
		sfrb IOA2	:1;
		sfrb IOA3	:1;
		sfrb IOA4	:1;
		sfrb IOA5	:1;
		sfrb		:2;
		}ts_PORTA;

typedef	struct	{
		sfrb IOB0	: 1;
		sfrb IOB1	: 1;
		sfrb IOB2	: 1;
		sfrb IOB3	: 1;
		sfrb IOB4	: 1;
		sfrb IOB5	: 1;
		sfrb IOB6	: 1;
		sfrb IOB7	: 1;
		}ts_PORTB;

typedef	struct	{
		sfrb HCMPIN0	: 1;
		sfrb HCMPIN1	: 1;
		sfrb			: 2;
		sfrb HCMPEN		: 1;
		sfrb LVDTE		: 1;
		sfrb EIS		: 1;
		sfrb WDTE		: 1;
		}ts_PCON;

typedef	struct	{
		sfrb WUB0	: 1;
		sfrb WUB1	: 1;
		sfrb WUB2	: 1;
		sfrb WUB3	: 1;
		sfrb WUB4	: 1;
		sfrb WUB5	: 1;
		sfrb WUB6	: 1;
		sfrb WUB7	: 1;
		}ts_WUCON;

typedef	struct	{
		sfrb PDA0	: 1;
		sfrb PDA1	: 1;
		sfrb PDA2	: 1;
		sfrb PDA3	: 1;
		sfrb PDB0	: 1;
		sfrb PDB1	: 1;
		sfrb PDB2	: 1;
		sfrb PDB3	: 1;
		}ts_PDCON;

typedef	struct	{
		sfrb ODB0	: 1;
		sfrb ODB1	: 1;
		sfrb ODB2	: 1;
		sfrb ODB3	: 1;
		sfrb ODB4	: 1;
		sfrb ODB5	: 1;
		sfrb ODB6	: 1;
		sfrb ODB7	: 1;
		}ts_ODCON;

typedef	struct	{
		sfrb PHB0	: 1;
		sfrb PHB1	: 1;
		sfrb PHB2	: 1;
		sfrb PHB3	: 1;
		sfrb PHB4	: 1;
		sfrb PHB5	: 1;
		sfrb PHB6	: 1;
		sfrb PHB7	: 1;
		}ts_PHCON;

typedef	struct	{
		sfrb T0IE		: 1;
		sfrb PBIE		: 1;
		sfrb INTIE		: 1;
		sfrb T1IE		: 1;
		sfrb			: 3;
		sfrb GIE		: 1;
		}ts_INTEN;

typedef	struct	{
		sfrb T0IF		: 1;
		sfrb PBIF		: 1;
		sfrb INTIF		: 1;
		sfrb T1IF		: 1;
		sfrb			: 4;
		}ts_INTFLAG;

typedef	struct	{
		sfrb 			: 6;
		sfrb RP0		: 1;
		sfrb RP1		: 1;
		}ts_FSR;

//-------------------------------
volatile ts_STATUS	STATUS_		@ 0x03;
volatile ts_FSR		FSR_		@ 0x04;
volatile ts_PORTA	PORTA_ 		@ 0x05;
volatile ts_PORTB	PORTB_ 		@ 0x06;
volatile ts_PCON	PCON_ 		@ 0x08;
volatile ts_WUCON	WUCON_ 		@ 0x09;
volatile ts_PDCON	PDCON_ 		@ 0x0B;
volatile ts_ODCON	ODCON_ 		@ 0x0C;
volatile ts_PHCON	PHCON_ 		@ 0x0D;
volatile ts_INTEN	INTEN_ 		@ 0x0E;
volatile ts_INTFLAG	INTFLAG_ 	@ 0x0F;
//==============================================================
typedef	struct	{
		sfrb PWM0E	: 1;
		sfrb BUZE	: 1;
		sfrb ALOAD	: 1;
		sfrb T1CKS	: 1;
		sfrb T1PS0	: 1;
		sfrb T1PS1	: 1;
		sfrb T1PS2	: 1;
		sfrb T1EN	: 1;
		}ts_T1M;

typedef	struct	{
		sfrb T1C0	: 1;
		sfrb T1C1	: 1;
		sfrb T1C2	: 1;
		sfrb T1C3	: 1;
		sfrb T1C4	: 1;
		sfrb T1C5	: 1;
		sfrb T1C6	: 1;
		sfrb T1C7	: 1;
		}ts_T1C;

typedef	struct	{
		sfrb T1R0	: 1;
		sfrb T1R1	: 1;
		sfrb T1R2	: 1;
		sfrb T1R3	: 1;
		sfrb T1R4	: 1;
		sfrb T1R5	: 1;
		sfrb T1R6	: 1;
		sfrb T1R7	: 1;
		}ts_T1R;


typedef	struct	{
		sfrb PWM2E	: 1;
		sfrb PWM1E	: 1;
		sfrb PWMINV	: 1;
		sfrb PWMMD	: 1;
		sfrb 		: 1;
		sfrb PWM2OE	: 1;
		sfrb PWM1OE	: 1;
		sfrb PWM0OE	: 1;
		}ts_PWMCON;

typedef	struct	{
		sfrb TC1C0		: 1;
		sfrb TC1C1		: 1;
		sfrb TC1C2		: 1;
		sfrb TC1C3		: 1;
		sfrb TC1C4		: 1;
		sfrb TC1C5		: 1;
		sfrb TC1C6		: 1;
		sfrb TC1C7		: 1;
		}ts_PWM0R;


typedef	struct	{
		sfrb TC1R0		: 1;
		sfrb TC1R1		: 1;
		sfrb TC1R2		: 1;
		sfrb TC1R3		: 1;
		sfrb TC1R4		: 1;
		sfrb TC1R5		: 1;
		sfrb TC1R6		: 1;
		sfrb TC1R7		: 1;
		}ts_PWM1R;


typedef	struct	{
		sfrb TC2R0		: 1;
		sfrb TC2R1		: 1;
		sfrb TC2R2		: 1;
		sfrb TC2R3		: 1;
		sfrb TC2R4		: 1;
		sfrb TC2R5		: 1;
		sfrb TC2R6		: 1;
		sfrb TC2R7		: 1;
		}ts_PWM2R;

typedef	struct	{
		sfrb STOPHX	: 1;
		sfrb CLKMD	: 1;
		sfrb RTCCON	: 1;
		sfrb RTCWP	: 1;
		sfrb 		: 4;
		}ts_SYSM;


volatile ts_T1M		T1M_		@ 0x07;
volatile ts_T1C		T1C_		@ 0x08;
volatile ts_T1R		T1R_		@ 0x09;
volatile ts_PWMCON	PWMCON_		@ 0x0A;
volatile ts_PWM0R	PWM0R_		@ 0x0B;
volatile ts_PWM1R	PWM1R_		@ 0x0C;
volatile ts_PWM2R	PWM2R_		@ 0x0D;
volatile ts_SYSM	SYSM_		@ 0x0E;
//==============================================================
typedef	struct	{
		sfrb WR		: 1;
		sfrb BER	: 1;
		sfrb SER	: 1;
		sfrb CER	: 1;
		sfrb RD		: 1;
		sfrb 		: 3;
		}ts_E2PCON;
volatile ts_E2PCON	E2PCON_		@ 0x07;
//==============================================================
typedef	unsigned char		u8;
typedef	signed char			s8;
typedef	unsigned short		u16;
typedef	signed short		s16;

#endif
