# C syntax with examples: Preprocessor

Contents:

* Includes
* Definitions
* Conditionals
* Default Constants
* Macros

Before a `.c` file is actually compiled into machine code, it gets processed by C preprocessor.
We don't execute the preprocessor binary manually, because it's called automatically by gcc.
With preprocessor directives:

* we include several files into the compilation process, otherwise the compiler doesn't know about the library functions we call
* we set constants and macros
* we choose which code blocks will actually get compiled depending on preprocessor constants


## Includes

We order the compiler to read another file by `#include` directive.

	#include <FFOS/std.h>

The compiler searches for file `FFOS/std.h` in every include directory.
Include directories are set by `-I` command-line parameter to gcc.

We may use `""` for an `#include` directive

	#include "base.h"

It works like with `<>` but also searches for the file in the same directory where our current file lives.

When complex file include trees are used, it's quite possible that several files include the same `.h` file.
Compiler should read and process the same file twice and it will show an error if it detects a name conflict.
To prevent compiler from doing so, we place `#pragma` directive in each `.h` file as the first line:

	#pragma once


## Definitions

We create a new preprocessor constant with `#define`

	#define SUCCESS  0

	int main()
	{
		return SUCCESS;
	}

Preprocessor constants are usually named in uppercase for better readability.

We may undefine it at any time by `#undef`

	#undef SUCCESS


## Conditionals

We check if preprocessor constant or macro is set by `#if defined`

	#define X  123
	#if defined X
		// code will be compiled if `X` is defined
	#endif

or with `#ifdef`

	#define X  123
	#ifdef X
		// code will be compiled if `X` is defined
	#endif

Every `#if` branch ends with `#endif`.

We check if preprocessor constant or macro is not set by `#if !defined`

	#define X  123
	#if !defined X
		// code will be compiled if `X` is not defined
	#endif

or with `#ifndef`

	#define X  123
	#ifndef X
		// code will be compiled if `X` is not defined
	#endif

We use `#else` for branching

	#if defined X
		// code will be compiled if `X` is defined
	#else
		// code will be compiled if `X` is not defined
	#endif

We use `#if` with arithmetic comparison operators `==, !=, <, >, <=, >=` to compare values

	#if X == 123
		// code will be compiled if `X` is 123
	#endif

We use `#elif` for branching with another condition

	#if X == 123
		// code will be compiled if `X` is 123
	#elif X == 321
		// code will be compiled if `X` is 321
	#endif

Or mixing them together

	#if X == 123
		// code will be compiled if `X` is 123
	#elif X == 321
		// code will be compiled if `X` is 321
	#else
		// code will be compiled if none of the above
	#endif


## Default Constants

There are several preprocessor constants defined by gcc that we can use in our code to make decisions about the compiler, CPU and OS.

### Detect compiler

	Name    | Constants
	========|=================================
	clang   | __clang__
	mingw   | __MINGW32__ || __MINGW64__
	gcc     | __GNUC__
	MSVC    | _MSC_VER

### Detect CPU architecture

	Name    | Constants
	========|=================================
	AMD64   | __amd64__ || _M_AMD64
	x86     | __i386__ || _M_IX86
	ARM     | __arm__ || _M_ARM || __aarch64__

### Detect OS

	Name    | Constants
	========|=================================
	Linux   | __linux__
	Android | __linux__ && ANDROID
	macOS   | __APPLE__ && __MACH__
	*BSD    | __unix__ && BSD (defined in sys/param.h)
	Windows | _WIN32 || _WIN64


## Macros

Macros are code blocks inlined into the calling function's code by preprocessor before compilation starts.
We create a new macro with `#define`

	#define ADD(a, b)  ((a) + (b))

	void main()
	{
		int i = ADD(1, 2);
	}

For small and simple operations this almost has the same effect as defining a function.
However, natural functions are better in almost all cases, because preprocessor macros have these disadvantages:

* We have to enclose an arguments in `()` every time we use it.
Failing to do so may produce compilation errors.
* Macros have the same scope as the calling function and may use its local variables implicitly.
This is not obvious to the caller - it can lead to runtime bugs which are hard to find.
* It's hard to debug macros

But macros are important when we need to write a generic function which works the same way for any parameter type.
For example, we can use the above `ADD` macro for parameters of type `double`, not just `int`.

Long lines may be split by using `\` at the end of line:

	#define ADD(a, b) \
		((a) + (b))

### Examples

These are examples where macros are necessary.

Get the number of elements in a static array:

	#define ARRAY_COUNT(a)  (sizeof(a) / sizeof(a[0]))

Get the length of static string:

	#define STR_LENGTH(s)  (ARRAY_COUNT(s) - 1)

Get offset of a structure field:

	#define FIELD_OFFSET(struct_type, field) \
		(((long long)&((struct_type *)0)->field))
