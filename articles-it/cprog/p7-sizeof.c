#include <FFOS/std.h>

void main()
{
	fflog("char\t\t%L", sizeof(char));
	fflog("short\t\t%L", sizeof(short));
	fflog("int\t\t%L", sizeof(int));
	fflog("long long\t%L", sizeof(long long));

	fflog("void*\t\t%L", sizeof(void*));

	fflog("float\t\t%L", sizeof(float));
	fflog("double\t\t%L", sizeof(double));
	fflog("long double\t%L", sizeof(long double));
}
