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
