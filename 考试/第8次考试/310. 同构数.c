#include <stdio.h>

int main()
{
	int i, a, b, sum;

	scanf("%d%d", &a, &b);

	for(i = a, sum = 0; i <= b; ++i) {
		if(i < 10) {
			if(i * i % 10 == i)
				sum += i;
		} 

		else if(i < 100) {
			if(i * i % 100 == i)
				sum += i;
		}

		else if(i < 1000) {
			if(i * i % 1000 == i)
				sum += i;
		}

		else
			if(i * i % 10000 == i)
				sum += i;
	}

	printf("%d\n", sum);

	return 0;
}