#include <stdio.h>
#include <stdlib.h>

struct stu {
	int id, pass_cnt;
};

int stu_cmp(const void *a, const void *b)
{
	if(((struct stu *)a)->pass_cnt == ((struct stu *)b)->pass_cnt)
		return ((struct stu *)a)->id - ((struct stu *)b)->id;

	return ((struct stu *)b)->pass_cnt - ((struct stu *)a)->pass_cnt;
}

int main()
{
	struct stu stus[100] = {{0}};
	int i, j, k, m, n, finish_cnt, finish_num, homework_num, homeworks[10000] = {0};

	for(i = 0, scanf("%d", &n); i < n; i++) {
		scanf("%d", &homework_num);
		homeworks[homework_num] = 1;
	}

	for(i = 0, scanf("%d%d", &m, &k); i < m; ++i) {
		for(j = 0, scanf("%d%d", &stus[i].id, &finish_cnt); j < finish_cnt; ++j) {
			scanf("%d", &finish_num);

			if(1 == homeworks[finish_num])
				++stus[i].pass_cnt;
		}
	}

	qsort(stus, m, sizeof(struct stu), stu_cmp);

	for(i = 0; i < m && k; ++i) {
		printf("%d ", stus[i].id);

		if(i < m - 1 && stus[i].pass_cnt != stus[i + 1].pass_cnt)
			--k;
	}

	printf("\n");

	return 0;
}