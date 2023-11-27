#include <stdio.h>
#include <string.h>
int main(void)
{
	printf("%p", "");
	printf("%d\n", printf("%p", ""));
	return (0);
}