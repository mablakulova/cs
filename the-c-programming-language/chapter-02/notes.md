# The C Programming Language

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
- A `character constant` is an integer, written as one charater within single quotes, such as 'x'.
- A `string constant` is a sequence of zero or more characters surrounded by double quotes. String constants can be concatenated at compile time.
- `Enumeration constant` is a list of constant integer values.

### 2.4 Declarations
- The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed.

### 2.5 Arithmetic Operators
- The `%` (modulus) operator cannot be applied to `float` or `double`.

### 2.6 Relational and Logical Operators
- Relational operators (>, >=, <, <=) have lower precedence than arithmetic operators, i < lim - 1 is taken as i < (lim - 1).
- In logical operators (||, &&) expressions are evaluated left to right, and evaluation stops as soon as the truth or falsehood of the result is known.
- The unary negation operator (!) converts a non-zero operand into 0, and a zero operand into 1.

### 2.7 Type Conversions
- The only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information, such as int to float.
- Expressions that might lose information (long to short, float to int) may draw a warning, but they are not illegal.
- The `<ctype.h>` provides tests and conversions that are independent of character set (tolower(), isdigit()).
- For portability, specify signed or unsigned if non-character data is to be stored in char variables.
- Explicit type conversions can be forced with a unary operator called a `cast`.

### 2.8 Increment and Decrement Operators
- `++n` increments n before its value is used, while `n++` increments n after its value has been used.
- The increment and decrement operators can be applied to variables, an expression like (i+j)++ is illegal.

### 2.9 Bitwise Operators
- The Boolean operation `~` corresponds to the logical operation NOT, denoted by the symbol `¬`. `¬P` is true when P is not true, and vice versa. Correspondingly, ~p equals 1 when p equals 0, and vice versa.
- `&` corresponds to the logical operation AND, denoted by the symbol `∧`. `P∧Q` holds when both P and Q is true. p & q equals 1 only when p = 1 and q = 1.
- `|` corresponds to the logical operation OR, denoted by the symbol `∨`. `P∨Q` holds when either P or Q is true. p | q equals 1 when either p = 1 or q = 1.
- `^` corresponds to the logical operation EXCLUSIVE-OR, denoted by the symbol `⊕`. `P⊕Q` holds when either P or Q is true, but not both. p ^ q equals 1 when either p = 1 and q = 0, or p = 0 and q = 1.
- For an operand x having bit representation [x(w-1), x(w-2), ..., x(0)], the expression `x << k` yields a value with bit representation [x(w-k-1), x(w-k-2), ..., x(0), 0 ..., 0]. x is shifted k bits to the left, dropping off the k most significant bits and filling the right end with k zeros.
- Shift operations associate from left to right, so `x << j << k` is equivalent to `(x << j) << k`.
- A logical right shift fills the left end with k zeros, giving a result [0, ..., 0, x(w-1), x(w-2), ...x(k)].
- An arithmetic right shift fills the left end with k repetitions of the most significant bit, giving a result [x(w-1), ..., x(w-1), x(w-1), x(w-2), ...x(k)].
- Use arithmetic right shifts for signed data, and for unsigned data, right shifts must be logical.

### 2.10 Assignment Operators and Expressions
- Assignment operators: i += 2, i -= 2, (+, -, *, /, %, <<, >>, &, ^, |).
- In all assignment expressions, the type of an assignment expression is the type of its left operand, and the value is the value after the assignment.

### 2.11 Conditional Expressions
- The `conditional expression`, written with the ternary operator "?:", provides an alternative way to write if/else and similar constructions.

### 2.12 Precedence and Order of Evaluation
- The precedence of the bitwise operators &, ^, and | falls below `==` and `!=`. This implies that bit-testing expressions like `if ((x & MASK) == 0) ...` must be fully parenthesized to give proper results.