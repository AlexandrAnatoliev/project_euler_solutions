// main.c - project Euler problem 3 "Largest Prime Factor"
//
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 6008514745143?
//
#include <stdio.h>
#include <time.h>                                               // for clock_t, clock(), CLOCKS_PER_SEC

int main(void)
{
    long long answer = 600851475143;

    double time_spent = 0.0;                                    // для хранения времени выполнения кода
    clock_t begin = clock();                                    // СТАРТ таймера

    int div = 2;                                                // начало диапазона

    while(div * div < answer)                                        // пока число делится
    {
        for(div = 2 ; div * div < answer; div++)
            if( !(answer % div) )                               // если число делится нацело (answer % div == 0)
            {                                    
                answer /= div;                                  // уменьшаем число
                break;   
            }
    } 
    
    clock_t end = clock();                                      // СТОП таймера
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;       // время работы в секундах

    printf("answer = %lld runtime = %f\n", answer, time_spent); // выводим результат и время работы программы
    return 0;
}

