#include <stdio.h>

int main() {
    printf("Hello, World!\d");
}

// the above program gives the follwing output when compiled using cc:
// exercise-1-2.c:4:26: warning: unknown escape sequence '\d' [-Wunknown-escape-sequence]
//     printf("Hello, World!\d");
//                          ^~
// 1 warning generated.
