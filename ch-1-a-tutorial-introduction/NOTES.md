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

int main()
{
    printf("Hello, World!\n");
}
```

There's a lot going on in these few lines so let's break things down. First, we'll put that text in a file called
hello.c. Next we'll run the following command to compile our program:

```bash
cc hello.c
```

That command will output a file called _a.out_ which we'll run using the command:

```bash
./a.out
```

Given everything went well we should the following on the terminal:

```bash
Hello, World!
```

Let's go back and explain the program itself. All C programs consist of _functions_ and _variables_. Functions contain
_statements_ that tell the computer what to do. Our program has one function called **main** which is a special
function. All C programs begin their execution with a **main** function. Otherwise we can name functions as we like.
Right before our one and only function we first include the standard input / output library. You will often see this as
well as other include statements at the top of a C program. In the body of our **main** function we call or invoke
another function, printf, and pass it the _string constant_ "Hello, World!\n" which is our desired string with a newline
character on the end.

Don't forget to review the other escape characters.

## 1.2 Variables and Arithmetic Expressions

Let's solve the following problem:

- Print the Fahrenheit and Celsius temperature scales in 20 degree increments from 0 degrees Fahrenheit to 300 degrees
  Fahrenheit, one Fahrenheit-Celsius pair per line.

We'll introduce several new ideas in the following program including _comments_, _variables_, _arithmetic_, _loops_, and
_output formatting_. Check out the solution below:

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;   // lower limit of temperature table
    upper = 300; // upper limit
    step = 20;   // step size

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

Keep in mind that the size of char, short, int, long, float, double are all machine-dependent. Besides the programming
concepts we've seen, there are still many concepts to learn including _arrays_, _structures_, and _unions_ of the basic
types as well as _pointers_ to them, and _functions_ that return them. All in due time.

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

int main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```

The use of the for statement has allowed us to eliminate most of the variables present in the
while loop [version][fahr-celsius-table.c] of the same program. We also inlined the `celsius` variable by directly using
the expression in the printf statement. The choice between the for loop and while loop is arbitrary and is left to
the reader. Typically a while loop is used when the number of loops to be done is unknown.

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

int main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
```

## 1.5 Character Input and Output

Let's move on from temperature conversion and take a look at a family of programs for processing character data. The
model of input/output supported by the standard library is that of _text streams_. A _text stream_ is a sequence of
characters divided into lines, each line ending in the newline character. We begin by learning to read and write one
character at a time using `getchar` and `putchar`. Each time it is called `getchar` reads the next input character from
a _text stream_ and returns its value. The characters normally come from the keyboard. `putchar` prints a character each
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

Now let's write [a program][counting-more.c] that counts even more! We'll count the number of occurrences of each digit,
of whitespaces, and of all other characters. We'll use an array to hold the number of occurrence of each digit rather
than ten individual variables.

## 1.7 Functions

Functions provide a convenient way to encapsulate some computation or action. We can then reuse the function without
worrying about its implementation. Functions allow us to ignore how something is done and focus on what is done instead.
You'll sometimes see functions defined and called only once, just to clarify some code. So far, we have only used
functions, ones lines `printf` and `getchar`. Now we'll write our own function `power(m, n)` that raises an integer m to
a positive integer power n. As an example `power(2, 5)` is equal to 32. Check out the [power function][power-1.c]:

```c
#include <stdio.h>

int power(int base, int n);

/* test power function */
int main()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; i++)
    {
        p *= base;
    }

    return p;
}
```

Note how we have to declare the prototype before any uses of the function. Also, note how our function returns the value
computed. Not all functions need to or will return a value.

## 1.8 Arguments - Call By Value

In C all function arguments are passed by value. Here is a version of the [power function][power-1.c] that uses the fact
that parameters are conveniently initialized local variables:

```c
/* power: raise base to n-th power; n >= 0; version 2 */
int power(int base, int n)
{
    int p;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```

Any changes made to the parameter n have no effect on the argument that power() was originally called with. If you need
to modify a value in a called function then you must pass the address of a.k.a. a pointer to the value you
wish to change.

Arrays are a different story. When you use the name of an array as an argument, the value passed to the function is the
location/address of the beginning of the array, no array elements are copied. Beware that by subscripting the array
name, the called function can access and alter elements of the array.

## 1.9 Character Arrays

We will often use arrays of characters in C. To illustrate the use of character arrays we'll write a program that reads
a set of text lines and prints the longest. Our pseudocode looks like this:

- While there is another line
  - If the current line is longer than the longest line
    - Save the current line as the longest line
    - Save the length of the current line as the longest line length
- Print the longest line

From the above pseudocode we can see that the program divides naturally into pieces. One piece gets a new line, another
piece saves lines, and another piece controls the whole process. We'll divide the program as follows:

- A `getline` function that fetches users input. It has to return a signal about a possible EOF.
- A `copy` function that saves a line to a safe place.
- A `main` function to control `getline` and `copy`.

Here is the resulting code:

```c
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */

int getline(char line[], int maxLine);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max < 0)    /* there was a line */
    {
        printf("%s", longest);
    }

    return 0;
}

/* getline: read a line into line, returns the length of the line read in */
int getline(char line[], int maxLine)
{
    int c, i;

    for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

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
```

Notice how `main` and `getline` communicate through a pair of arguments and a returned value. On the other hand, `copy`
is used only for its effect and returns no value. We use `void` to state explicitly that no value is returned.

`getline` puts the character '\0' at the end of the array. This character is know as the null terminator and is used to
mark the end of a string of characters. The `%s` format specifier in `printf` expects the corresponding argument to be a
null terminated character array.

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
[counting-more.c]: ./counting-more.c
[power-1.c]: ./power-1.c
[power-2.c]: ./power-2.c
[exercise-solutions]: ./exercises
