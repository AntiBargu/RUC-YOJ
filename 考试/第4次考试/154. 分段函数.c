#include <stdio.h>
#include <math.h>

int main()
{
	double x;

	scanf("%lf", &x);

	if(x < 0)
		printf("%.2lf\n", -x);
	else if(x <= 1)
		printf("%.2lf\n", sqrt(x));
	else
		printf("%.2lf\n", x * x);

	return 0;
}
