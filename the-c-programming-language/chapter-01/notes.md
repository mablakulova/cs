# The C Programming Language

## Preface
The computing world has undergone a revolution since the publication of *The C Programming Language* in 1978.

In 1983, the American National Standards Institute (ANSI) established a committee whose goal was to produce "an unambiguous and machine-independent definition of the language C", while still retaining its spirit. The result is the ANSI standard for C.

## Preface to the First Edition
C was originally designed for and implemented on the UNIX operating system on the DEC PDP-11, by Dennis Ritchie. The operating system, the C compiler, and essentially all UNIX applications programs (including all of the software used to prepare this book) are written in C.

Besides showing how to make effective use of the language, we have also tried where possible to illustrate useful algorithms and principles of good style and sound design.

## Introduction
Many of the important ideas of C stem from the language BCPL, developed by Martin Richards. The influence of BCPL on C proceeded indirectly through the language B, which was written by Ken Thompson in 1970 for the first UNIX system on the DEC PDP-7.

C is a relatively "low level" language. This characterization is not pejorative; it simply means that C deals with the same sort of objects that most computers do, namely characters, numbers, and addresses.

Nevertheless, C retains the basic philosophy that programmers know what they are doing; it only requires that they state their intentions explicitly.

## Chapter 1: A Tutorial Introduction

### 1.1 Getting Started
- A C program, whatever its size, consists of *functions* and *variables*. A function contains *statements* that specify the computing operations to be done, and variables store values used during the computation.
- Normally you are at liberty to give functions whatever names you like, but "main" is special-your program begins executing at the beginning of main. This means that every program must have a *main* somewhere.
- `#include <stdio.h>` tells the compiler to include information about the standard input/output library.
- One method of communicating data between functions is for the calling function to provide a list of values, called *arguments*, to the function it calls.
- A sequence of characters in double quotes, like "hello, world\n", is called a *character string* or *string constant*.
- The sequence `\n` in the string is C notation for the *newline character*, which when printed advances the output to the left margin on the next line.
- `\n` represents only a single character. An *escape sequence* like `\n` provides a general and extensible mechanism for representing hard-to-type or invisible characters. Among the others that C provides are `\t` for tab, `\b` for backspace, `\"` for the double quote, and `\\` for the backslash itself.

### 1.2 Variables and Arithmetic Expressions
- Any characters between /* and */ are ignored by the compiler; they may be used freely to make a program easier to understand.
- A *declaration* announces the properties of variables; it consists of a type name and a list of variables.
- The type `int` means that the variables listed are integers, by contrast with `float`, which means floating point, i.e., numbers that may have a fractional part.
- `char` - character-a single byte; `short` - short integer; `long` - long integer; `double` - double-precision floating point.
- The `printf` conversion specification `%3.0f` says that a floating-point number is to be printed at least three characters wide, with no decimal point and no fraction digits. `%6.1f` describes another number that is to be printed at least six characters wide, with 1 digit after the decimal point.
- `printf` recognizes `%d` for decimal integer, `%f` for floating point, `%o` for octal, `%x` for hexadecimal, `%c` for character, `%s` for character string, and `%%` for % itself.

### 1.3 The For Statement
- The `for` statement is a loop, a generalization of the `while`.
- The choice between `while` and `for` is arbitrary, based on which seems clearer. The `for` is usually appropriate for loops in which the initialization aud increment are single statements and logically related, since it is more compact than `while` and it keeps the loop control statements together in one place.

### 1.4 Symbolic Constants
- A `#define` line defines a symbolic name or symbolic constant to be a particular string of characters: `#define  name  replacement text`
- Any occurrence of *name* (not in quotes and not part of another name) will be replaced by the corresponding *replacement text*. The *name* has the same form as a variable name: a sequence of letters and digits that begins with a letter. The *replacement text* can be any sequence of characters; it is not limited to numbers.
- Notice that there is no semicolon at the end of a `#define` line.

### 1.5 Character Input and Output
- A *text stream* is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character. 
- It is the responsibility of the library to make each input or output stream conform to this model; the C programmer using the library need not worry about how lines are represented outside the program.
- Each time it is called, `getchar` reads the *next input character* from a text stream and returns that as its value. That is, after `c = getchar()` the variable `c` contains the next character of input.
- The function `putchar` prints a character each time it is called: `putchar(c)`
prints the contents of the integer variable `c` as a character, usually on the
screen.

### 1.5.1 File Copying
- We must declare `c` to be a type big enough to hold any value that `getchar` returns. We can't use `char` since `c` must be big enough to hold `EOF` in addition to any possible char. Therefore we use `int`.
- `EOF` is an integer defined in `<stdio.h>`, but the specific numeric value doesn't matter as long as it is not the same as any `char` value.
- The *precedence* of `!=` is higher than that of `=`.

### 1.5.2 Character Counting
- But the grammatical rules of C require that a `for` statement have a body. The isolated semicolon, called a *null statement*, is there to satisfy that requirement.

### 1.5.3 Line Counting
- A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called a *character constant*, although it is just another way to write a small integer.

### 1.5.4 Word Counting
- There is a corresponding operator `&&` for *AND*; its precedence is just higher than ||.
- Expressions connected by `&&` or `||` are evaluated left to right, and it is guaranteed that evaluation will stop as soon as the truth or falsehood is known.

### 1.6 Arrays
- Array subscripts always start at zero in C.

### 1.7 Functions
- A function definition has this form:
  ```
  return-type function-name (parameter declarations, if any)
  {
      declarations
      statements
  } 
  ```
- Function definitions can appear in any order, and in one source file or several,
although no function can be split between files.
- We will generally use *parameter* for a variable named in the parenthesized list in a function definition, and *argument* for the value used in a call of the function. The terms *formal argument* and *actual argument* are sometimes used for the same distinction.
- A function need not return a value; a *return* statement with no expression causes control, but no useful value, to be returned to the caller, as does "falling off the end" of a function by reaching the terminating right brace.

### 1.8 Arguments-Call by Value
- In C, all function arguments are passed "by value."
- When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the *address* of the variable to be set (technically a *pointer* to the variable), and the called function must declare the parameter to be a pointer and access the variable indirectly through it.

### 1.9 Character Arrays
- ..or zero if end of file is encountered. Zero is an acceptable end-of-file return because it is never a valid line length. Every text line has at least one character; even a line containing only a newline has length 1.
- `getline` puts the character `'\0'` (the *null character*, whose value is zero) at the end of the array it is creating, to mark the end of the string of characters. This convention is also used by the C language.

### 1.10 External Variables and Scope
- Each local variable in a function comes into existence only when the function is called, and disappears when the function is exited. This is why such variables are usually known as *automatic* variables, following terminology in other languages.
- Because automatic variables come and go with function invocation, they do not retain their values from one call to the next, and must be explicitly set upon each entry. If they are not set, they will contain garbage.
- Furthermore, because external variables remain in existence permanently, rather than appearing and disappearing as functions are called and exited, they retain their values even after the functions that set them have returned.
- An external variable must be *defined*, exactly once, outside of any function; this sets aside storage for it. The variable must also be *declared* in each function that wants to access it; this states the type of the variable. The declaration may be an explicit *extern* statement or may be implicit from context.
- If the program is in several source files, and a variable is defined in *file1* and used in *file2* and *file3*, then *extern* declarations are needed in *file2* and *file3* to connect the occurrences of the variable. The usual practice is to collect extern declarations of variables and functions in a separate file, historically called a *header*, that is included by `#include` at the front of each source file. The suffix `.h` is conventional for header names.
- But for compatibility with older C programs the standard takes an empty list as an old-style declaration, and turns off all argument list checking; the word *void* must be used for an explicitly empty list.
- "Definition" refers to the place where the variable is created or assigned storage; "declaration" refers to places where the nature of the variable is stated but no storage is allocated.