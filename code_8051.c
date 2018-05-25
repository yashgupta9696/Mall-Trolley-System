#include<reg51.h>

sbit RS=P3^7;
sbit EN=P3^6;
sbit buzzer=P2^0;

void Rxmsg(void);
void lcdinit(void);
void lcdData(unsigned char l);
void lcdcmd(unsigned char k);
void DelayMs(unsigned int count); 
void unknown(void);
void ConvertAndDisplay_one(unsigned int value1,unsigned char c[]);
void display_one(unsigned char s,t,u);
void ConvertAndDisplay(unsigned int value1,unsigned char c[]);
void display(unsigned char s,t,u);

void welcome(void);
int tea = 100;
int sugar = 120;
int coffee = 130;
int rice = 150;
int bread = 140;

int total=0;
int total_items=0;
int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
 
void main()
{
unsigned char i=0;
unsigned int j=0;
unsigned char c[15];

TMOD=0x20;		  // Configure the serial port to 9600 baud rate
TH1=0xFD;
SCON=0X50;
TR1=1;
//R=0;
lcdinit();
welcome();
//bz=1;

	while(1)
	{
	back:

		for(i=0;i<15;i++)			  //command to recv data
		{
			c[i]=0xFF;
		}
																    
		while(RI==0);

		for(i=0;i<15;i++)			  //command to recv data
		{
			j=0;
			while(RI==0)
				{
					if(j>=1000)
					goto timeout;
					j++;
				}
			c[i]=SBUF;
			RI=0;
		}

	timeout:
		for(i=0;i<15;i++)
			{
				if(c[i]=='8' && c[i+1]=='4' && c[i+2]=='0' && c[i+3]=='0' && c[i+4]=='8' && c[i+5]=='5' && c[i+6]=='7' && c[i+7]=='1' && c[i+8]=='7' && c[i+9]=='A'&& c[i+10]=='0' && c[i+11]=='A')
					{
						if(c1==1)
						{
							total = total - tea;
							total_items = total_items - 1;
							if(total < 500)
								buzzer=1;
							c1=0;
						}
						else
						{
							total = total + tea;
							total_items = total_items + 1;
							if(total > 500)
								buzzer=0;
							c1=1;
						}
						ConvertAndDisplay(tea,"Tea Cost");
						DelayMs(2000); 
						lcdinit();
						DelayMs(100);
						//welcome();
						ConvertAndDisplay(total,"Total Cost");
						ConvertAndDisplay_one(total_items,"total_items");
						goto back;
					}

				if(c[i]=='8' && c[i+1]=='4' && c[i+2]=='0' && c[i+3]=='0' && c[i+4]=='8' && c[i+5]=='5' && c[i+6]=='A' && c[i+7]=='5' && c[i+8]=='2' && c[i+9]=='D'&& c[i+10]=='8' && c[i+11]=='9')
					{
						if(c2==1)
						{
							total = total - sugar;
							total_items = total_items - 1;
							if(total < 500)
								buzzer=1;
							c2=0;
						}
						else
						{
							total = total + sugar;
							total_items = total_items + 1;
							if(total > 500)
								buzzer=0;
							c2=1;
						}
//						total = total + sugar;
						ConvertAndDisplay(sugar,"Sugar Cost");
						DelayMs(2000); 
						lcdinit();
						DelayMs(100);
//						welcome();
						ConvertAndDisplay(total,"Total Cost");
						ConvertAndDisplay_one(total_items,"total_items");
						goto back;
					}


				if(c[i]=='8' && c[i+1]=='4' && c[i+2]=='0' && c[i+3]=='0' && c[i+4]=='8' && c[i+5]=='5' && c[i+6]=='A' && c[i+7]=='5' && c[i+8]=='3' && c[i+9]=='0'&& c[i+10]=='9' && c[i+11]=='4')
					{
						if(c3==1)
						{
							total = total - coffee;
							total_items = total_items - 1;
							if(total < 500)
								buzzer=1;
							c3=0;
						}
						else
						{
							total = total + coffee;
							total_items = total_items + 1;
							if(total > 500)
								buzzer=0;
							c3=1;
						}
						//total = total + coffee;
						ConvertAndDisplay(coffee,"Coffee Cost");
						DelayMs(2000); 
						lcdinit();
						DelayMs(100);
//						welcome();
						ConvertAndDisplay(total,"Total Cost");
						ConvertAndDisplay_one(total_items,"total_items");
						goto back;
					}

				if(c[i]=='8' && c[i+1]=='4' && c[i+2]=='0' && c[i+3]=='0' && c[i+4]=='8' && c[i+5]=='5' && c[i+6]=='6' && c[i+7]=='D' && c[i+8]=='6' && c[i+9]=='5'&& c[i+10]=='0' && c[i+11]=='9')
					{
						if(c4==1)
						{
							total = total - rice;
							total_items = total_items - 1;
							if(total < 500)
								buzzer=1;
							c4=0;
						}
						else
						{
							total = total + rice;
							total_items = total_items + 1;
							if(total > 500)
								buzzer=0;
							c4=1;
						}

//						total = total + rice;
						ConvertAndDisplay(rice,"Rice Cost");
						DelayMs(2000); 
						lcdinit();
						DelayMs(100);
//						welcome();
						ConvertAndDisplay(total,"Total Cost");
						ConvertAndDisplay_one(total_items,"total_items");
						goto back;
					}


				if(c[i]=='8' && c[i+1]=='4' && c[i+2]=='0' && c[i+3]=='0' && c[i+4]=='8' && c[i+5]=='5' && c[i+6]=='A' && c[i+7]=='5' && c[i+8]=='4' && c[i+9]=='6'&& c[i+10]=='E' && c[i+11]=='2')
					{
						if(c5==1)
						{
							total = total - bread;
							total_items = total_items - 1;
							if(total < 500)
								buzzer=1;
							c5=0;
						}
						else
						{
							total = total + bread;
							total_items = total_items + 1;
							if(total > 500)
								buzzer=0;
							c5=1;
						}
						//total = total + bread;
						ConvertAndDisplay(bread,"Bread Cost");
						DelayMs(2000); 
						lcdinit();
						DelayMs(100);
//						welcome();
						ConvertAndDisplay(total,"Total Cost");
						ConvertAndDisplay_one(total_items,"total_items");
						goto back;
					}



			}


		unknown();
		DelayMs(1000);
		lcdinit();
		DelayMs(100);
		welcome();
	}
}
void unknown(void)
{
	unsigned int i=0;
	unsigned char c[]="ACCESS DENIED";

	lcdcmd(0x01);
	DelayMs(10);
	lcdcmd(0x80);
	DelayMs(10);

	while(c[i]!='\0')
	{
	lcdData(c[i]);
	i++;
	}
}

//---------------------------------------
// Lcd initialization subroutine
//---------------------------------------
void lcdinit(void)
{
lcdcmd(0x38); //creating a 5x7 matrix, crystal
DelayMs(250);
lcdcmd(0x0E); //Display on, cursor on
DelayMs(250);
lcdcmd(0x01); //clear screen
DelayMs(250);
lcdcmd(0x06); //Entry mode
DelayMs(250);
lcdcmd(0x80); //Force cursor to the beginning of the 1st row
DelayMs(250);
}

//---------------------------------------
// Lcd data display
//---------------------------------------
void lcdData(unsigned char l)
{
	P1=l;
	RS=1;
	EN=1;
	DelayMs(1);
	EN=0;
	return;
}

//---------------------------------------
// Lcd command
//---------------------------------------
void lcdcmd(unsigned char k)
{
	P1=k;
	RS=0;
	EN=1;
	DelayMs(1); //Make enable high to low with some delay
	EN=0;
	return;
}			   

//---------------------------------------
// Delay mS function
//---------------------------------------
void DelayMs(unsigned int count) 
{  // mSec Delay 11.0592 Mhz 
    unsigned int i;		      // Keil v7.5a 
    while(count) {
        i = 115; 			 // 115	exact value
		while(i>0) 
		i--;
        count--;
    }
}

void welcome(void)
{
	unsigned int i=0;
	unsigned char c[]="WELCOME TO RFID";	 
	unsigned char d[]="MALL BILLING SYS.";

	lcdcmd(0x01);
	DelayMs(10);
	lcdcmd(0x80);
	DelayMs(10);

	while(c[i]!='\0')
	{
	lcdData(c[i]);
	i++;
	}

	lcdcmd(0xc0);

	i=0;
	while(d[i]!='\0')
	{
	lcdData(d[i]);
	i++;
	}
}	

void ConvertAndDisplay(unsigned int value1,unsigned char c[])
{
unsigned int i,a=0,j;
unsigned char d1,d2,d3;
for(i=0;i<value1;i++)
a=a+1;
lcdcmd(0x01);
DelayMs(10);
lcdcmd(0x80);
DelayMs(10);

j=0;
while(c[j]!='\0')
{
lcdData(c[j]);
j++;
}
lcdData('=');
d1=a%10;		//digits before desible point
a=a/10;
d2=a%10;
a=a/10;
d3=a%10;

//lcdcmd(0xc0);
DelayMs(10);
display(d1,d2,d3);
}

void display(unsigned char s,t,u)
{
s=s+0x30;			//convert each digit to equivalent ASCII value
t=t+0x30;
u=u+0x30;

//Move the cursor to position 5 on LCD
DelayMs(50);

lcdData(u);			//Display the digits one by one on LCD
DelayMs(50);
lcdData(t);
DelayMs(50);
lcdData(s);
DelayMs(50);
} 
void ConvertAndDisplay_one(unsigned int value1,unsigned char c[])
{
unsigned int i,a=0,j;
unsigned char d1,d2,d3;
for(i=0;i<value1;i++)
a=a+1;
//lcdcmd(0x01);
//DelayMs(10);
lcdcmd(0xc0);
DelayMs(10);

j=0;
while(c[j]!='\0')
{
lcdData(c[j]);
j++;
}
lcdData('=');
d1=a%10;		//digits before desible point
a=a/10;
d2=a%10;
a=a/10;
d3=a%10;

//lcdcmd(0xc0);
DelayMs(10);
display_one(d1,d2,d3);
}

void display_one(unsigned char s,t,u)
{
s=s+0x30;			//convert each digit to equivalent ASCII value
t=t+0x30;
u=u+0x30;

//Move the cursor to position 5 on LCD
DelayMs(50);

lcdData(u);			//Display the digits one by one on LCD
DelayMs(50);
lcdData(t);
DelayMs(50);
lcdData(s);
DelayMs(50);
} 
