#include <FFOS/std.h>

void main()
{
	struct {
		long long l;
		int i;
		short s;
		char c;
	} o;
	fflog("sizeof=%L", sizeof(o));
	fflog("l.offset=%L", (long long)&o.l - (long long)&o);
	fflog("i.offset=%L", (long long)&o.i - (long long)&o);
	fflog("s.offset=%L", (long long)&o.s - (long long)&o);
	fflog("c.offset=%L", (long long)&o.c - (long long)&o);
}
