// main.c - project Euler problem 3 "Largest Prime Factor"
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 6008514745143?
//
#include <stdio.h>
#include "timer.h"	// to measure the program running time

int main(void)
{
    long long answer = 600851475143;
    int div = 2;                                                // начало диапазона

	TIMER_START

    while(div * div < answer)                                        // пока число делится
    {
        for(div = 2 ; div * div < answer; div++)
            if( !(answer % div) )                               // если число делится нацело (answer % div == 0)
            {                                    
                answer /= div;                                  // уменьшаем число
                break;   
            }
    } 
    
	TIMER_STOP
	TIMER_PRINT

    printf("answer = %lld\n", answer); // выводим результат
	
	return 0;
}

