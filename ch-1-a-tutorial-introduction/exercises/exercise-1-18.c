#include <stdio.h>

#define MAX_LINE_LENGTH 120

int getLine(char line[], int maxLine);

/* trims trailing tabs and spaces, removes lines with only whitespace characters */
int main(void)
{
    int length, i;
    char currentLine[MAX_LINE_LENGTH];

    while ((length = getLine(currentLine, MAX_LINE_LENGTH)) > 0)
    {
        i = length - 1;
        while (i >= 0 && (currentLine[i] == ' ' || currentLine[i] == '\t' || currentLine[i] == '\n'))
            i--;

        if (i >= 0)
        {
            currentLine[i + 1] = '\n';
            currentLine[i + 2] = '\0';
            printf("%s", currentLine);
        }
    }
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
