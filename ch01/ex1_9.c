/* Exercise 1-9. Write a program to copy its input to output, replacing each
 * string of one or more blanks by a single blank.
 */


#include <stdio.h>
#define IN  1  /* previous character is a blank */
#define OUT 0

int main(void)
{
    int state = OUT;
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (state == IN)
                ;
            else
            {
                putchar(c);
                state = IN;
            }
        }
        else
        {
            putchar(c);
            state = OUT;
        }
    }

    return 0;
}

