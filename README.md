# Learning C Programming 

This is some basic exercises to get familiar with C programming, and notes regarding features in the C programming language.

## Data Types

Data types:
* char - character (or single byte)
* short - short int
* long - long integer 
* double - double-precision floating point

**Note:** you can specify the accuracy (trailing decimals) in printf by using the float number followed by *f* 
ex. `printf("6.1f", 32.423232);`


**Long integer** - int (long integers) are at least 32 bits. On some systems, `int` and `long` are the same size. 

## Methods 

**putchar()**

putchar is a function that writes a single character to the standard output stream.

**Detecting backspace \b**

Apparently, in c program, you can't catch catch '\b' from standard in as it is connected to the 
interactive device (serial terminal or console window).

**Chars in C**

In C, a char is the "smallest addressable unit of machine that can contain basic character set. It is an integer type."

Char is equivalent to "one-byte-long integer", so they can hold values between [0, 255].

To convert a digit's character set to the digit value itself, you can rely on the property of the character sets
that digits are always stored sequentially and increasingly and just subtract by '0' (ASCII eqv - 48).

## Pointers
