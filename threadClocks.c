/*
 * William Wood cssc1167, Nadim Tahmass	cssc1158
 * CS570, Summer 2018
 * Assignment #3, Multithread Alarm Clock
 * threadClocks.c
 */

#include "alarmClock.h"

void *countdownTimer(void *x){
	int time = *((int *) x);
	

	sleep(time);

	printf("Alarm! ");

	write(pipe1[1], "C", 1);
	
	
	
	return NULL;
}

//Wall Clock printer
void *clockPrint(void *x){
	int inputTime = *((int *) x);
	
	//first second to x seconds
	int i = 1;
	time_t timer;
	char buffer[32];
	char cCheck[10];
	struct tm* tm_info;
	
	
	while(1) {
		
		time(&timer);
		tm_info = localtime(&timer);
		strftime(buffer, 32, "%H:%M:%S", tm_info);

		//Let you know the start time
		if( i == 1){
			printf("Alarm countdown start is %s\n", buffer);
		}
		//Normal time printing
		else{
			printf("%s\n", buffer);
		}


		if(i >= inputTime){
			read(pipe1[0], cCheck, 1);
	
		}
		//Prints the time the alarm went off and breaks while loop to close.
		if(cCheck[0] == 'C'){
			
			time(&timer);
			tm_info = localtime(&timer);
			strftime(buffer, 32, "%H:%M:%S", tm_info);
			printf("%s your timer for %d seconds is over\n", buffer, inputTime);
			break;
		}			

		i++;
		sleep(1);
	
	}
	
	
	return NULL;
}
