#include <FFOS/std.h>

void main()
{
	char s[] = { 's', 't', 'r' };
	fflog("size of s=%d", sizeof(s));

	char s2[] = { "str" };
	fflog("size of s2=%d", sizeof(s2));

	fflog("size of str=%d", sizeof("str"));

	const char* p = "str";
	fflog("size of p=%d", sizeof(p));
}
