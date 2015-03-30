/*astyle --style=linux 272.c && gcc -Wall -Wextra -g -lm -lcrypt  -pipe -ansi -DONLINE_JUDGE 272.c -o 272 && ./272*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main()
{
    char input[1000];
    int flag = FALSE;
    while(fgets(input, 1000, stdin) != NULL) {
        int i, count = 0;
        char output[1000];
        for(i = 0; input[i] != '\0'; i++) {
            if(input[i] == '"' && flag == FALSE) {
                flag = TRUE;
                output[count++] = 96;
                output[count++] = 96;
            } else if(input[i] == '"' && flag == TRUE) {
                flag = FALSE;
                output[count++] = 39;
                output[count++] = 39;
            } else {
                output[count++] = input[i];
            }
        }
        output[count] = '\0';
        printf("%s", output);
    }

    return 0;
}