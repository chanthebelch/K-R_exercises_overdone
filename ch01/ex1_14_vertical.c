/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>
#include <math.h>


int main(void)
{
    const int len = 126 - 33 + 1;  /* only the printable ascii characters */
    char c;
    int freqs[94] = {};

    while ((c = getchar()) != EOF)
    {
        if (c >= 33 && c <= 126)
            ++freqs[c - 33];
    }

    // statistics
    int total = 0, max = 0;
    for (int i = 0; i < len; ++i)
    {
        total += freqs[i];
        max = freqs[i] > max ? freqs[i] : max;
    }

    // draw histogram vertically
    const int Y_AXIS = max < 30 ? max : 30;
    for (int i = Y_AXIS; i > 0; --i)
    {
        printf("%5i|", (int) round((float) i / Y_AXIS * max));
        for (int j = 0; j < len; ++j)
        {
            int height = round((float) freqs[j] / max * Y_AXIS);
            if (height >= i)
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }

    // print x-axis
    printf("     +");
    for (int i = 0; i < len; ++i)
        putchar('-');
    putchar('\n');
    printf("      ");
    for (int i = 0; i < len; ++i)
        putchar(33 + i);
    putchar('\n');
    printf("        max: %i, total: %i\n", max, total);

    return 0;
}

