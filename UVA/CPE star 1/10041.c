#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; /*positive, don't swap*/
}

int main()
{
    int test_case;
    while(scanf("%d", &test_case) != EOF) {
        while(test_case--) {
            int cases, data[500] = {0};
            scanf("%d", &cases);

            int i, sum = 0;
            for(i= 0; i < cases; i++)
                scanf("%d", &data[i]);

            qsort(data, cases, sizeof(int), compare);

            int total = 0, mid = cases / 2;
            for(i = 0; i < cases; i++) {
                total += abs(data[i] - data[mid]);
            }
            
            printf("%d\n", total);
                
        }
    }
    return 0;
}