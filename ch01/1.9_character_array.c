/* pg. 29
 * The outline:
 *     while (there's another line)
 *         if (it's longer than the previous longest)
 *             (save it)
 *             (save its length)
 *     print longest line
 */


#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */


int my_getline(char line[], int limit);
void copy(char to[], char from[]);


int main(void)
{
    int len = 0, max = 0;  /* current line length and max length seen so far */
    char line[MAXLINE] = {};     /* current input line */
    char longest[MAXLINE] = {};  /* longest line saved here */

    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)  /* there was a line */
        printf("%s", longest);

    return 0;
}


/* my_getline: read a line into line[], return its length */
int my_getline(char line[], int limit)
{
    char c;
    int i = 0;

    for (; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}


/* copy: copy from[] into to[]; assume to[] is big enough */
void copy(char to[], char from[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}

