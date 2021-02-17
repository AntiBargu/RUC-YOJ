#include <stdio.h>
#include <limits.h>

struct interval {
	int val;
	double rate;
};

int main()
{
	double bonus;
	int i, n, profit;
	struct interval intervals[102] = {{0}};

	scanf("%d", &n);

	for(i = 1; i <= n; ++i)
		scanf("%d%lf", &intervals[i].val, &intervals[i].rate);

	intervals[n].val = INT_MAX;

	scanf("%d", &profit);

	if(profit < 0) {
		printf("NO\n");

		return 0;
	}

	for(i = 1, bonus = 0; i <= n; ++i)
		if(profit < intervals[i].val) {
			bonus += (profit - intervals[i - 1].val) * intervals[i].rate;
			break;
		}
		else
			bonus += (intervals[i].val - intervals[i -1].val) * intervals[i].rate;

	printf("%.02lf\n", bonus);

	return 0;
}