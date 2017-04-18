/* Exercise 1-2. Experiment to find out what happens when printf's argument
 * string contains \c, where c is some character not listed above.
 */

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
            printf("  %c ", i * 16 + j);
        putchar('\n');
    }

    return 0;
}

