#Project Euler problem2: Even Fibonacci Numbers

Для удобства разделим программу не несколько файлов:
* header.h	- объявления функций, используемых в программе
* funcs.c	- реализация функций

## Файл header.h

С помощью конструкции:
```
#ifndef HEADER
#define HEADER
#endif
```
int get_fib_recurs(int ser_num);
// operation:		 getting the Fibonacci number by its serial number recursively
// precondition:	 function takes the serial number
// postcondition:	 and return the Fibonacci number

int get_next_fib(int array[]);
// operation:		 getting the next Fibonacci number by using array
// precondition:	 function takes the array is containing the first two Fibonacci numbers
// postcondition:	 return the next Fibonacci number and stores the last two numbers in an array
// 			

## Файл funcs.c
Защищаем файл от повторного включения
Подключаем с помощью "header.h" объявления функций.
С помошью заголовочного файла <assert.h> подключаем библиотеку утверждений. Она необходима для обработки ошибок  при отладке программы.


int get_fib_recurs(int ser_num)
// operation:		 getting the Fibonacci number by its serial number recursively
// precondition:	 function takes the serial number
// postcondition:	 and return the Fibonacci number
{
	if(ser_num <= 1)
		return 1;
	else
		return get_fib_recurs(ser_num - 1) + get_fib_recurs(ser_num - 2);
}

int get_next_fib(int array[])
// operation:		 getting the next Fibonacci number by using array
// precondition:	 function takes the array is containing the first two Fibonacci numbers
// postcondition:	 return the next Fibonacci number and stores the last two numbers in an array
{
	assert((array[0] > 0) && (array[1] > 0) && (array[0] <= array[1]));	// input valudation
										
	int next_fib = array[0] + array[1];	// next Fibonacci number is sum previous two numbers
						
	array[0] = array[1];				// updating the values of the last numbers
	array[1] = next_fib;
	
	return next_fib;
}


