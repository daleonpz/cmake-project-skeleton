#include <example/example.h>
#include <stdio.h>

int main(void)
{
	const int expected = 42;
	int val = ret42();

	printf("ret42() returned %d\n", val);
	return (expected != val);
}
