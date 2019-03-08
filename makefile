# William Wood cssc1167, Nadim Tahmass cssc1158
# CS570, Summer 2018
# Assignment #3, Multithread Alarm Clock
# makefile
 

tevent: main.c threadClocks.c
	gcc -pthread -o tevent threadClocks.c main.c -I.
