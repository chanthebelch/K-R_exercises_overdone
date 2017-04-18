/* Exercise 1-12. Write a program that prints its input one word per line. */


#include <stdio.h>


int main(void)
{
    char c;
    int prev_is_white_space = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ;
        else if (c == ' ' || c == '\t')
        {
            if (prev_is_white_space)
                ;
            else
                putchar('\n');
            prev_is_white_space = 1;
        }
        else
        {
            putchar(c);
            prev_is_white_space = 0;
        }
    }
    putchar('\n');  /* since all '\n' is ingored, it is neccesory to do this */

    return 0;
}

