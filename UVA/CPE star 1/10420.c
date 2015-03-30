#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    int cases;
    while(scanf("%d", &cases) != EOF) {
        getchar();
        char country[75][50];
        memset(country,'\0',sizeof(country));
        
        int i=0,case_original=cases;
        while(cases--) {
            char input[75+2], *token;
            fgets(input, 77, stdin);
            token = strtok(input, " ");
            strcpy(country[i++], token);
        }
        
        qsort(country, case_original, sizeof(char) * 50, compare);
        
    }
    
    return 0;
}