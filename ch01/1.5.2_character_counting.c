/* pg. 20 */


#include <stdio.h>


int main(void)
{
    unsigned long nc = 0;

    while (getchar() != EOF)
        ++nc;

    printf("%li\n", nc);

    return 0;
}

