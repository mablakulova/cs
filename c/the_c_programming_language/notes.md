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
- A `#define` line defines a symbolic name or symbolic constant to be a particular string of characters: `#define name replacement text`
- Any occurrence of *name* (not in quotes and not part of another name) will be replaced by the corresponding *replacement text*. The *name* has the same form as a variable name: a sequence of letters and digits that begins with a letter. The *replacement text* can be any sequence of characters; it is not limited to numbers.
- Notice that there is no semicolon at the end of a `#define` line.
### 1.5 Character Input and Output
- A *text stream* is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character.
- It is the responsibility of the library to make each input or output stream conform to this model; the C programmer using the library need not worry about how lines are represented outside the program.
- Each time it is called, `getchar` reads the *next input character* from a text stream and returns that as its value. That is, after `c = getchar()` the variable `c` contains the next character of input.
- The function `putchar` prints a character each time it is called: `putchar(c)` prints the contents of the integer variable `c` as a character, usually on the screen.
#### 1.5.1 File Copying
- We must declare `c` to be a type big enough to hold any value that `getchar` returns. We can't use `char` since `c` must be big enough to hold `EOF` in addition to any possible char. Therefore we use `int`.
- `EOF` is an integer defined in `<stdio.h>`, but the specific numeric value doesn't matter as long as it is not the same as any `char` value.
- The *precedence* of `!=` is higher than that of `=`.
#### 1.5.2 Character Counting
- But the grammatical rules of C require that a `for` statement have a body. The isolated semicolon, called a *null statement*, is there to satisfy that requirement.
#### 1.5.3 Line Counting
- A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called a *character constant*, although it is just another way to write a small integer.
#### 1.5.4 Word Counting
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
- Function definitions can appear in any order, and in one source file or several, although no function can be split between files.
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
## Chapter 2: Types, Operators, and Expressions
### 2.1 Variable Names
- Don't begin variable names with underscore, however, since library routines often use such names.
- Upper case and lower case letters are distinct, so `x` and `X` are two different names. Traditional C practice is to use lower case for variable names, and all upper case for symbolic constants.
- Keywords like if, else, int, float, etc., are reserved: you can't use them as variable names. They must be in lower case.  
### 2.2 Data Types and Sizes
- There are only a few basic data types in C: char, int, float, double.
- `short` and `long` apply to integers. shorts and ints are at least 16 bits, longs are at least 32 bits, and short is no longer than int, which is no longer than long.
- `signed` or `unsigned` may be applied to char or any integer.
- `long double` specifies extended-precision floating point.
- `<limits.h>` and `<float.h>` contain symbolic constants for all of data type sizes, along with other properties of the machine and compiler.
### 2.3 Constants
- A `long` constant is written with a terminal `l` or `L`, `unsigned` constants with a terminal `u` or `U`, and the suffix `ul` or `UL` indicates `unsigned long`.
- The suffixes `f` or `F` indicate a `float` constant; `l` or `L` indicate a `long double`.
- A leading `0` (zero) on an integer constant means octal; a leading `0x` or `0X` means hexadecimal. Octal and hexadecimal constants may also be followed by `L` to make them `long` and `U` to make them `unsigned`.
- A *character constant* is an integer, written as one charater within single quotes, such as 'x'. The value of a character constant is the numeric value of the character in the machine's character set.
- An arbitrary byte-sized bit pattern can be specified by `'\000'` where 000 is one to three octal digits (0...7) or by `'\xhh'` where hh is one or more hexadecimal digits (0...9, a...f, A...F).
- A *constant expression* is an expression that involves only constants. Such expressions may be evaluated during compilation rather than run-time.
- A *string constant* is a sequence of zero or more characters surrounded by double quotes. String constants can be concatenated at compile time.
- The standard library function `strlen(s)` returns the length of its character string argument *s*, excluding the terminal `'\0'`.
- *Enumeration constant* is a list of constant integer values.
- Although variables of enum types may be declared, compilers need not check that what you store in such a variable is a valid value for the enumeration.
### 2.4 Declarations
- The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed.
### 2.5 Arithmetic Operators
- The `%` (modulus) operator cannot be applied to `float` or `double`.
### 2.6 Relational and Logical Operators
- Relational operators (>, >=, <, <=) have lower precedence than arithmetic operators, `i < lim - 1` is taken as `i < (lim - 1)`.
- Expressions connected by `&&` or `||` are evaluated left to right, and evaluation stops as soon as the truth or falsehood of the result is known.
- The precedence of `&&` is higher than that of `||`, and both are lower than relational (>, >=, <, <=) and equality operators (==, !=).
- The unary negation operator (!) converts a non-zero operand into 0, and a zero operand into 1.
### 2.7 Type Conversions
- The only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information, such as int to float.
- Expressions that might lose information, like assigning a longer integer type to a shorter, or a floating-point type to an integer, may draw a warning, but they are not illegal.
- The `<ctype.h>` provides tests and conversions that are independent of character set (`tolower()`, `isdigit()`).
- For portability, specify signed or unsigned if non-character data is to be stored in char variables.
- Functions like `isdigit` may return any non-zero value for *true*. In the test part of `if`, `while`, `for`, etc., "true" just means "non-zero," so this makes no difference.
- In general, if an operator like `+` or `*` that takes two operands (a binary operator) has operands of different types, the "lower" type is promoted to the "higher" type before the operation proceeds. The result is of the higher type.
- The main reason for using `float` is to save storage in large arrays, or, less often, to save time on machines where *double-precision* arithmetic is particularly expensive.
- The problem is that comparisons between signed and unsigned values are machine-dependent, because they depend on the sizes of the various integer types.
- Since an argument of a function call is an expression, type conversions also take place when arguments are passed to functions.
- Explicit type conversions can be forced ("coerced") in any expression, with a unary operator called a *cast*.
### 2.8 Increment and Decrement Operators
- The expression `++n` (prefix) increments n *before* its value is used, while `n++` (postfix) increments n *after* its value has been used.
- The increment and decrement operators can be applied to variables, an expression like `(i+j)++` is illegal.
### 2.9 Bitwise Operators
- The Boolean operation `~` corresponds to the logical operation NOT, denoted by the symbol `¬`. `¬P` is true when P is not true, and vice versa. Correspondingly, ~p equals 1 when p equals 0, and vice versa.
- `&` corresponds to the logical operation AND, denoted by the symbol `∧`. `P∧Q` holds when both P and Q is true. p & q equals 1 only when p = 1 and q = 1.
- `|` corresponds to the logical operation OR, denoted by the symbol `∨`. `P∨Q` holds when either P or Q is true. p | q equals 1 when either p = 1 or q = 1.
- `^` corresponds to the logical operation EXCLUSIVE-OR, denoted by the symbol `⊕`. `P⊕Q` holds when either P or Q is true, but not both. p ^ q equals 1 when either p = 1 and q = 0, or p = 0 and q = 1.
- For an operand x having bit representation [x(w-1), x(w-2), ..., x(0)], the expression `x << k` yields a value with bit representation [x(w-k-1), x(w-k-2), ..., x(0), 0 ..., 0]. x is shifted k bits to the left, dropping off the k most significant bits and filling the right end with k zeros.
- Shift operations associate from left to right, so `x << j << k` is equivalent to `(x << j) << k`.
- Machines support two forms of right shift: *logical* and *arithmetic*.
- A *logical right shift* fills the left end with k zeros, giving a result [0, ..., 0, x(w-1), x(w-2), ...x(k)].
- An *arithmetic right shift* fills the left end with k repetitions of the most significant bit, giving a result [x(w-1), ..., x(w-1), x(w-1), x(w-2), ...x(k)].
- Use *arithmetic right shifts* for signed data, and for unsigned data, right shifts must be *logical*.
### 2.10 Assignment Operators and Expressions
- Assignment operators: i += 2, i -= 2, (+, -, *, /, %, <<, >>, &, ^, |).
- In all assignment expressions, the type of an assignment expression is the type of its left operand, and the value is the value after the assignment.
### 2.11 Conditional Expressions
- The `conditional expression`, written with the ternary operator "?:", provides an alternative way to write if/else and similar constructions.
### 2.12 Precedence and Order of Evaluation
- The precedence of the bitwise operators &, ^, and | falls below `==` and `!=`. This implies that bit-testing expressions like `if ((x & MASK) == 0) ...` must be fully parenthesized to give proper results.
## Chapter 3 Control Flow
### 3.1 Statements and Blocks
- An expression such as x = 0 or i++ or printf(...) becomes a `statement` when it is followed by a semicolon.
- In C, the semicolon(,) is a statement terminator.
- Braces ({}) are used to group declarations and statements together into a compound statement, or block, so that they are syntactically equivalent to a single statement.
### 3.2 If-Else
- It's a good idea to use braces when there are nested `if`s.
### 3.3 Else-If
- The last `else` part handles the "none of the above" or default case where none of the other conditions are satisfied. 
- Sometimes there is no explicit action for the default; in that case the trailing else statement can be omitted, or it may be used for error checking to catch an "impossible" condition.
### 3.4 Switch
- The case labeled `default` is executed if none of the other cases are satisfied. 
- A `default` is optional; if it isn't there and if none of the cases match, no action at all takes place.
- The `break` statement causes an immediate exit from the `switch`. Because cases serve just as labels, after the code for one case is done, execution falls through to the next unless you take explicit action to escape.
- As a matter of good form, put a `break` after the last case (the `default` here) even though it's logically unnecessary.
### 3.5 Loops - While and For
- The `for` statement is equivalent to `while` except for the behavior of `continue`.
  ```c
  for (expr1; expr2; expr3)
    statement

  expr1;
  while (expr2) {
    statement
    expr3;
  }
  ```
- Any of the three expressions part of the `for` loop can be omitted, although the semicolons must remain.
- The `while` is most natural for loops when there is no initialization or re-initialization.
- The `for` is preferable when there is a simple initialization and increment, since it keeps the loop control statements close together and visible at the top of the loop.
- A pair of expressions separated by a comma is evaluated left to right, and the type and value of the result are the type and value of the right operand.
### 3.6 Loops - Do-while
- By contrast, the third loop in C, the `do-while`, tests at the bottom after making each pass through the loop body; the body is always executed at least once.
### 3.7 Break and Continue
- The `break` statement provides an early exit from `for`, `while`, and `do`, just as from `switch`. A `break` causes the innermost enclosing loop or `switch` to be exited immediately.
- The `continue` statement causes the next iteration of the enclosing `for`, `while`, or `do loop` to begin.
- The `continue` statement applies only to loops, not to `switch`. A `continue` inside a `switch` inside a loop causes the next loop iteration.
### 3.8 Goto and Labels
- C provides the infinitely-abusable `goto` statement, and `labels` to branch to.
- The common use-case of `goto` is to abandon processing in some deeply nested structure, such as breaking out of two or more loops at once. The `break` statement cannot be used directly since it only exits from the `innermost loop`.
  ```c
  for ( ... ) 
      for ( ... ) {
          ...
          if (disaster)
             goto error;
      }
   ...

   error:
      clean up the mess
  ```
- A `label` has the same form as a variable name, and is followed by a colon.