#include <string.h>
#include <unistd.h>
#include <stdio.h>

void do_something(char* p, int x)
{
	printf("p is %s and x is %d\n", p, x);
}

int main()
{
	printf("Hello, world!\n");

	char* h = "Hello";
	char* w = "world!";

	printf("%s, %s\n", h, w);

	do_something("random", 15);
	do_something("xyz", 25);
	do_something("kenyér", 50);

	return 0;
}