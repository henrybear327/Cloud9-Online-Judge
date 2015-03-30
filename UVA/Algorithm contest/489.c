#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int left_over(int []);

int main()
{
    int round;
    while(scanf("%d", &round) != EOF && round != -1) {
        getchar();
        char ans[100];
        fgets(ans, 100, stdin);
        char guess[100];
        fgets(guess, 100, stdin);

        int i, wrong_count = 0, ans_count[26] = {0}, guess_count[26] = {0};

        /*present 1, not present 0*/
        for(i = 0; ans[i] != '\n'; i++)
            if(ans_count[ans[i] - 'a'] == 0)
                ans_count[ans[i] - 'a'] = 1;
        for(i = 0; guess[i] != '\n'; i++) { /*Don't forget to check whether the ans has all been guessed or not!!!*/
            int guess_ascii = guess[i] - 'a'; /*guessed char doesn't matter at all*/
            if(guess_count[guess_ascii] == 0 && ans_count[guess_ascii] == 1) {
                ans_count[guess_ascii] = -1;
                guess_count[guess_ascii] = 1;
            } else if(guess_count[guess_ascii] == 0 && ans_count[guess_ascii] == 0) {
                wrong_count++;
                guess_count[guess_ascii] = 1;
            }

            if(wrong_count == 7 || left_over(ans_count) == 0)
                break;
        }
        printf("Round %d\n", round);
        if(wrong_count == 7)
            printf("You lose.\n");
        else {
            if(left_over(ans_count) == 1)
                printf("You chickened out.\n");
            else
                printf("You win.\n");
        }

    }
    return 0;
}

int left_over(int ans_count[])
{
    int i;
    for(i = 0; i < 26; i++) {
        if(ans_count[i] == 1)
            return 1;
    }
    return 0;
}