// ProjectEuler1c - Числа, кратные 3 или 5
// Если выписать все натуральные числа меньше 10, кратные 3 или 5, то получим 3, 5, 6 и 9.
// Сумма этих чисел равна 23. Найдите сумму всех чисел меньше 1000, кратных 3 или 5.

#include <stdio.h>
#include "header.h"

int main(void)
{
    int answ = 0;

    TIMER_START

    for (int num = 1; num < 1000; num++)    // sorting through the numbers
        if(IS_MULTIPLES(num))               // if it is divisible by 3 or 5
            answ += num;                    // add to answer

    TIMER_FINISH

    printf(ANSWER);     // display the result and running time of the program using MACRO

    return 0;
}

/* русские комментарии
int main(void)
{
    int answ = 0;

    TIMER_START

    for (int num = 1; num < 1000; num++)    // перебираем числа
        if(IS_MULTIPLES(num))               // если оно делится на 3 или 5
            answ += num;                    // складываем

    TIMER_FINISH

    printf(ANSWER);     // выводим результат и время работы программы используя МАКРОС

    return 0;
}*/