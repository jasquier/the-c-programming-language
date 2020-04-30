#include <stdio.h>

#define MAX_WORDS 10

/* prints a histogram of the lengths of words in its input */
int main() {

    int i, j, c, numWords, currentWordLength;
    int wordLengths[MAX_WORDS];

    /* initialize the array */
    for (i = 0; i < MAX_WORDS; i++) {
        wordLengths[i] = 0;
    }

    numWords = currentWordLength = 0;
    printf("Enter a maximum of %d words:\n", MAX_WORDS);

    while ((c = getchar()) != EOF && numWords < MAX_WORDS) {
        if (c == ' ' || c == '\t' || c == '\n') {
            wordLengths[numWords] = currentWordLength;
            numWords++;
            currentWordLength = 0;
        } else {
            currentWordLength++;
        }
    }

    /* next we print the histogram */
    printf("\nWord Lengths Histogram:\n");

    /* determine the maximum word length so we know the highest bar in our histogram */
    int maxWordLength = 0;
    for (i = 0; i < numWords; i++) {
        if (wordLengths[i] > maxWordLength) {
            maxWordLength = wordLengths[i];
        }
    }

    /* print each word length then a star for each word of that length */
    for (i = 0; i <= maxWordLength; i++) {
        printf("%d: ", i);
        for (j = 0; j < numWords; j++) {
            if (wordLengths[j] == i) {
                printf("*");
            }
        }
        printf("\n");
    }
}
