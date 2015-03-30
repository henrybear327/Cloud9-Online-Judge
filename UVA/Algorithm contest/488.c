#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int amplitude, frequency;
            scanf("%d", &amplitude);
            scanf("%d", &frequency);

            int i, j, flag = 0;
            for(i = 1; i <= frequency; i++) {
                for(j = 1; j > 0; (flag == 0) ? j++ : j--) {
                    int temp = j;
                    while(temp--)
                        printf("%d", j);
                    printf("\n");
                    if(j == amplitude)
                        flag = 1;
                }
                flag = 0;
                if(frequency != i)
                    printf("\n");
            }
            if(test_cases != 0)
                printf("\n");
        }
    }

    return 0;
}