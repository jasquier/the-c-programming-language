#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main() {

    int c, isPrintingSpaces = TRUE;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (isPrintingSpaces) {
                printf("%c", c);
            }
            isPrintingSpaces = FALSE;
        } else {
            isPrintingSpaces = TRUE;
            printf("%c", c);
        }
    }
}
