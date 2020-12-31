#include <stdio.h>

int main()
{
	int day;
	const char *strs[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

	scanf("%d", &day);
	printf("%s\n", strs[(day - 1) % 7]);

	return 0;
}
