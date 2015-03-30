#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int a, b;
    while(scanf("%lld %lld", &a, &b) != EOF)
        printf("%lld\n", (a - b) > 0 ? a - b : b - a);   
       
    return 0;
}