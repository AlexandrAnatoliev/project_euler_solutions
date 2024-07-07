// header.h

#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

#define TIMER_START double time_spent = 0.0; clock_t begin = clock(); 
#define TIMER_FINISH clock_t end = clock(); time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
// operation:		measuring the program running time
// precondition:	double time_spent = 0.0;	create a variable to store code execution time
//					clock_t begin = clock();	timer START
// postcondition:	clock_t end = clock();		timer STOP
//					time_spent += (double)(end - begin) / CLOCKS_PER_SEC; 
//												measure operating time in seconds

#define IS_NOT_DIVIDED(NUM, DIV) (NUM % DIV)
// operation:		determining whether a number is divisible by an integer divisor
// precondition:	NUM			- number to be checked
//					DIV			- number divisor
// postcondition:	false (0)	- if the number is evenly divisible by the divisor
//					true		- if the number is not divisible

#define IS_MULTIPLES(NUM) (!IS_NOT_DIVIDED(NUM, 3)) || (!IS_NOT_DIVIDED(NUM, 5))
// operation:		determining whether a number is divisible by 3 or 5
// precondition:	NUM		- number to be checked
// postcondition:	true	- if the number is divisible by one of the divisors
//					false	- if the number is not divisible

#define ANSWER "answer = %d runtime = %f\n", answ, time_spent 
// pass the MACRO to printf() to print the response
