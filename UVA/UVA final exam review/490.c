#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[102][102];
    memset(sentence, ' ', sizeof(sentence));/*empty space needs to be filled in with ' '*/

    int count = 0, max = 0;
    while(fgets(sentence[count], 102, stdin) != NULL) {
        sentence[count][strlen(sentence[count]) - 1] = '\0'; /*\n -> \0*/
        sentence[count][strlen(sentence[count]) + 1] = ' '; /*\0 -> ' '*/
        max = (int)strlen(sentence[count]) > max ? (int)strlen(sentence[count]) : max; /* max is exact length*/
        sentence[count][strlen(sentence[count])] = ' '; /*\0 -> ' '*/
        count++;
    }
    count--; /*the count-th line will be NULL only*/

    int row = 0, column = 0;
    for(column = 0; column < max; column++) {
        for(row = count; row >= 0; row--) {
            if(sentence[row][column] == ' ' || sentence[row][column] == '\0' || sentence[row][column] == '\n')
                printf(" ");
            else
                printf("%c", sentence[row][column]);
        }
        printf("\n");
    }
    return 0;
}