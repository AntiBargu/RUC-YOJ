#include <stdio.h>

int gcd(int m, int n)
{
	if(0 == m % n)
		return n;

	return gcd(n, m % n);
}

int main()
{
	int m, n, c;

	scanf("%d/%d", &m, &n);

	c = gcd(m, n);

	printf("%d/%d\n", m / c, n / c);

	return 0;
}
