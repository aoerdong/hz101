#include<stdio.h>
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
	
	
	digitalWrite(8,HIGH);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
	digitalWrite(12,HIGH);
	digitalWrite(13,HIGH);
	
	digitalWrite(8, LOW);
	softPwmCreate(9, 0, 100);
	softPwmCreate(7, 0, 100);
	softPwmCreate(0, 0, 100);
	
	while(1)
	{
		softPwmWrite(9, 0);
		softPwmWrite(7, 0);
		softPwmWrite(0, 0);
		delay(1000);
		softPwmWrite(9, 255);
		softPwmWrite(7, 255);
		softPwmWrite(0, 255);
		delay(1000);
	}
	return 0;
}
