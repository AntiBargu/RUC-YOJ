#include <stdio.h>

int main()
{
	int num, cnt;

	scanf("%d", &num);

	if(0 == num) {
		printf("0,1\n");
		return 0;
	}

	for(cnt = 0; num; ++cnt, num /= 10)
		printf("%d,", num % 10);

	printf("%d\n", cnt);

	return 0;
}
