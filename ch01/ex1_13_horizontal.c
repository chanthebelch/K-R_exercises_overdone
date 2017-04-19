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

    int X_AXIS = max < 50 ? max : 50;
    for (int i = 0; i < LEN; ++i)
    {
        printf("%2i|", i + 1);
        int width = round((float) lengths[i] / max * X_AXIS);
        int color = 31 + round((float) lengths[i] / max * 5);
        for (int j = 0; j < width; ++j)
            printf("\033[%im▇\033[0m", color);
        printf("%4i\n", lengths[i]);
    }
    printf("max: %li, total: %li\n", max, total);

    return 0;
}

