/*
 * William Wood cssc1167, Nadim Tahmass	cssc1158
 * CS570, Summer 2018
 * Assignment #3, Multithread Alarm Clock
 * alarmClock.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

int pipe1[2];

//Waits x seconds then sends 'C' through a pipe and returns NULL
void *countdownTimer(void *x);

/* Continually prints the time till it recieves a C through the pipe.
 * Also prints starting time.
 */
void *clockPrint(void *x);
