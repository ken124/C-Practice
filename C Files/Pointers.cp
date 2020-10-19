#include <stdio.h>

//https://www.cprogramming.com/tutorial/c/lesson6.html

int main()
{
    int x;            /* A normal integer*/
    int *p;           /* A pointer to an integer ("*p" is an integer, so p
                       must be a pointer to an integer) */

    p = &x;           /* Read it, "assign the address of x to p" */
    printf("Enter a Value for int x: \n");
    scanf( "%d", &x );          /* Put a value in x, we could also use p here */
    printf("This is the value of the pointer *p: \n");
    printf( "%d\n", *p ); /* Note the use of the * to get the value */
    printf("This is the address of the pointer *p: \n");
    printf( "%x\n\n", *p );
    getchar();

    printf("*********************************************************************\n\n");

    int var = 20;     //variable declaration
    int *ip;          //pointer variable declaration

    ip = &var;        //store address of var in pointer variable

    printf("Address of var variable: %x\n", &var );
    printf("Address store in ip variable: %x\n", ip );

    printf("Value of *ip variable: %d\n", *ip);
    printf("\n");

    return 0;
}
