#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_answer(long long int, int);

int main()
{
    long long int input, count = 1;
    while(scanf("%lld", &input) != EOF) {
        printf("%4d.", (int)count++);

        if(input == 0) {
            printf(" 0\n"); /*space!!*/
            continue;
        }

        long long int first_part, second_part;
        first_part = input / 10000000;
        second_part = input - (first_part * 10000000);

        /*printf("%lld %lld\n", first_part, second_part);*/
        print_answer(first_part, 1);
        print_answer(second_part, 2);
        printf("\n"); /*crucial*/
    }

    return 0;
}

void print_answer(long long int number, int flag)
{
    int alert = 0;
    if(flag == 1 && number / 10000000 != 0) {
        printf(" %lld kuti", number / 10000000);
        number = number - (number / 10000000 * 10000000);
        alert = 1;
    }
    if(number / 100000 != 0) {
        printf(" %lld lakh", number / 100000);
        number = number - (number / 100000 * 100000);
        alert = 1;
    }
    if(number / 1000 != 0) {
        printf(" %lld hajar", number / 1000);
        number = number - (number / 1000 * 1000);
        alert = 1;
    }
    if(number / 100 != 0) {
        printf(" %lld shata", number / 100);
        number = number - (number / 100 * 100);
        alert = 1;
    }
    if(flag == 1) { /*Watch out for this trick!!*/
        if(number != 0)
            printf(" %lld kuti", number);
        else if(alert == 1) /*bullshit*/
            printf(" kuti");
    }
    if(flag == 2) {
        if(number != 0)
            printf(" %lld", number);
    }

    return;
}