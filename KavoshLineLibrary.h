////////////////////////////////IN THE NAME OF GOD/////////////////////////////////////////////
#include <mega128.h>
#include <delay.h>
#include <i2c.h>
#include <alcd.h>
#include <stdio.h>
#include <stdlib.h>
#define ADC_VREF_TYPE 0x40
//#define ADC_VREF_TYPE ((0<<REFS1) | (1<<REFS0) | (0<<ADLAR))


//#define muxA             PORTG.0
//#define muxB             PORTG.1
//#define muxC             PORTG.2
#define SBR              PINA.3
#define SBL              PINA.4
#define TXD_enable       PORTA.6

#define enter            PINB.4
#define increase         PINB.5
#define decrease         PINB.6
#define exit             PINB.7
#define previuse_page    PIND.0
#define next_page        PIND.1

#define victim           PINA.5
#define conductive       sensor(1,0)          
#define co_volt          sensor_voltage(1,0)          
#define check_obs        PINF.0
#define check_kit        PINC.5

#define SFR              PINC.7
#define SFL              PINC.6


#define ENC_L            PIND.6
#define ENC_R            PIND.7
#define MUXOUT_R         PINF.1
#define MUXOUT_L         PINF.2


#define SM   sensor(0,0)
#define SL1  sensor(0,1)
#define SL2  sensor(0,2)
#define SL3  sensor(0,3)
#define SL4  sensor(0,4)
#define SL5  sensor(0,5)
#define SL6  sensor(0,6)
#define SL7  sensor(0,7)


#define SR1  sensor(1,1)
#define SR2  sensor(1,2)
#define SR3  sensor(1,3)
#define SR4  sensor(1,4)
#define SR5  sensor(1,5)
#define SR6  sensor(1,6)
#define SR7  sensor(1,7)


#define VSM   sensor_voltage(0,0)
#define VSL1  sensor_voltage(0,1)
#define VSL2  sensor_voltage(0,2)
#define VSL3  sensor_voltage(0,3)
#define VSL4  sensor_voltage(0,4)
#define VSL5  sensor_voltage(0,5)
#define VSL6  sensor_voltage(0,6)
#define VSL7  sensor_voltage(0,7)



#define VSR1  sensor_voltage(1,1)
#define VSR2  sensor_voltage(1,2)
#define VSR3  sensor_voltage(1,3)
#define VSR4  sensor_voltage(1,4)
#define VSR5  sensor_voltage(1,5)
#define VSR6  sensor_voltage(1,6)
#define VSR7  sensor_voltage(1,7)

#define senscount_all  SL7+SL6+SL5+SL4+SL3+SL2+SL1+SM+SR1+SR2+SR3+SR4+SR5+SR6+SR7
#define senscount SM+SL1+SR1+SL2+SR2+SL3+SR3+SL4+SR4
#define senscount_l SM+SL1+SL2+SL3+SL4 
#define senscount_r SM+SR1+SR2+SR3+SR4

#define TCNT3     (TCNT3H*256+TCNT3L)
#define UF ULTRA(1)
#define UL ULTRA(2)
#define UR ULTRA(3)
#define VLF   vl()

#define deg     cmps(1)    ////               
#define pitch   cmps(2)
#define role    cmps(3)
                
#define xx       cmps_gyro(1)
#define yy       cmps_gyro(2)
#define zz       cmps_gyro(3)
#define gayro    cmps_gyro(3)

#define front    1
#define back     2          
#define sides    3
#define right    4
#define left     5

#define F    100
#define B    200          
#define R    300
#define L    400

#define LF 3    // wheel motor left Front
#define LB 2    // wheel motor left Back
#define RB 1    // wheel motor Right Back
#define RF 4    // wheel motor Right Front

#define AL 21    // ARM LEFT
#define AR 22    // ARM RIGHT

#define resana 1
#define naresana 0 //cundac

#define normal  3456
#define search  3455 
#define drop    3454 
#define get     3453 

//#define silver_voltage 0.3

#define green 101
#define black 201
#define red   204

#define P_TORQUE_ENABLE1    64
#define P_GOAL_SPEED_L1     104

#define INST_WRITE         0x03
#define INST_REG_WRITE     0x04
#define P_TORQUE_ENABLE    24
#define P_GOAL_POSITION_L  30
#define P_GOAL_SPEED_L     32
#define bit_is_set(REG8,BITNUM) ((REG8&(1<<BITNUM))!=0)
#define CHECK_TXD_FINISH        bit_is_set(UCSR1A,6)  
#define TXD_READY               bit_is_set(UCSR1A,5)
#define DATA_REGISTER_EMPTY (1<<UDRE0)
#define RX_COMPLETE (1<<RXC0)
#define FRAMING_ERROR (1<<FE0)
#define PARITY_ERROR (1<<UPE0)
#define DATA_OVERRUN (1<<DOR0)
#define sbi(REG8,BITNUM) REG8|=_BV(BITNUM)
#define _BV(BITNUM)      (1<<BITNUM)


#pragma used+
char redroom_dir,text[100],Parameter_1[40],boro=0,Parameter_2[40],barband[4],its_not_obs,color_selected=left,first_touched;
char loc=0,s_ball,b_ball,correct,side_check,check_while_finished,obs_in_checkwhile;
int pich_check_while,dooble=0,tekrar,malesh_rast,malesh_chap,near_wall_right=0,near_wall_left=0,while_sakoo,loop,DN,first_wall,t_gap,deg_arm,deg_basket,deg_xl,exit_redroom=0,no_side=0,pich_dar=1,pich_sakoo=0, uuu, x,kavosh, j,degghabli_1,degghabli_2,paresh,degdif,address=0x3a,green_L=0,red_L=0,amb_L=0,amb_R=0,green_R=0,red_R=0,blue_L=0,blue_R=0,difL,difR,MotRStatus=91,MotLStatus=91,deg_fake,ball_num=0,sg,both_touched;
eeprom int halat_mane,tekrar1,difl,difr,last_pos,vol_left,vol_right, sp,found_dep,found_deg,ev_s_ball,ev_b_ball,x_s_ball,turnedtodeg,ev_deg=400,T90L,T90R,ev_ball,rad_round,dis_obs,value_l,value_r,sens_Rdif,sens_Ldif,x_ball,obstacle_dir,direction_deg=410,ev_out_deg=510;
eeprom int gap_cmp_en,gap_time_limit;
eeprom int red_rcal,blue_rcal,green_rcal,amb_rcal,red_lcal,blue_lcal,green_lcal,amb_lcal,value_r,value_l;
eeprom int farz,cnt,xpos,xpos1,xpos2,basket_1,basket_2,ax_arm_1,ax_arm_2,ax_arm_3,xl_1,xl_2,xl_3,xl_4,DS=122,DE=164,DW=132,max_right,min_left,max_left,min_right,dif_silver;
eeprom float silver_voltage;
eeprom int rescue_kit,difGBR,difGBL,difRBR,difRBL,difGRR,difGRL,disable_SM,disable_SL1,disable_SL2,disable_SL3,disable_SL4,disable_SL5,disable_SL7,disable_SR1,disable_SR2,disable_SR3,disable_SR4,disable_SR5,disable_SR7;
unsigned int dis_out=100,vl_buf[2],redroom_time;
unsigned char tcnt3h,tcnt3l;
unsigned int dist_f,dist_r,dist_l;
bit reset,chargoosh,toop_get_out,hey,str,victim_checked,fifth;
int check_get_out,X,n,s,w,e,tm;
int sum_x,first_x,err2,er,posi;
int armin[200][4];
void count(int cnt);
void rotation_motor(int pos);
int rotate(int type);
void xl_reset_alarm (char ID,char gh);
char color(signed char num);
unsigned int ULTRA(char number);
void move(char direction,int cnt);
void obstacle (char obs_direction);
void check_while(void);
void turnto(signed int position);                                          
void get_near(void);
void ev_zone(void);
void get_out(void);
void silver(void);
void vic(void); 
void gap(int enable);
void color_detect(void);
void color_detect_ramp(void);
void green_get_out(void);
void rescuekit(void);
//unsigned int read_ax_pos(char ID);
//unsigned int read_xl_pos(char ID);
//char getchar1(void);

//rotate
void come_down(void);

unsigned int read_adc(unsigned char adc_input)
    {
    ADMUX=adc_input | ADC_VREF_TYPE;
    delay_us(10);
    ADCSRA|=0x40;
    while ((ADCSRA & 0x10)==0);
    ADCSRA|=0x10;
    return ADCW;         
    }
                                     
char  sensor (char select,char num)
    {
    char s;                                  
    PORTG=num;
    delay_us(5);
    if (select==0)     // left sensors
        s=MUXOUT_L;
    else if (select==1)//right sensors
        s=MUXOUT_R;                               
    return s;
    }
float sensor_voltage (char select,char num)
    {
    float s;
    PORTG=num;
    delay_us(10);
    if (select==0)     // left sensors
        s=read_adc(2);
    else if (select==1)//right sensors
        s=read_adc(1);

    s=s*0.00488;
    return s;
    }

//*********************************DYNAMIXEL***********************************************************************
unsigned short update_crc(unsigned short crc_accum,unsigned char *data_blk_ptr,unsigned short data_blk_size)
{
unsigned short i,j;
unsigned short crc_table[256] = {
    0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
    0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
    0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
    0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
    0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
    0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
    0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
    0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
    0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
    0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
    0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
    0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
    0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
    0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
    0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
    0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
    0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
    0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
    0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
    0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
    0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
    0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
    0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
    0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
    0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
    0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
    0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
    0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
    0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
    0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
    0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
    0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202};

for(j=0; j < data_blk_size; j++)
    {
    i=((unsigned short)(crc_accum >> 8) ^ data_blk_ptr[j]) & 0xFF;
    crc_accum=(crc_accum << 8) ^ crc_table[i];
    }
return crc_accum;
}
char Communication_1(char ID, char Inst, char ParameterLength)
{
char TxPacket_1[32],Count,CheckSum,PacketLength;
TXD_enable=0;                   // set TXD
TxPacket_1[0] = 0xff;
TxPacket_1[1] = 0xff;
TxPacket_1[2] = ID;
TxPacket_1[3] = ParameterLength+2; //Length(Paramter,Instruction,Checksum)
TxPacket_1[4] = Inst;

for(Count=0; Count < ParameterLength; Count++)
    TxPacket_1[Count+5] = Parameter_1[Count];

CheckSum=0;
PacketLength = ParameterLength+4+2;

for(Count=2; Count < PacketLength-1; Count++) //except 0xff,checksum
    CheckSum += TxPacket_1[Count];

TxPacket_1[Count] = ~CheckSum; //Writing Checksum with Bit Inversion

for(Count=0; Count < PacketLength; Count++)
    {
    while(!TXD_READY);
    UDR1=TxPacket_1[Count];
    }
while(!CHECK_TXD_FINISH); //Wait until TXD Shift register empty
return PacketLength;
}
void Communication_2(char ID,char Inst,char ParameterLength)
{
char Count,TxPacket_2[32];
unsigned short CRC;

TXD_enable=0;                                  // set TXD
TxPacket_2[0] = 0XFF;                             // Header
TxPacket_2[1] = 0XFF;                             // Header
TxPacket_2[2] = 0XFD;                             // Header
TxPacket_2[3] = 0X00;                             // Reserved
TxPacket_2[4] = ID;                               // ID of dynamixel
TxPacket_2[5] = (ParameterLength+3) & 0xFF;       // Lenth low  bit
TxPacket_2[6] = (ParameterLength+3 >> 8) & 0xFF;  // Lenth high bit
TxPacket_2[7] = Inst;                             // Instruction

for(Count=0; Count < ParameterLength; Count++)
    TxPacket_2[Count+8] = Parameter_2[Count];

CRC = update_crc (0, TxPacket_2, ParameterLength+3+5);
TxPacket_2[Count+8] = CRC & 0xFF;                 // CRC_L
TxPacket_2[Count+9] = (CRC>>8) & 0xFF;            // CRC_H

for(Count=0; Count < ParameterLength+10; Count++)
    {
    while(!TXD_READY);
    UDR1=TxPacket_2[Count];
    }
while(!CHECK_TXD_FINISH); //Wait until TXD Shift register empty
delay_us(1000);//taghirdadeshod
}
void Status(char ID,char st)  // gozaresh bede ya na
    {
    Parameter_1[0] = 16;        //Address of Firmware Version(P_RETURN_LEVEL)
    Parameter_1[1] = st;        //0 means No status packet will be returned
    Communication_1(ID,INST_WRITE,2);
    //delay_ms(10);
    }
void wheel_mode(char ID)
    {
    Parameter_1[0]=6;  //Address of Firmware Version(P_CW_ANGLE_LIMIT_L)
    Parameter_1[1]=0;
    Parameter_1[2]=0;
    Parameter_1[3]=0;
    Parameter_1[4]=0;
    Communication_2(ID,INST_WRITE,5);
    //delay_ms(10);

    Parameter_1[0] = P_TORQUE_ENABLE1; //Address of Firmware Version
    Parameter_1[1] = 1;               //Writing Data P_GOAL_POSITION_L
    Communication_2(ID,INST_WRITE,2);
    //delay_ms(10);
    }
void ax(char bID,int position, int speed)        
{
Parameter_1[0] = P_GOAL_POSITION_L; //Address of Firmware Version
Parameter_1[1] = position & 255;    //Writing Data P_GOAL_POSITION_L
Parameter_1[2] = position >> 8;     //Writing Data P_GOAL_POSITION_H
Parameter_1[3] = speed & 255;       //Writing Data P_GOAL_SPEED_L
Parameter_1[4] = speed >>8;         //Writing Data P_GOAL_SPEED_H
Communication_1(bID,INST_WRITE,5); delay_ms(10);
}
void xl2 (char ID,int position,int speed)
{        
// in tabe ghabli ast
TXD_enable=0;
Parameter_2[0] = P_GOAL_POSITION_L; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = position & 255;    // POSITION_L
Parameter_2[3] = position >> 8;     // POSITION_H
Parameter_2[4] = speed & 255;       // SPEED_L
Parameter_2[5] = speed >>8;         // SPEED_H
Communication_2(ID,INST_WRITE,6); //delay_ms(10);
}
void xl_reset_alarm (char ID,char gh)
{
TXD_enable=0;
Parameter_2[0] = 18; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = gh;    
Communication_2(ID,INST_WRITE,3); delay_ms(5);
}
void xl(char ID,int position,int speed)
{
// dar in tabe har bar error ra reset mikone

xl_reset_alarm(AL,0);

TXD_enable=0;
Parameter_2[0] = 30; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = position & 255;    // POSITION_L
Parameter_2[3] = position >> 8;     // POSITION_H
Parameter_2[4] = speed & 255;       // SPEED_L
Parameter_2[5] = speed >>8;         // SPEED_H
Parameter_2[6] = 0;                 // empty
Parameter_2[7] = 0xff;              // torque L
Parameter_2[8] = 0x03;              // torque H
Communication_2(ID,INST_WRITE,9); //delay_ms(10);

xl_reset_alarm(AL,0);

}
void xl_max_torque (char ID)
{
TXD_enable=0;
Parameter_2[0] = 15; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = 0xff;    
Parameter_2[3] = 0x03;    
Communication_2(ID,INST_WRITE,4); delay_ms(10);
}
void xl_430_speed (char ID,signed int speed)
{
TXD_enable=0;
Parameter_2[0] = 104; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = speed & 255;    // speed_L
Parameter_2[3] = speed >> 8;     // sspeed_H
Parameter_2[4] = 0;       // 0
Parameter_2[5] = 0;         // 0
Communication_2(ID,INST_WRITE,6); delay_ms(2);
}
void xl_430_torque(char ID, char torque_enable)
{
Parameter_2[0] = 64; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = torque_enable;    //
Communication_2(ID,INST_WRITE,3); delay_ms(2);
}
void xl_430_dir(char ID, char dir)
{
Parameter_2[0] = 10; // Address of Firmware Version
Parameter_2[1] = 0;                 // Address of Firmware Version
Parameter_2[2] = dir;
Communication_2(ID,INST_WRITE,3); delay_ms(2);
}
char getchar1(void)
{
	char status,data;
	while (1)
    {   
        lcd_clear();
		while (((status=UCSR1A) & RX_COMPLETE)==0);
		{
        data=UDR1;
        sprintf(text," %d",data);
        lcd_puts(text);
        }
		if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN)) == 0)
		{
			return data;
		}
    }
}
eeprom int delayyy;                              

unsigned int read_ax_pos(char ID)
    {
	char p[40];
	char A[40];
    int i;
	unsigned char CheckSum, Count;
	unsigned int position;

	TXD_enable = 0;  // TXD
	p[0] = 0xFF;
	p[1] = 0xFF;
	p[2] = ID;  //id
	p[3] = 4; // length
	p[4] = 2; // instruction
	p[5] = 0x24;  // address of Position
	p[6] = 2;     // number of bytes

	CheckSum = 0;
	for (Count = 2; Count < 7; Count++) //except 0xff,checksum
		CheckSum += p[Count];
	p[7] = ~CheckSum; //Writing Checksum with Bit Inversion

	for (Count = 0; Count < 8; Count++)
	{
		while (!TXD_READY);
		UDR1 = p[Count];
	}
	while (!CHECK_TXD_FINISH); //Wait until TXD Shift register empty

    delayyy+=5;
	delay_ms(delayyy); //300 ta 400 us

    lcd_gotoxy(0,3);
    sprintf(text, "delay=%3d  ", delayyy);
    lcd_puts(text);
    
	TXD_enable = 1; // RXD
    lcd_gotoxy(0,0);

	for (Count = 0; Count<8; Count++)
		{
        A[Count] = getchar1();
        sprintf(text, "%3d  ", A[Count]);
        lcd_puts(text);
        }

	position = A[6] * 255 + A[5];
	return position;
    }
unsigned int read_xl_pos(char ID)
{
	unsigned char Packet[20];
	unsigned short CRC;
	unsigned char Count;
	TXD_enable = 0;   // TXD

	Packet[0] = 0XFF;
	Packet[1] = 0XFF;
	Packet[2] = 0XFD;
	Packet[3] = 00;         // Reserved
	Packet[4] = ID;         // ID of dynamixel
	Packet[5] = 7;          // (ParameterLength+3) & 0xFF;        Lenth low  bit
	Packet[6] = 0;          // (ParameterLength+3 >> 8) & 0xFF;   Lenth high bit
	Packet[7] = 2;          // Instruction
	Packet[8] = 37;         // adress low  bit
	Packet[9] = 0;          // adress high bit
	Packet[10] = 2;          // Lenth low  bit
	Packet[11] = 0;          // Lenth high bit
	CRC = update_crc(0, Packet, 12);
	Packet[12] = CRC & 0x00FF;              // CRC_L
	Packet[13] = (CRC >> 8) & 0x00FF;         // CRC_H

	for (Count = 0; Count < 14; Count++)
	{
		while (!TXD_READY);
		UDR1 = Packet[Count];
	}
	while (!CHECK_TXD_FINISH);
	delay_us(1000);  // this delay may vary. must be changed if not recieve correctly

	TXD_enable = 1; // RXD

	for (Count = 0; Count<13; Count++)
		Packet[Count] = getchar1();

	sprintf(text, "%3d %3d %3d %3d %3d ", Packet[0], Packet[1], Packet[2], Packet[3], Packet[4], Packet[5]);
	lcd_gotoxy(0, 0);
	lcd_puts(text);
	sprintf(text, "%3d %3d %3d %3d %3d ", Packet[6], Packet[7], Packet[8], Packet[9], Packet[10], Packet[11]);
	lcd_gotoxy(0, 1);
	lcd_puts(text);
	sprintf(text, "%3d %3d %3d %3d %3d ", Packet[12], Packet[13], Packet[14], Packet[15], Packet[16], Packet[17]);
	lcd_gotoxy(0, 2);
	lcd_puts(text);

	if (Packet[2] == 253)   // yani khata nadashtim
		return  Packet[10] * 255 + Packet[9];
	else if (Packet[3] == 253)   // yani ye adad eshtebahi daryaft kardim
		return  Packet[11] * 255 + Packet[10];
	else if (Packet[4] == 253)   // yani 2 ta adad eshtebahi daryaft kardm
		return  Packet[12] * 255 + Packet[11];

	/*
	dar vaghe bayad packet[9] & packet[10] read beshe,
	vali chon bazi vaghta avalesh 2 ta 255 alaki mide injoori kardim
	*/
}
void go (signed int spl,signed int spr)
    { 
    if(spl<-255)
        spl=-255;
    else if(spl>255)
        spl=255;
    if(spr<-255)
        spr=-255;
    else if(spr>255)
        spr=255;
    if(MotLStatus!=spl)
        {
        if(spl>=0)                    
            {

            TXD_enable=0;
            Parameter_2[0] = 104; // Address of Firmware Version
            Parameter_2[1] = 0;                 // Address of Firmware Version
            Parameter_2[2] = spl & 255;    // speed_L
            Parameter_2[3] = spl >> 8;     // sspeed_H
            Parameter_2[4] = 0;       // 0
            Parameter_2[5] = 0;         // 0
            Communication_2(LB,INST_WRITE,6); //delay_us(200);
            Communication_2(LB,INST_WRITE,6);
            Communication_2(LF,INST_WRITE,6); //delay_us(200); 
           Communication_2(LF,INST_WRITE,6);
//            Communication_2(LB,INST_WRITE,6); //delay_us(200);
//            Communication_2(LB,INST_WRITE,6);
//            Communication_2(LF,INST_WRITE,6); //delay_us(200); 
//            Communication_2(LF,INST_WRITE,6);
            }
        else
            { 
            TXD_enable=0;
            Parameter_2[0] = 104; // Address of Firmware Version
            Parameter_2[1] = 0;                 // Address of Firmware Version
            Parameter_2[2] = 255+spl;    // 
            Parameter_2[3] = 255;     // sspeed_H
            Parameter_2[4] = 255;       // 0
            Parameter_2[5] = 255;         // 0
            Communication_2(LF,INST_WRITE,6); //delay_us(200);
            Communication_2(LF,INST_WRITE,6);
            Communication_2(LB,INST_WRITE,6); //delay_us(200); 
            Communication_2(LB,INST_WRITE,6); 
//            Communication_2(LB,INST_WRITE,6); //delay_us(200);
//            Communication_2(LB,INST_WRITE,6);
//            Communication_2(LF,INST_WRITE,6); //delay_us(200); 
//            Communication_2(LF,INST_WRITE,6);    
            }
        MotLStatus=spl;
        }
    if(MotRStatus!=spr)
        {

        if(spr>=0)
            {
            TXD_enable=0;
            Parameter_2[0] = 104; // Address of Firmware Version
            Parameter_2[1] = 0;                 // Address of Firmware Version
            Parameter_2[2] = spr & 255;    // speed_L
            Parameter_2[3] = spr >> 8;     // sspeed_H
            Parameter_2[4] = 0;       // 0
            Parameter_2[5] = 0;         // 0
            Communication_2(RB,INST_WRITE,6); //delay_us(200);
            Communication_2(RB,INST_WRITE,6);
            Communication_2(RF,INST_WRITE,6); //delay_us(200); 
           Communication_2(RF,INST_WRITE,6);
//            Communication_2(RB,INST_WRITE,6); //delay_us(200);
//            Communication_2(RB,INST_WRITE,6);
//            Communication_2(RF,INST_WRITE,6); //delay_us(200); 
//            Communication_2(RF,INST_WRITE,6);
            }

        else
            {
            TXD_enable=0;
            Parameter_2[0] = 104; // Address of Firmware Version
            Parameter_2[1] = 0;                 // Address of Firmware Version
            Parameter_2[2] = 255+spr;    // 
            Parameter_2[3] = 255;     // sspeed_H
            Parameter_2[4] = 255;       // 0
            Parameter_2[5] = 255;         // 0
            Communication_2(RB,INST_WRITE,6); //delay_us(200);
           Communication_2(RB,INST_WRITE,6);
            Communication_2(RF,INST_WRITE,6); //delay_us(200); 
            Communication_2(RF,INST_WRITE,6); 
//            Communication_2(RB,INST_WRITE,6); //delay_us(200);
//            Communication_2(RB,INST_WRITE,6);
//            Communication_2(RF,INST_WRITE,6); //delay_us(200); 
//            Communication_2(RF,INST_WRITE,6);    
            }
        MotRStatus=spr;
        }
    #asm("sei")  
    }
//************************************I2C***************************************************************************
char color(signed char num)
    {
    int color_out_L,color_out_R;
    int difL,difR;
    difR= abs(blue_R - red_R);
    difL= abs(blue_L - red_L);

    if(num==right)
        {
        DDRG=0b11111;
        PORTG=0b00000;
         
        i2c_start();  
        i2c_write(114);   // APDS9960 8bit ID
        i2c_write(0x80);  // power On
        i2c_write(3);
        i2c_stop();
        
        i2c_start();
        i2c_write(114);
        i2c_write(0x8F);  //control register
        i2c_write(1);
        i2c_stop();
        
        i2c_start();
        i2c_write(114);
        i2c_write(0x94);  // ambient light address
        i2c_stop();
        delay_us(20);
        i2c_start();
        i2c_write(115);

        amb_R=i2c_read(7);
        amb_R+=(i2c_read(6)<<8);
        red_R=i2c_read(5);
        red_R+=(i2c_read(4)<<8);
        green_R=i2c_read(3);
        green_R+=(i2c_read(2)<<8);
        blue_R=i2c_read(1);
        blue_R+=(i2c_read(0)<<8);
        i2c_stop();

        if (difR>=value_r && green_R>=blue_R )                     color_out_R=green;      
        else if (red_R<40 && green_R<100)                          color_out_R=black;
        else if (red_R<65 && red_R>20  && green_R<42 && difR<35)            color_out_R=red;
        else                                                       color_out_R=0;
        return (char)color_out_R;
        }
    else if(num==left)
        { 
        DDRG=0b11111;                                                                                    
        PORTG=0b00001;        

        i2c_start();
        i2c_write(114);   // APDS9960 8bit ID
        i2c_write(0x80);  // power On
        i2c_write(3);
        i2c_stop();
        
        i2c_start();
        i2c_write(114);
        i2c_write(0x8F);  //control register
        i2c_write(1);
        i2c_stop();
    
        i2c_start();
        i2c_write(114);
        i2c_write(0x94);  // ambient light address
        i2c_stop();
        delay_us(20);
        i2c_start();
        i2c_write(115);
        amb_L=i2c_read(7);
        amb_L+=(i2c_read(6)<<8);
        red_L=i2c_read(5);
        red_L+=(i2c_read(4)<<8);
        green_L=i2c_read(3);
        green_L+=(i2c_read(2)<<8);
        blue_L=i2c_read(1);
        blue_L+=(i2c_read(0)<<8);
        i2c_stop();

        if (difL>value_l  && green_L>=blue_L-5)                    color_out_L=green;
        else if (red_L<40 && green_L<100)                         color_out_L=black;
        else if (red_L<80 && red_L>40  && green_L<100 && difL<15)            color_out_L=red;
        else                                                       color_out_L=0;

        return (char)color_out_L;
        }

    }

unsigned int vl22 (void)
 {  
  int vl_dis=0,arh,arl; 
  unsigned char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17;
    DDRG=0b11111;                                                                                    
    PORTG=0b00010;  
     
    i2c_start();      // VL53L1X_StartRanging
    i2c_write(0x52);
    i2c_write(0);
    i2c_write(0x89);
    i2c_write(0x40);
    i2c_stop();  
    delay_ms(50);
          

    i2c_start();      // VL53L1X_GetDistance
    i2c_write(0x52);
    i2c_write(0);
    i2c_write(0x89);
    i2c_stop();
     
    i2c_start();      // VL53L1X_read Distance
    i2c_write(0x53);
    vl_dis=i2c_read(1);
    i2c_stop(); 
 
     
//    i2c_start();      // VL53L1X_StopRanging
//    i2c_write(0x52);
//    i2c_write(0);
//    i2c_write(0x87);
//    i2c_write(0x0);
//    i2c_stop();
 

 
 return vl_dis;

 
 
 }

unsigned int vl(void)
{
unsigned int vl_dis=1;

    DDRG=0b11111;                                                                                    
    PORTG=0b00010;   
    i2c_start();
    i2c_write(0x52);
    i2c_write(0);
    i2c_write(1);
    i2c_stop();

    i2c_start();
    i2c_write(0x52);
    i2c_write(30);
    i2c_stop();

    i2c_start();
    i2c_write(0x53);
    vl_buf[0]=i2c_read(1);
    vl_buf[1]=i2c_read(0);
    i2c_stop();
    
    vl_dis=vl_buf[0]*255+vl_buf[1];
    if(vl_dis>500||vl_dis<=20)vl_dis=500;
    delay_ms(10);
    if(vl_dis>=100 && vl_dis<=400 )
        {
        PORTG=2;
        delay_us(5);
        i2c_start();
        i2c_write(0x52);
        i2c_write(0);
        i2c_write(1);
        i2c_stop();

        i2c_start();
        i2c_write(0x52);
        i2c_write(30);
        i2c_stop();

        delay_us(250);

        i2c_start();
        i2c_write(0x53);
        vl_buf[0]=i2c_read(1);
        vl_buf[1]=i2c_read(0);

        i2c_stop();
        vl_dis=vl_buf[0]*255+vl_buf[1];
        if(vl_dis>500||vl_dis<=20)vl_dis=500;
            delay_ms(10);
            if(vl_dis>=100 && vl_dis<=400 )
            {
            PORTG=2;
            delay_us(5);
            i2c_start();
            i2c_write(0x52);
            i2c_write(0);
            i2c_write(1);
            i2c_stop();

            i2c_start();
            i2c_write(0x52);
            i2c_write(30);
            i2c_stop();

            delay_us(250);

            i2c_start();
            i2c_write(0x53);
            vl_buf[0]=i2c_read(1);
            vl_buf[1]=i2c_read(0);

            i2c_stop();
            vl_dis=vl_buf[0]*255+vl_buf[1];
            if(vl_dis>500||vl_dis<=20)vl_dis=500;
            }
        }
    
return vl_dis;
}                                               

signed int  cmps(char select)
    {
    signed int pi,rol,degree,ekh;
    i2c_start();
    i2c_write(0xC0);
    i2c_write(0x02);
    i2c_stop();

    i2c_start();
    i2c_write(0xC1);

    degree=i2c_read(1);
    degree=degree<<8;
    degree+=i2c_read(1);
    degree=degree/10;
    degree-=DN;

    pi=i2c_read(1);
    pi=pi*180/255;
    rol=i2c_read(0);
    rol=rol*180/255;
    i2c_stop();              
    
    if(degree < 0)  degree+=360;
    if(degree >=360) degree-=360;
    if (select==1)          return degree;
    else if (select==2)     return pi;
    else                    return rol;
           
    }
signed int cmps_gyro(char select)
    { 
    signed int x,y,z,gayro_sum;
    i2c_start();
    i2c_write(0xC0);
    i2c_write(0x12);
    i2c_stop();

    i2c_start();
    i2c_write(0xC1);

    x=i2c_read(1);
    x=x<<8;
    x+=i2c_read(1);

    y=i2c_read(1);
    y=y<<8;
    y+=i2c_read(1);

    z=i2c_read(1);
    z=z<<8;
    z+=i2c_read(0);
    i2c_stop();
    
//    gayro_sum=x+y+z/1000;
            
    
    if (select==1)          return x;
    else if (select==2)     return y;
    else if (select==3)     return z;           
    else if (select==4)     return gayro_sum;  
    }

unsigned int connect(unsigned char high,unsigned char low)
{
 unsigned int c;
     
 c=high;
 c=c<<8;
 c= (c+low);
     
 return c; 
}

unsigned int ULTRA(char number)
    {
    // ultera 1  A.7
    // ultera 2  C.4
    // ultera 3  C.3
    char x_u;
    if(number==1)      // UF
        {
        DDRA.7=1;
        PORTA.7=1; 
        delay_us(20);
        PORTA.7=0;

        DDRA.7=0;

        TCNT3H=0;
        TCNT3L=0;

        
        while(PINA.7==0)
          {
           tcnt3l=TCNT3L;
           tcnt3h=TCNT3H;

           if( connect(tcnt3h,tcnt3l) > 40000)
             {
              break;
             }
          }

        TCNT3H=0;
        TCNT3L=0;

        while(PINA.7==1)
          {
           tcnt3l=TCNT3L;
           tcnt3h=TCNT3H;

           if( connect(tcnt3h,tcnt3l) > 40000)
             {
              break;
             }
          }

        tcnt3l=TCNT3L;
        tcnt3h=TCNT3H;

        dist_f =( (connect(tcnt3h,tcnt3l) / 8.2-10)/10);

        delay_ms(15); 
         return dist_f;
        }
        
        
        
    else if(number==2) // UL
        {
        DDRC.4=1;
        PORTC.4=1; 
        delay_us(20);
        PORTC.4=0;

        DDRC.4=0;

        TCNT3H=0;
        TCNT3L=0;

        
        while(PINC.4==0)
          {
           tcnt3l=TCNT3L;
           tcnt3h=TCNT3H;

           if( connect(tcnt3h,tcnt3l) > 40000)
             {
              break;
             }
          }

        TCNT3H=0;
        TCNT3L=0;

        while(PINC.4==1)
          {
           tcnt3l=TCNT3L;
           tcnt3h=TCNT3H;

           if( connect(tcnt3h,tcnt3l) > 40000)
             {
              break;
             }
          }

        tcnt3l=TCNT3L;
        tcnt3h=TCNT3H;

        dist_l =( (connect(tcnt3h,tcnt3l) / 8.2-10)/10);

        delay_ms(25); 
         return dist_l;
        }
    else if(number==3) // UR
        {
        DDRC.3=1;
        PORTC.3=1; 
        delay_us(20);
        PORTC.3=0;

        DDRC.3=0;

        TCNT3H=0;
        TCNT3L=0;

        
        while(PINC.3==0)
          {
           tcnt3l=TCNT3L;
           tcnt3h=TCNT3H;

           if( connect(tcnt3h,tcnt3l) > 40000)
             {
              break;
             }
          }

        TCNT3H=0;
        TCNT3L=0;

        while(PINC.3==1)
          {
           tcnt3l=TCNT3L;
           tcnt3h=TCNT3H;

           if( connect(tcnt3h,tcnt3l) > 40000)
             {
              break;
             }
          }

        tcnt3l=TCNT3L;
        tcnt3h=TCNT3H;

        dist_r =( (connect(tcnt3h,tcnt3l) / 8.2-10)/10);

        delay_ms(25); 
         return dist_r;
        }
  


    }
void calculate (void)
   {
        if ((deg>=0 && deg<45) || (deg>315 && deg<=360))   j=1;
        if (deg>=45 && deg<135)   j=2;
        if (deg>=135 && deg<225)  j=3;
        if (deg>=225 && deg<=315) j=4;
        
        if(j==1) posi=0;                     //saf kardane go(sp,sp);
        else if (j==2) posi=90;  
        else if (j==3) posi=180;  
        else if (j==4) posi=270; 
   }
void move_arm(int pos)
{
if(pos==normal)//normal
{
ax(13,ax_arm_1,500);delay_ms(10);
xl(AL,xl_1,800);
delay_ms(5);
xl(AR,1023-xl_1,800);
}
else if(pos==search)//seacrh for victim
{
ax(13,ax_arm_2,500);
xl(AL,xl_2,800);
delay_ms(5);
xl(AR,1023-xl_2,800);
}
else if(pos==drop)//drop victim into basket
{
ax(13,ax_arm_3,500);delay_ms(500);
               
if(victim==1)victim_checked=1;
else victim_checked=0;
}
else if(pos==get)//get and check victim
{
//ax(13,ax_arm_2,500);
xl(AL,xl_4,1023);
delay_us(200);
xl(AR,1023-xl_4,1023);
}
else if(pos==5)//move for 5
    {
    ax(13,490,500);delay_ms(5);
    }
else if(pos==6)//sheding 5
    {
    xl(AL,xl_2,800);
    delay_ms(1);
    xl(AR,1023-xl_2,800);
    delay_ms(2000);
    
    }
}
void move_basket(int pos)
{
if(pos==1)//normal position of basket
{
ax(17,basket_1,200);delay_ms(230);
}
if(pos==2)//sheading victims
    {
    ax(17,basket_2,200);delay_ms(800);
      ax(9,last_pos-50,600);delay_ms(300);
      ax(9,last_pos+50,600);delay_ms(300);
    ax(9,last_pos,400);delay_ms(200);

    }
}
 
 
void turnto (signed int position)
    {
    int err,difdeg,time,spd,dest,tsp;
    time=0;
    spd=250;
    tsp=spd;
    if(position==L)          
        {
        if (j==1)            position = 270;
        else if (j==2)       position = 0;
        else if (j==3)       position = 90;
        else if (j==4)       position = 180;
        }
    if(position==R)          
        {
        if (j==1)            position = 90;
        else if (j==2)       position = 180;
        else if (j==3)       position = 270;
        else if (j==4)       position = 0;
        }
    if(position==B)          
        {
        if (j==1)            position = 180;
        else if (j==2)       position = 270;
        else if (j==3)       position = 0;
        else if (j==4)       position = 90;
       // if(redroom_dir==left)  position = 185;
       // else                   position = 175;
        }    
    if(position==F)          
        {
        if (j==1)            position = 0;
        else if (j==2)       position = 90;
        else if (j==3)       position = 180;
        else if (j==4)       position = 270;
        }    
        
    while(time <= 3000)
        {    
        err = position - deg; 
        difdeg = err;
        if(err>180)                     difdeg = abs(err-360);
        else if(err<-180)               difdeg = err+360;
        else if(err<0 && err>=-180)     difdeg = abs(err);
        time++; 
        //if(time>=1200) {go(0,0);ax(13,ax_arm_1,500);delay_ms(1000);move(back,20);}
        if(VSM<=silver_voltage || color(right)==green || color(left)==green) 
          {
         ax(13,660,500);delay_ms(200);
         move(back,15);
         move_arm(search);delay_ms(500);        
          }     
        if (difdeg >90)
            {
            if (err > 0 && err <= 180)      go(tsp, -tsp);
            if (err > 0 && err > 180)       go(-tsp, tsp);
            if (err < 0 && err <= -180)     go(tsp, -tsp);
            if (err < 0 && err > -180)      go(-tsp, tsp);
            }
        if (difdeg>50 && difdeg<=90)
            {           
            if (err > 0 && err <= 180)      go(tsp/1.2,-tsp/1.2);
            if (err > 0 && err > 180)       go(-tsp/1.2,tsp/1.2);
            if (err < 0 && err <= -180)     go(tsp/1.2,-tsp/1.2);
            if (err < 0 && err > -180)      go(-tsp/1.2,tsp/1.2);
            } 
        if (difdeg>25 && difdeg<=50)
            {             
            if (err > 0 && err <= 180)      go(tsp/1.6,-tsp/1.6);
            if (err > 0 && err > 180)       go(-spd/1.6,tsp/1.6);
            if (err < 0 && err <= -180)     go(tsp/1.6,-tsp/1.6);
            if (err < 0 && err > -180)      go(-tsp/1.6,tsp/1.6);
            }
        if (difdeg>10 && difdeg<=25)
            {             
            if (err > 0 && err <= 180)      go(tsp/2.5,-tsp/2.5);
            if (err > 0 && err > 180)       go(-tsp/2.5,tsp/2.5);
            if (err < 0 && err <= -180)     go(tsp/2.5,-tsp/2.5);
            if (err < 0 && err > -180)      go(-tsp/2.5,tsp/2.5);
            }
        if (difdeg>0 && difdeg<=10)                                                
            {             

            if (err > 0 && err <= 180)      go(tsp/6,-tsp/6);
            if (err > 0 && err > 180)       go(-tsp/6,tsp/6);
            if (err < 0 && err <= -180)     go(tsp/6,-tsp/6);
            if (err < 0 && err > -180)      go(-tsp/6,tsp/6);
            }
        if (difdeg>=0 && difdeg<=2)     { go(0,0);break;}
        }
    }
void turn2(char dir, int angle)
{
    int err,difdeg,time,spd,dest,tsp;
    time=0;
    spd=250;
    tsp=spd;
    if(dir==right)
    {
        angle=cmps(1)+angle;
        if(angle >= 360)
            angle -= 360;
        else if(angle < 0)
        angle += 360; 
    }            
    if(dir==left)
    {
    angle=-angle;
    angle=cmps(1)+angle;             
    if(angle >= 360)
        angle -= 360;
    else if(angle < 0)
        angle += 360;
    }
    while(time <= 1600)
    {    
    err = angle - cmps(1); 
    difdeg = err;
    if(err>180)                     difdeg = abs(err-360);
    else if(err<-180)               difdeg = err+360;
    else if(err<0 && err>=-180)     difdeg = abs(err);
    time++; 
    if(time>=1200) {go(0,0);ax(13,ax_arm_1,500);delay_ms(1000);move(back,20);}
    if (difdeg >90)
        {
        if (err > 0 && err <= 180)      go(tsp, -tsp);
        if (err > 0 && err > 180)       go(-tsp, tsp);
        if (err < 0 && err <= -180)     go(tsp, -tsp);
        if (err < 0 && err > -180)      go(-tsp, tsp);
        }
    if (difdeg>50 && difdeg<=90)
        {
        if (err > 0 && err <= 180)      go(tsp/1.2,-tsp/1.2);
        if (err > 0 && err > 180)       go(-tsp/1.2,tsp/1.2);
        if (err < 0 && err <= -180)     go(tsp/1.2,-tsp/1.2);
        if (err < 0 && err > -180)      go(-tsp/1.2,tsp/1.2);
        } 
    if (difdeg>25 && difdeg<=50)
        {
        if (err > 0 && err <= 180)      go(tsp/1.6,-tsp/1.6);
        if (err > 0 && err > 180)       go(-spd/1.6,tsp/1.6);
        if (err < 0 && err <= -180)     go(tsp/1.6,-tsp/1.6);
        if (err < 0 && err > -180)      go(-tsp/1.6,tsp/1.6);
        }
    if (difdeg>10 && difdeg<=25)
        {
        if (err > 0 && err <= 180)      go(tsp/1.8,-tsp/1.8);
        if (err > 0 && err > 180)       go(-tsp/1.8,tsp/1.8);
        if (err < 0 && err <= -180)     go(tsp/1.8,-tsp/1.8);
        if (err < 0 && err > -180)      go(-tsp/1.8,tsp/1.8);
        }
    if (difdeg>2 && difdeg<=10)                                                
        {
        if (err > 0 && err <= 180)      go(tsp/2,-tsp/2);
        if (err > 0 && err > 180)       go(-tsp/2,tsp/2);
        if (err < 0 && err <= -180)     go(tsp/2,-tsp/2);
        if (err < 0 && err > -180)      go(-tsp/2,tsp/2);
        }
    if (difdeg>=0 && difdeg<=2)     {go(0,0);break;}
    }
}
void rotation_motor(int pos)
    { 
    if(pos==0){ax(9,1002,900);last_pos=1002;}
    else if(pos==1){ax(9,703,900);last_pos=703;}
    else if(pos==2){ax(9,386,900);last_pos=386;}
    else if(pos==3){ax(9,83,900);last_pos=83;}     
    
    else if(pos==10){ax(9,852,900);last_pos=852;}
    else if(pos==11){ax(9,544,900);last_pos=544;}
    else if(pos==12){ax(9,234,900);last_pos=234;}
    else if(pos==13){ax(9,1022,900);last_pos=1022;delay_ms(4000);ax(9,1,900);delay_ms(1000000);} 
    
    
    }
void move( char direction,int cnt)
    {
    int spd=sp;
        //lcd_clear();
    if (direction==left)
        {
        lcd_puts("left");
        go(-spd,spd);
        }
    else if (direction==right)
        {
        lcd_puts("right");
        go(spd,-spd);
        }
    else if (direction==front)
        {
        //lcd_puts("front");
        go(spd,spd);
        }
    else if (direction==back)
        {
        lcd_puts("back");
        go(-spd,-spd);
        }
    count(cnt);
    go(0,0);
    }