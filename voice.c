#include<stdio.h>
#include<wiringPi.h>
#include<sys/time.h>

int main()
{
	wiringPiSetup();
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
	
	return 0;
}
