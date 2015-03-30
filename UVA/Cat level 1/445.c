#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[134];
    while(fgets(input, 134, stdin) != NULL) {
        int i, total = 0;
        for(i = 0; input[i] != '\0'; i++) {
            if(input[i] >= '0' && input[i] <= '9') {
                total += input[i] - '0';
            } else if(input[i] == '!' || input[i] == '\n') {
                printf("\n");
            } else if((input[i] >= 'A' && input[i] <= 'Z') || input[i] == 'b' || input[i] == '*') {
                int j;
                for(j = 0; j < total; j++) {
                    if(input[i] != 'b')
                        printf("%c", input[i]);
                    else
                        printf(" ");
                }
                total = 0;
            }
        }
    }
    return 0;
}