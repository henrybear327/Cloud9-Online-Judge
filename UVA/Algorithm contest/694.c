#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*(2147483647 - 1) / 3 = 715827882*/

int main()
{
    int input, limit, case_count = 1;
    while(scanf("%d %d", &input, &limit) != EOF && (input != -1 && limit != -1)) {
        printf("Case %d: A = %d, limit = %d, number of terms = ", case_count++, input, limit);
        int count = 1;
        while(input != 1) {
            if(input % 2 == 0) /*even*/
                input /= 2;
            else { /*odd*/
                if(input <= 715827882)
                    input = input * 3 + 1;
                else
                    break;
            }
            if(input <= limit)
                count++;
            else
                break;
        }
        printf("%d\n", count);
    }

    return 0;
}