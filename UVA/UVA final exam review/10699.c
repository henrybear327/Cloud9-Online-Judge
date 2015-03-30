#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime_bit[1001] = {0};
void make_prime_list();

int main()
{
    make_prime_list();

    int input;
    while(scanf("%d", &input) != EOF && input) {
        printf("%d : ", input);
        int i = 0, count = 0;
        while(1) {
            if(prime_bit[i] != 0 && input % prime_bit[i] == 0) {
                count++;
                while(input % prime_bit[i] == 0)
                    input /= prime_bit[i];
            } else {
                if(prime_bit[i] != 0 )
                    i++;
                else
                    break;
            }
        }
        if(input != 1) //this means, there must be 1 number that is a prime which is still not counted yet. (verify)
            count++;
        printf("%d\n", count);
    }
    return 0;
}

void make_prime_list()
{
    int i = 0;
    for(i = 2; i < 1001; i++)
        prime_bit[i] = 1;
    for(i = 2; i < 1001; i++) {
        if(prime_bit[i] == 1) {
            int n = 2;
            while(i * n < 1001) {
                prime_bit[i * n] = 0;
                n++;
            }
        }
    }
    int index = 0;
    for(i = 0; i < 1001; i++) {
        if(prime_bit[i] == 1) {
            prime_bit[i] = 0;
            prime_bit[index++] = i;
            int n = 2;
            while(i * n < 1001) {
                prime_bit[i * n] = 0;
                n++;
            }
        }
    }
}