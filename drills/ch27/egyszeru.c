#include <stdio.h>
#include <unistd.h>
#include <string.h>

void vegtelen()
{
	int x;
	while(5!=1)
	{
		x = 0;
	}
}

int main()
{
	// Végtelen ciklus
	//vegtelen();

	// Csere
	int a = 4;
	int b = 3;
	printf("%d, %d", a, b);

	int temp = a;
	a = b;
	b = temp;
	printf("\n%d, %d\n", a, b);

	// Szóhossz
	char str[13] = "Csaladipotlek";
	//char* sz = str[strlen(str)-1];
	printf("%ld\n", strlen(str));

	return 0;
}