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
