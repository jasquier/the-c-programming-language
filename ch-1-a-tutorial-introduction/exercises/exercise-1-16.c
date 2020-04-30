#include <stdio.h>

#define MAXLINE 10    /* maximum input line length */

int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

/*
    Prints the longest input line.
    If the longest line is longer than MAXLINE, prints line length plus MAXLINE characters.
*/
int main(void)
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)    /* there was a line */
    {
        printf("The longest line is %d characters long.\n", max);
        printf("%s", longest);
        /* include a newline if we know the string doesn't end with one */
        if (max >= MAXLINE)
        {
            printf("\n");
        }
    }

    return 0;
}

/* getLine: reads at most maxLine-1 characters into line, returns the total number of characters read in */
int getLine(char line[], int maxLine)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        /* only save maxLine-1 characters */
        if (i < maxLine - 1)
        {
            line[i] = c;
        }
    }

    /* count the newline but only save it if there is room */
    if (c == '\n')
    {
        if (i < maxLine - 1)
        {
            line[i] = c;
        }
        i++;
    }

    /* put a null terminator at i or maxLine - 1 whichever is lesser */
    int nullTerminatorIndex = i < maxLine ? i : maxLine - 1;
    line[nullTerminatorIndex] = '\0';

    return i;
}

/* copy: copy from into to; assumes to is big enough */
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}
