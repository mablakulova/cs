# The C Programming Language

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