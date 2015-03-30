#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("prime.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    long long int i = 2, j, count = 1;
    fprintf(f, "%lld, ", i);
    i++;
    for(i = 3; i<= 47000; i += 2) {
        for(j = 3; j * j <= i; j += 2) {
            if(i % j == 0)
                break;
        }
        if(j * j > i) {
            /*printf("%lld, ", i);*/
            fprintf(f, "%lld, ", i);
            count++;
        }
    }
    printf("count = %lld", count);
    fclose(f);
    return 0;
}