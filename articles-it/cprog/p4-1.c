#include <FFOS/std.h>

void main(int arg_total, char** args)
{
	for (int i = 1;  i < arg_total;  i++) {
		fflogz(args[i]);
	}
}
