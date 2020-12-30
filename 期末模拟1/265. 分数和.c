#include <stdio.h>

int gcd(int m, int n)
{
	if(0 == m % n)
		return n;

	return gcd(n, m % n);
}

int main()
{
	int m1, n1, m2, n2, r1, r2, c;

	scanf("%d%d%d%d", &m1, &n1, &m2, &n2);

	r1 = m1 * n2 + m2 * n1;
	r2 = n1 * n2;

	c = gcd(r1, r2);

	printf("%d/%d\n", r1 / c, r2 / c);

	return 0;
}
