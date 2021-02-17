#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_cmp(const void *a, const void *b)
{
	if(*(int *)a == *(int *)b)
		return 0;

	return *(int *)a < *(int *)b ? -1 : 1;
}

int main()
{
	int goods[100], common[100], tmp[100];
	int i, j, a, b, n, good_cnt, common_cnt, tmp_cnt;

	scanf("%d", &n);

	for(j = 0, scanf("%d", &common_cnt); j < common_cnt; ++j)
		scanf("%d", &common[j]);

	qsort(common, common_cnt, sizeof(int), int_cmp);

	for(i = 1; i < n; ++i) {
		for(j = 0, scanf("%d", &good_cnt); j < good_cnt; ++j)
			scanf("%d", &goods[j]);

		qsort(goods, good_cnt, sizeof(int), int_cmp);

		for(a = 0, b = 0, tmp_cnt = 0; a < common_cnt && b < good_cnt; ) {
			if(common[a] == goods[b]) {
				tmp[tmp_cnt++] = common[a];
				++a;
				++b;
			}
			else if(common[a] < goods[b])
				++a;
			else
				++b;
		}

		memcpy(common, tmp, tmp_cnt * sizeof(int));
		common_cnt = tmp_cnt;
	}

	if(common_cnt) {
		for(i = 0; i < common_cnt; ++i)
			printf("%d ", common[i]);
	}
	else
		printf("NO");

	printf("\n");

	return 0;
}
