/*
 * William Wood cssc1167, Nadim Tahmass	cssc1158
 * CS570, Summer 2018
 * Assignment #3, Multithread Alarm Clock
 * main.c
 */

#include "alarmClock.h"

int isNumber(char number[]){
	int i = 0;
	
	for(; number[i] != 0; i++){
		if(!isdigit(number[i])){
			return 1;
		}
	}
	return 0;
	
}


int main (int argc, char* argv[]){
	
	char input[20];
	
	if(argv[1] != NULL){
		strcpy(input, argv[1]);
	}
	
	if(argc == 1){
		input[0] = '2';
		input[1] = '5';
	}
	
	else if(isNumber(input) == 1){
		printf("Invalid time value inputted. Exiting program.\n");
		exit(1);
	}

	if(pipe(pipe1) == -1){
		printf("Pipe creation failed.\n");
		exit(1);
	}
	//Create a struct to pass as a void pointer for the pthread_create function
	int seconds = atoi(input);
	int *arg = malloc(sizeof(int));
	
	*arg = seconds;

	
	pthread_t countdownT, wallClock;

	pthread_create(&countdownT, NULL, countdownTimer, (void *) arg);
	pthread_create(&wallClock, NULL, clockPrint, (void *) arg);

	pthread_join(countdownT, NULL);
	pthread_join(wallClock, NULL);

	printf("Thanks for using this alarm system.\n");

	free(arg);

	close (pipe1[0]);
	close (pipe1[1]);

	return 0;	
}
