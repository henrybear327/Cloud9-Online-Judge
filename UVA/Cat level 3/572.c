#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkforpockets(char [102][102], int, int, int, int);

int main()
{
    int rows, columns;
    while(scanf("%d %d", &rows, &columns) != EOF && rows != 0 && columns != 0) {
        getchar();
        char data[102][102] = {0};
        int i, j;
        for(i = 0; i < rows; i++)
            fgets(data[i], 102, stdin);

        int count = 0;
        for(i = 0; i < rows; i++) {
            for(j = 0; j < columns; j++) {
                if(data[i][j] == '@') {
                    count++;
                    checkforpockets(data, i, j, rows, columns);
                }
            }
        }

        printf("%d\n", count);
    }
    return 0;
}

void checkforpockets(char data[][102], int i, int j, int rows, int columns)
{
    if(data[i][j] == '@')
        data[i][j] = '*';
    else
        return;

    int p, q;
    for(p = i - 1; p <= i + 1; p++) {
        for(q = j + 1; q >= j - 1; q--) {
            if(p < rows && q < columns && p >= 0 && q >= 0)
                checkforpockets(data, p, q, rows, columns);
        }
    }

    return;
}