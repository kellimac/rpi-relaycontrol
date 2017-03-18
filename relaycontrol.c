#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPi.h>
#
# Simple C Program to read and write to Raspberry Pi GPIO pins. 
# Run the program with no command line arguments to show you the state of the pins.
# Run the program with 0's or 1's to turn various pins on and off 
# ex ./relaycontrol 0 1 0 0 1 
# Compile using gcc: gcc relaycontrol -o relaycontrol.c -l wiringPi
# requires the wiringPi library
# Use freely and at your own risk
# written by Kelli McMillan-McKowan 2015
# http://www.rationalmisanthrope.com
#

extern int errno ;
int main (int argc, char *argv[])
{


int errnum;
int i;
int pinstate;
int pinstates;
int readstate;
int numpins = 16;

wiringPiSetup () ;
if (argc > 1) { // if there are no arguments, then just give us the current pin states instead of changing anything
   numpins = argc-1; // this is just to change the readcount to the same as the number of changed pins
   for (i=0;i<argc-1;i++) {
	pinstates = atoi(argv[i+1]);
//	printf("%i ",argc);
	printf ("%i",pinstates);
	if (pinstates == 1) {pinstate = 1;}
	if (pinstates == 0) {pinstate = 0;}

        pinMode (i, OUTPUT) ;
        if (pinstate == 1) {digitalWrite (i,  HIGH);}
        if (pinstate == 0) {digitalWrite (i,  LOW);}
   }

   printf("\n");
}



for (i=0;i<numpins;i++) {
	readstate = digitalRead(i);
	printf ("%i",readstate);
}
printf("\n");

  return 0 ;
}
