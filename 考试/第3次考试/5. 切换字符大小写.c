#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;

	ch = getchar();

	if(isupper(ch))
		putchar(ch + 32);
	else
		putchar(ch - 32);

	return 0;
}
