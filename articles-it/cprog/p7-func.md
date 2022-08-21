# C syntax with examples: Functions

Contents:

* Output value
* Return with `goto`
* Input parameters
* Array as function parameter
* Array as function return value
* Variable arguments
* Visibility
* Scope problem

Instead of copying a block of code each time we want to do something similar, we move this block of code into a separate function which has a unique name, return value and a set of parameters.

	void f() {} // definition
	void main()
	{
		f(); // call
	}

We must first declare or define a function before being able to call it.

	void main()
	{
		f(); // call -- INCORRECT
	}
	void f() {} // definition

When we want to call a function which is defined below the point of calling, we use function declaration.

	void f(); // declaration
	void main()
	{
		f(); // call
	}
	void f() {} // definition


## Output value

Functions can return values using `return` keyword:

	int f()
	{
		return 123;
	}
	void main()
	{
		int i = f();
		// now `i` has value 123
	}

We may `return` from function at any time.


## Return with `goto`

`goto` helps when there are several points in our function we must return from.

	int f()
	{
		int i = -1;
		...
		if (...)
			goto end;
		...
		i = 0;

	end:
		return i;
	}

	void main()
	{
		int i = f();
	}


## Input parameters

Functions can accept input parameters.

	int add(int a, int b)
	{
		return a + b;
	}
	void c()
	{
		int i = add(1, 2);
		// now `i` has value 3
	}

Parameters may be used as input and output when passed as pointers.

	void add_to(int *a, int b)
	{
		*a += b;
	}
	void c()
	{
		int i = 1;
		add_to(&i, 2);
		// now `i` has value 3
	}


## Variable arguments

We use variable arguments when we want our function to accept different amount of parameters, or parameters of different types.
This program defines the function which sums up all input parameters and returns the result.
Note that first function parameter contains the number of arguments after it - otherwise we don't know where to stop reading parameters.

	#include <FFOS/std.h>

	int multi_add(int nargs, ...)
	{
		int sum = 0;
		va_list va;
		va_start(va, nargs);
		for (int i = 0;  i != nargs;  i++) {
			sum += va_arg(va, int);
		}
		va_end(va);
		return sum;
	}

	void main()
	{
		int i = multi_add(3, 1, 2, 3);
		fflog("i=%d", i);
	}


## Array as function parameter

Arrays are accepted as function parameters using pointers along with the number of array elements.
By using constant pointer we explicitly say that the array data won't be modified by this function.

This program sums up the values in array and returns the result.

	#include <FFOS/std.h>

	int array_sum(int n, const int *array)
	{
		int sum = 0;
		for (int i = 0;  i != n;  i++) {
			sum += array[i];
		}
		return sum;
	}

	void main()
	{
		int a[] = { 1, 2, 3 };
		int i = array_sum(3, a);
		fflog("i=%d", i);
	}


## Array as function return value

We can't just return arrays from functions as we do with `int` because array data can't fit into CPU register.
There are 2 ways of doing it:
* The function itself allocates memory for array data and returns the array via structure object or function output parameter:

		struct array f()
		{
			struct array a;
			a.ptr = ...; // allocate memory
			// fill in `a`
			a.len = ...;
			return a;
		}

However, C alone can't allocate more memory, we need to ask OS to do that and it's not in scope of this document.

* The caller allocates memory for array data and uses it as function input/output parameter.

		int f(int *a, int cap)
		{
			// fill in `a`
			return ...; // return array length
		}
		void main()
		{
			int a[100];
			int n = f(a, 100);
		}


## Visibility

Define a locally visible function which can be called only within the same `.c` file

	static void f() {}

Compilers usually warn about unused static functions - we either forgot to call it or we don't need it and should delete it.
But if it's a library function, we can't just delete it - we mark it with `inline`.
Define a locally visible function which will be silently ignored by compiler when not used

	static inline void f() {}

Define a globally visible function which means that this function can be called from another `.c` file

	void f() {}

This function may be called by another `.c` file if declared:

	extern void f();


## Scope problem

A function can't nest another function and all functions are in global scope (or namespace).
This leads to a little problem with function naming - they must be unique.
A locally visible function can't have the same name as any other function declared before it - compiler shows an error in this case.
A globally visible function can't have the same name as another global function defined in another `.c` file - linker shows an error in this case.

Usually, every library we use in C has its own almost unique prefix for all its functions.
For example, all public functions defined by ffbase have `ff` prefix.
It guarantees that unless we also use `ff` prefix to name our own functions, ffbase won't be guilty of name conflicts in our code.

However, OS and libc symbols are the exception - they are named without any particular prefix.
This means that thousands of plain names are reserved by them and we should be careful when writing cross-platform code because it may not compile due to a sudden name conflict.

The same scope rules apply to global variables, preprocessor constants/definitions and macros.
