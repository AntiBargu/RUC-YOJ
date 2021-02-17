#include <stdio.h>
#include <math.h>

int main()
{
	double x;

	scanf("%lf", &x);

	if(x < 0)
		printf("%.02lf\n", -x);
	else if(x <= 1)
		printf("%.02lf\n", sqrt(x));
	else
		printf("%.02lf\n", x * x);

	return 0;
}