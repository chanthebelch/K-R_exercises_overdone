/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input.
 */

#include <stdio.h>
#include <math.h>


int main(void)
{
    const int len = 26;
    unsigned long freqs[26] = {};  /* ignore non-letters */
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
            ++freqs[c - 'A'];
        else if (c >= 'a' && c <= 'z')
            ++freqs[c - 'a'];
    }

    unsigned long max = 0, total = 0;
    for (int i = 0; i < len; ++i)
    {
        total += freqs[i];
        max = freqs[i] > max ? freqs[i] : max;
    }

    int X_AXIS = max < 50 ? max : 50;

    for (int i = 0; i < len; ++i)
    {
        printf("%c%c|", 'A' + i, 'a' + i);
        int width = round((float) freqs[i] / max * X_AXIS);
        for (int j = 0; j < width; ++j)
            printf("▇");
        printf(" %li\n", freqs[i]);
    }
    printf("max: %li, total: %li\n", max, total);

    return 0;
}

