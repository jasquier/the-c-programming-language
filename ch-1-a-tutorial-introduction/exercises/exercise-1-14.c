#include <stdio.h>

#define NUM_CHARS 26 /* count of lowercase letters */

/* prints a histogram of the frequencies of letters in the input */
int main() {

    printf("Enter letters only:\n");

    int i, j, c;
    int charFrequencies[NUM_CHARS];

    // initialize arrray
    for (i = 0; i < NUM_CHARS; i++) {
        charFrequencies[i] = 0;
    }

    // collect input and count characters only
    while((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            charFrequencies[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            charFrequencies[c - 'A']++;
        }
    }

    // print histogram
    printf("Character frequencies:\n");
    for (i = 0; i < NUM_CHARS; i++) {
        printf("%c\\%c: ", i + 'A', i + 'a');
        for (j = 0; j < charFrequencies[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}
