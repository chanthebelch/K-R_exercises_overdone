/* pg. 22
 * count lines, words, and characters in input
 */


#include <stdio.h>

#define IN  1
#define OUT 0


int main(void)
{
    char c;
    int nl = 0, nw = 0, nc = 0;
    int state = OUT;

    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
        {
            ++nl;
            state = OUT;
        }
        else if (c == ' ' || c == '\t')
        {
            state = OUT;
        }
        else
        {
            if (state == OUT)  // only increment nw when the state change from
                ++nw;          // OUT to IN
            state = IN;
        }
    }
    printf("%i %i %i\n", nl, nw, nc);

    return 0;
}

