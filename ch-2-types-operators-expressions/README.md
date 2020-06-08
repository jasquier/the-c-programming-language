# Chapter 2: Types, Operators, and Expressions

In programming, variables and constants are two of the most important "things"
we use. We declare the variables to be used and specify their types. A
variables' type determines the values it can have and the operations that can be
performed on it. Operators allow us to combine variables (and other things) into
expressions. Expressions produce new values. These are the basic building blocks
of programming.

## 2.1 Variable Names

Variable names must begin with a letter and can only contain letters, numbers,
and underscores. Keep in mind that uppercase and lowercase letters are distinct,
so `x` and `X` are two different variables. Traditionally in C we use lowercase
for variable names and uppercase for symbolic constants.

## 2.2 Data Types and Sizes

We have only a few basic types available to us in C

- `char`: a single byte
- `int`: an integer, often 32 bits
- `float`: single precision floating point
- `double`: double precision floating point

In addition, we can add various qualifiers to some of the basic types. An `int`
can be `short` or `long`. The only rules enforced upon these qualifiers is that
the size of a `short` <= 16 bits <= size of an `int` <= 32 bits <= size of a
`long`. The qualifiers `signed` or `unsigned` may be applied to `char` or any
`int`. Be aware that `unsigned` numbers are always positive or zero. Lastly,
`long` may be used with `double` to create an extended precision floating point.

## 2.3 Constants

## 2.4 Declarations

## 2.5 Arithmetic Operators

## 2.6 Relational and Logical Operators

## 2.7 Type Conversions

## 2.8 Increment and Decrement Operators

## 2.9 Bitwise Operators

## 2.10 Assignment Operators and Expressions

## 2.11 Conditional Expressions

## 2.12 Precedence and Order of Evaluation

---

Don't forget to check out the [exercise solutions][exercise-solutions].

[exercise-solutions]: ./exercises
