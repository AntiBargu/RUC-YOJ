#include <stdio.h>

int main()
{
	int n;
	double price;

	scanf("%lf%d", &price, &n);

	if(n < 2)
		printf("%.2lf\n", price * n);
	else if(n < 3)
		printf("%.2lf\n", price * n * 0.8);
	else if(n < 5)
		printf("%.2lf\n", price * n * 0.7);
	else
		printf("%.2lf\n", price * 5 * 0.7 + price * (n - 5) * 1.1);

	return 0;
}
