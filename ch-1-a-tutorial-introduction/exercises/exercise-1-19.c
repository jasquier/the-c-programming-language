#include <stdio.h>

#define MAX_LINE_LENGTH 120

int getLine(char line[], int maxLine);
void reverse(char original[], int size);

/* reverses the input string */
int main(void)
{
    int length;
    char currentLine[MAX_LINE_LENGTH];
    char currentLineReversed[MAX_LINE_LENGTH];

    while ((length = getLine(currentLine, MAX_LINE_LENGTH)) > 0)
    {
        /* length=1 is a newline and length=2 is a single char+newline, only reverse when there are 3 or more chars */
        if (length >= 3)
        {
            reverse(currentLine, length);
        }
        printf("%s", currentLine);
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

/* reverse: in place reversal of the characters of the string, does not reverse trailing newlines */
void reverse(char original[], int size)
{
    int i = 0;
    int j = size - 2; // shortest string: "ab\n\0" has size=3
    char temp;

    while (i < j)
    {
        temp = original[i];
        original[i] = original[j];
        original[j] = temp;

        i++;
        j--;
    }
}
