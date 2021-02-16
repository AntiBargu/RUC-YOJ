#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, q;

	scanf("%lf%lf%lf", &a, &b, &c);

	q = (a + b + c) / 2;

	printf("%.2lf\n", sqrt(q * (q - a) * (q - b) * (q - c)));

	return 0;
}
