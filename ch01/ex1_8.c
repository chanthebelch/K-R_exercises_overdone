/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */


#include <stdio.h>


int main(void)
{
    char c;
    unsigned long nb = 0, nt = 0, nl = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case ' ':
                ++nb;
                break;
            case '\t':
                ++nt;
                break;
            case '\n':
                ++nl;
                break;
        }
    }
        
    printf("blanks: %li, tabs: %li, newlines: %li\n", nb, nt, nl);

    return 0;
}

