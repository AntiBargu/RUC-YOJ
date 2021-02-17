#include <stdio.h>

int digit_get(int n)
{
	int rslt;

	if(!n)
		return 0;

	for(rslt = 0; n; n /= 10, ++rslt)
		;

	return rslt;
}

int main()
{
	int i, a, b, n, k, m, cnt;

	scanf("%d%d%d%d%d", &a, &b, &n, &k, &m);

	for(i = a, cnt = 0; i <= b; ++i)
		if(i % 10 == n && 0 == i % k && m == digit_get(i))
			++cnt;

	printf("%d\n", cnt);

	return 0;
}
