/* Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters.
 */

#include <stdio.h>
#define MAXLINE 1000


int my_getline(char s[], int limit);


int main(void)
{
    int len = 0;
    char line[MAXLINE] = {};

    while ((len = my_getline(line, MAXLINE)) > 0)  /* 空行将使本程序失效 */
    {
        if (len > 80)
            printf("%s", line);
    }

    return 0;
}


int my_getline(char s[], int limit)
{
    int i = 0;
    char c;

    while (i < limit - 1 && (c = getchar()) != EOF)
    {
        s[i] = c;
        if (c == '\n')
            break;
        ++i;
    }
    s[i + 1] = '\0';

    return c == EOF || s[0] == '\n' ? 0 : i + 1;
}

