#include <FFOS/std.h>

void main(int arg_total, char** args)
{
	for (int i = 1;  ;  i++) { // bad code
		fflogz(args[i]);
	}
}
