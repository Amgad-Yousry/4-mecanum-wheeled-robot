#define F_CPU 16000000UL
#include "avr/io.h"
#include <util/delay.h>
void PWM_init()
{
TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
TCCR1A = (1<<WGM11) | (1<<COM1A1) | (1<<COM1B1);
TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS10) | (1<<CS11);
TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) | (1<<CS20);
DDRC = 0xff;
DDRB|= (1<<PINB3);
DDRD|= (1<<PIND5);
DDRD|= (1<<PIND4);
DDRD|= (1<<PIND7);
TCNT1 = 0;
ICR1 = 255;
}
void N_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x66;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void S_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x99;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void E_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0xA5;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void W_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x5A;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void N_E_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x24;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void N_W_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x42;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void S_E_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x81;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void S_W_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x18;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void Rot_E_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0xAA;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void Rot_W_M(int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x55;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void Turn_N_E (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x66;
OCR1A= duty_M1;
OCR1B=0.1 *duty_M2;
OCR2= duty_M3;
OCR0= 0.1* duty_M4;
}
void Turn_N_W (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x66;
OCR1A= 0.1* duty_M1;
OCR1B= duty_M2;
OCR2= 0.1* duty_M3;
OCR0= duty_M4;
}
void Turn_S_E (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x99;
OCR1A=duty_M1;
OCR1B= 0.1*duty_M2;
OCR2=duty_M3;
OCR0= 0.1* duty_M4;
}
void Turn_S_W (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x99;
OCR1A= 0.1*duty_M1;
OCR1B= duty_M2;
OCR2= 0.1*duty_M3;
OCR0= duty_M4;
}
void Lat_N_e_w (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x0A;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void Lat_N_w_e (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x05;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void Lat_S_e_w (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0xA0;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
void Lat_S_w_e (int duty_M1,int duty_M2,int duty_M3, int duty_M4)
{
PORTC=0x50;
OCR1A=duty_M1;
OCR1B=duty_M2;
OCR2=duty_M3;
OCR0=duty_M4;
}
int main ()
{
unsigned char duty_M1;
unsigned char duty_M2;
unsigned char duty_M3;
unsigned char duty_M4;
PWM_init();
while (1)
{
duty_M1=255;
duty_M2=255;
duty_M3=255;
duty_M4=255;
N_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
S_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
E_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
W_M (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
N_E_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
N_W_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
S_E_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
S_W_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Rot_E_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Rot_W_M(duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Turn_N_E (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Turn_N_W (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Turn_S_E (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Turn_S_W (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Lat_N_e_w (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Lat_N_w_e (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Lat_S_e_w (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
Lat_S_w_e (duty_M1,duty_M2, duty_M3,duty_M4);
_delay_ms(2000);
}
}