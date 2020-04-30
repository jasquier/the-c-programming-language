#include <stdio.h>

#define MAX_LINE_LENGTH 120
#define LONG_LINE_CHAR_COUNT 80

int getLine(char line[], int maxLine);

/* prints all input lines that are longer than LONG_LINE_CHAR_COUNT characters */
int main(void)
{
    int length;
    int currentLongLineIndex = 0;
    char currentLine[MAX_LINE_LENGTH];

    while ((length = getLine(currentLine, MAX_LINE_LENGTH)) > 0)
        if (length > LONG_LINE_CHAR_COUNT)
            printf("%s", currentLine);
}

/* getLine: read a line into line[], returns the length of the line read in */
int getLine(char line[], int maxLine)
{
    int c, i;

    for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}
