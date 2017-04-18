/* Exercise 1-19. Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input a line at a
 * time.
 */

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int my_getline(char s[], int limit);

int main(void)
{
    int len = 0;
    char lines[MAXLINE] = {};
