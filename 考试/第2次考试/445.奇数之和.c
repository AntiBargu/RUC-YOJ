#include <stdio.h>

int main()
{
	int i, a, b, sum;

	scanf("%d,%d", &a, &b);

	for(i = a + 1, sum = 0; i < b; ++i)
		if(i & 1)
			sum += i;

	printf("%d\n", sum);

	return 0;
}
