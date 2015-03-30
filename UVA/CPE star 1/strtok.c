#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[30] = {'\0'};
    while(fgets(input, 12, stdin) != NULL && input[0] != '0') {
        char *token;
        token = strtok(input, " \0");

        int i = 0, number[2];
        while(token != NULL) {
            number[i++] = atoi(token);
            token = strtok(NULL, " \0");
        }

        printf("%d %d\n", number[0], number[1]);
    }

    return 0;
}