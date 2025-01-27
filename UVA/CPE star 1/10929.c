#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1010];
    while(fgets(input, 1010, stdin) && !(input[0] == '0' && input[1] == '\n')) { /*WTF, the '\n' is required!!*/
        int i, len = strlen(input) - 1, sum_odd = 0, sum_even = 0;
        input[len] = '\0';

        for(i = 0; i < len; i++)
            if(i % 2 == 1)
                sum_odd += input[i] - '0';
            else
                sum_even += input[i] - '0';

        if(abs(sum_even - sum_odd) % 11 == 0)
            printf("%s is a multiple of 11.\n", input);
        else
            printf("%s is not a multiple of 11.\n", input);
    }
    return 0;
}