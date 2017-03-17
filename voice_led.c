#include<stdio.h>
#include<wiringPi.h>
#include<sys/time.h>

void led_init()
{
	pinMode(7, OUTPUT);   //D0
	pinMode(0, OUTPUT);		// R
	
	digitalWrite(7, HIGH);
	digitalWrite(0, HIGH);
	
}

int voice_init()
{
	pinMode(8,OUTPUT);
	pinMode(9,INPUT);
	
	digitalWrite(8,LOW);
	digitalWrite(9,LOW);
	digitalWrite(8,HIGH);
	delayMicroseconds(10);
	digitalWrite(8,LOW);
	
	struct timeval start, end;
	
	int val=digitalRead(9);
	while(val==0)
	{
		val = digitalRead(9);
	}
	printf("start\n");
	gettimeofday(&start,NULL);
	while(val==1)
	{
		val = digitalRead(9);
	}
	printf("end\n");
	gettimeofday(&end,NULL);
	
	long t1 = start.tv_sec * 1000000 + start.tv_usec;
	long t2 = end.tv_sec * 1000000 + end.tv_usec;
	
	float dis = (float)(t2-t1)/1000000 * 34000/2;
	printf("%fcm\n",dis);
	
	return dis;	
}

int main()
{
	wiringPiSetup();
	void led_init();
	int dis;
	int x = 50;
	while(1)
	{
		dis = voice_init();
		if(dis<=x)
		{
			digitalWrite(7,LOW);
			digitalWrite(0,LOW);
		}
		else if(dis>x)
		{
			digitalWrite(7,HIGH);
			digitalWrite(0,HIGH);
		}
		delay(2000);
	}
	return 0;
}