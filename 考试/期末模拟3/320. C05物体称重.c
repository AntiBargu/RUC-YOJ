#include <stdio.h>
#include <stdlib.h>

struct weight {
	int weight, cnt;
};

int n, combins[10][10000];

int combin_cmp(const void *a, const void *b)
{
	if(combins[n - 1][*(int *)a] == combins[n - 1][*(int *)b])
		return *(int *)a - *(int *)b;

	return combins[n - 1][*(int *)b] - combins[n - 1][*(int *)a];
}

int main()
{
	struct weight weights[10];
	int i, j, times, m, total, indices[10000];

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; ++i)
		scanf("%d", &weights[i].weight);

	for(i = 0; i < n; ++i)
		scanf("%d", &weights[i].cnt);

	for(i = 0; i < m; ++i)
		scanf("%d", &indices[i]);

	for(times = 0; times <= weights[0].cnt; ++times)
		combins[0][times * weights[0].weight] = 1;

	for(i = 1, total = weights[0].cnt * weights[0].weight; i < n; total += weights[i].cnt * weights[i].weight, ++i)
		for(j = 0; j <= total; ++j)
			for(times = 0; times <= weights[i].cnt && j + times * weights[i].weight < 10000; ++times)
					combins[i][j + times * weights[i].weight] += combins[i - 1][j];

	qsort(indices, m, sizeof(int), combin_cmp);

	for(i = 0; i < m; ++i)
		printf("%d:%d\n", indices[i], combins[n - 1][indices[i]]);

	return 0;
}
