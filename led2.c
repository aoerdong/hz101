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
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);
	
	digitalWrite(9,LOW);
	int total = 20;
	int time = total;
	int step = 1;
	int i;
	
	while(1)
	{
		for(time=total;time>0;time -=step)
		{	
			for(i=0;i<10;i++)
			{
				digitalWrite(8,HIGH);
				delay(time);
				digitalWrite(8,LOW);
				delay(total-time);
				/*if(time<=0)
					time = total;*/
			}
		}
		for(time=total;time>0;time -=step)
		{
		for(i=0;i<10;i++)
		{
			digitalWrite(8,LOW);
			delay(time);
			digitalWrite(8,HIGH);
			delay(total-time);
			/*if(time<=0)
				time = total;*/
		}
		}
		
	}
	return 0;
}
