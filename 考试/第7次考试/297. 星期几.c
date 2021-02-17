#include <stdio.h>

int main()
{
	int d1, d2;
	const char *strs[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	scanf("%d%d", &d1, &d2);
	printf("%s\n%s\n", strs[(d1 + 1) % 7], strs[(d2 + 6) % 7]);

	return 0;
}
