#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct man {
	int id, nums[8];
	double similarity;
};

int similar_cmp(const void *a, const void *b)
{
	if(fabs(((struct man *)a)->similarity - ((struct man *)b)->similarity) < 1e-10)
		return ((struct man *)b)->id - ((struct man *)a)->id;

	return ((struct man *)b)->similarity - ((struct man *)a)->similarity > 0 ? 1 : -1;
}

int main()
{
	struct man men[100];
	int i, j, n, k, woman_nums[8], sum_a, sum_b, sum_ab;

	scanf("%d%d", &n, &k);

	for(i = 0, sum_a = 0; i < 8; ++i) {
		scanf("%d", &woman_nums[i]);
		sum_a += woman_nums[i] * woman_nums[i];
	}

	for(i = 0; i < n; ++i) {
		scanf("%d", &men[i].id);

		for(j = 0, sum_b = 0, sum_ab = 0; j < 8; ++j) {
			scanf("%d", &men[i].nums[j]);
			sum_b += men[i].nums[j] * men[i].nums[j];
			sum_ab += woman_nums[j] * men[i].nums[j];
		}

		men[i].similarity = sum_ab / (sqrt(sum_a) * sqrt(sum_b));
	}

	qsort(men, n, sizeof(struct man), similar_cmp);

	for(i = 0; i < k; ++i)
		printf("%d ", men[i].id);

	printf("\n");

	return 0;
}
