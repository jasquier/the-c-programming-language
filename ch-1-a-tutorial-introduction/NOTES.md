# Chapter 1: A Tutorial Introduction

The goal of this first chapter is to give a rather quick, rather concise overview of the language essentials. We focus
on the core of the language and dive into the more complex features a bit later on. None of the features will be covered
in full and quite a few features will be skipped for now.

## 1.1 Getting Started

The only way to learn programming is to write programs.

As with all languages, we'll start by printing the words Hello, World! to the screen. Keep in mind that this simple task
involves many steps including creating the text file, compiling it, loading it, and running it. Assuming we can
accomplish this task, it's all downhill from here. Our program looks like [this][hello.c]:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
}
```

There's a lot going on in these few lines so let's break things down. First, we'll put that text in a file called
hello.c. Next we'll run the following command to compile our program:

```bash
cc hello.c
```

That command will output a file called *a.out* which we'll run using the command:

```bash
./a.out
```

Given everything went well we should the following on the terminal:

```bash
Hello, World!
```

Let's go back and explain the program itself. All C programs consist of *functions* and *variables*. Functions contain
*statements* that tell the computer what to do. Our program has one function called **main** which is a special
function. All C programs begin their execution with a **main** function. Otherwise we can name functions as we like.
Right before our one and only function we first include the standard input / output library. You will often see this as
well as other include statements at the top of a C program. In the body of our **main** function we call or invoke
another function, printf, and pass it the *string constant* "Hello, World!\n" which is our desired string with a newline
character on the end.

Don't forget to review the other escape characters.

## 1.2 Variables and Arithmetic Expressions

Let's solve the following problem:

- Print the Fahrenheit and Celsius temperature scales in 20 degree increments from 0 degrees Fahrenheit to 300 degrees
Fahrenheit, one Fahrenheit-Celsius pair per line.

We'll introduce several new ideas in the following program including *comments*, *variables*, *arithmetic*, *loops*, and
*output formatting*. Check out the solution below:

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main() {

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;   // lower limit of temperature table
    upper = 300; // upper limit
    step = 20;   // step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

Keep in mind that the size of char, short, int, long, float, double are all machine-dependent. Besides the programming
concepts we've seen, there are still many concepts to learn including *arrays*, *structures*, and *unions* of the basic
types as well as *pointers* to them, and *functions* that return them. All in due time.

Be sure to check out the tweaks we made to [the above program][fahr-celsius-table.c] below:

- [Right justified text][right-justified-fahr-celsius-table.c]
- [Floating point arithmetic][floating-point-fahr-celsius-table.c]

Note that `printf` accepts many format specifiers including:

- %d for integers
- %f for floats
- %o for octal
- %x for hexadecimal
- %c for characters
- %s for strings
- %% for % itself

## 1.3 The For Statement

Let's rewrite the Fahrenheit-Celsius converter:

```c
#include <stdio.h>

int main() {

    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```

The use of the for statement has allowed us to eliminate most of the variables present in the
while loop [version][fahr-celsius-table.c] of the same program. We also inlined the `celsius` variable by directly using
the expression in the printf statement. The choice between the for loop and while loop is arbitrary and it left to the
reader. Typically a while loop is used when the number of loops to be done is unknown.

## 1.4 Symbolic Constants

It's bad practice to leave number in your programs without clarifying what those numbers mean. We can use the
preprocessor to define constants in our programs. These constants will be replaced with the values they represent. Note
that convention is to use all capital letters in constant names, and also note the lack of a semi-colon when using
define. Check out the file [here][symbolic-constants.c].

```c
#include <stdio.h>

#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limit of table */
#define STEP  20  /* step size */

int main() {

    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```

## 1.5 Character Input and Output

Let's move on from temperature conversion and take a look at a family of programs for processing character data. The
model of input/output supported by the standard library is that of *text streams*. A *text stream* is a sequence of
characters divided into lines, each line ending in the newline character. We begin by learning to read and write one
character at a time using `getchar` and `putchar`. Each time it is called `getchar` reads the next input character from
a *text stream* and returns its value. The characters normally come from the keyboard. `putchar` prints a character each
time it is called, usually to the screen.

### 1.5.1 File Copying

Check out our first [program using these functions][copy-input-to-output-1.c],
note that we can copy more than one character using these functions. Note that the char datatype might not be big enough
to hold the expected EOF character.

We can shorten the first version of our program by noting that the statement:

```c
c = getchar();
```

Evaluates to the value of the left hand side after the assignment. We rewrite our program in
[version 2][copy-input-to-output-2.c]. Note that the precedence of `!=` is greater than `=` so the parentheses wrapping
our `(c = getchar())` statement are required.

### 1.5.2 Character Counting

Our [next program][character-counting-1.c] counts characters rather than copying them. We change things up a bit in the
[second version][character-counting-2.c].

### 1.5.3 Line Counting

[Counting lines][line-counting-1.c] is a simple as counting newline character appearances. Note the use of `==` to test
equality, don't confuse `==` and `=`. Remember, in C, characters are integers so `'\n'` is equivalent to 10 (usually).
It is always better to use character constants over integers, it increases the clarity of your program.

### 1.5.4 Word Counting

Ok this is the big one. In [the following program][lines-words-characters-counting.c] we will be counting lines, words,
and characters. A word is any sequence of characters that does not contain a blank, tab, or newline. Our program is
barebones version of the unix program `wc`. Note that in C `||` and `&&` short-circuit once their value is determined.

## 1.6 Arrays

## 1.7 Functions

## 1.8 Arguments - Call By Value

## 1.9 Character Arrays

## 1.10 External Variables and Scope

---

Don't forget to check out the [exercise solutions][exercise-solutions].

[hello.c]: ./hello.c
[fahr-celsius-table.c]: ./fahrenheit-celsius-table.c
[right-justified-fahr-celsius-table.c]: ./right-justified-fahrenheit-celsius-table.c
[floating-point-fahr-celsius-table.c]: ./floating-point-fahrenheit-celsius-table.c
[for-loop.c]: ./for-loop.c
[symbolic-constants.c]: ./symbolic-constants.c
[copy-input-to-output-1.c]: ./copy-input-to-output-1.c
[copy-input-to-output-2.c]: ./copy-input-to-output-2.c
[character-counting-1.c]: ./character-counting-1.c
[character-counting-2.c]: ./character-counting-2.c
[line-counting-1.c]: ./line-counting-1.c
[lines-words-characters-counting.c]: ./lines-words-characters-counting.c
[exercise-solutions]: ./exercises
