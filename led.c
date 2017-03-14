#include<stdio.h>// printf scantf
#include<wiringPi.h>

int main()
{
	wiringPiSetup();
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(13,OUTPUT);
	
	digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);
	
	digitalWrite(8,HIGH);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
	digitalWrite(12,HIGH);
	digitalWrite(13,HIGH);
	
	while(1)
	{
		digitalWrite(9,LOW);
		digitalWrite(13,HIGH);
		digitalWrite(8,LOW);
		delay(1000);
		digitalWrite(8,HIGH);
		digitalWrite(2,LOW);
		delay(1000);
		digitalWrite(2,HIGH);
		digitalWrite(3,LOW);
		delay(1000);
		digitalWrite(3,HIGH);
		digitalWrite(12,LOW);
		delay(1000);
		digitalWrite(12,HIGH);
		digitalWrite(13,LOW);
		delay(1000);
	}	
	return 0;	
}
