/* Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. (horizontal version)
 */


#include <math.h>
#include <stdio.h>

#define IN  1
#define OUT 0
#define LEN 10

int main(void)
{
    char c;
    int n = 0, state = OUT;
    int lengths[LEN] = {};  /* 1, 2, 3, ..., 9, 10+ */

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {
                if (n > 0 && n < 10)
                    ++lengths[n - 1];
                else
                    ++lengths[9];
                n = 0;
            }
            state = OUT;
        }
        else
        {
            ++n;
            state = IN;
        }
    }

    unsigned long max = 0, total = 0;
    for (int i = 0; i < LEN; ++i)
    {
        max = lengths[i] > max ? lengths[i] : max;
        total += lengths[i];
    }

    int Y_AXIS = max < 30 ? max : 30;
    for (int i = Y_AXIS; i > 0; --i)
    {
        printf("%4i|", (int) round((float) i / Y_AXIS * max));
        for (int j = 0; j < LEN; ++j)
        {
            int height = round((float) lengths[j] / max * Y_AXIS);
            printf("  ");
            if (height >= i)
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }

    printf("    +");
    for (int i = 0; i < LEN * 3; ++i)
        putchar('-');
    putchar('\n');
    printf("     ");
    for (int i = 0; i < LEN; ++i)
        printf(" %2i", i + 1);
    putchar('\n');

    return 0;
}

