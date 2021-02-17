#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct farm {
	int id, stat, capacity, basic_cost, cost;
};

int pigs[3];

int farms_cmp(const void *a, const void *b)
{
	return ((struct farm *)a)->id - ((struct farm *)b)->id;
}

int pigs_cmp(const void *a, const void *b)
{
	return pigs[*(int *)b] - pigs[*(int *)a];
}

int main()
{
	struct farm farms[3000];
	int i, j, n, indices[3] = {0, 1, 2}, rslt[3], tmp_min, total_min, tmp;

	for(i = 0; i < 3; ++i)
		scanf("%d", &pigs[i]);

	/* 对猪仔的批次的下标降序排列 */
	qsort(indices, 3, sizeof(int), pigs_cmp);

	for(i = 0, scanf("%d", &n); i < n; ++i)
		scanf("%d%d%d%d%d", &farms[i].id, &farms[i].stat, &farms[i].capacity, &farms[i].basic_cost, &farms[i].cost);

	/* 对养殖场的编号进行升序排列，目的是为了优先分配小的养殖场编号 */
	qsort(farms, n, sizeof(struct farm), farms_cmp);

	/* 贪心算法：优先分配猪的数量多的批次 */
	for(i = 0, total_min = 0; i < 3; ++i) {
		for(j = 0, tmp_min = INT_MAX; j < n; ++j) {
			if(!farms[j].stat && farms[j].capacity >= pigs[indices[i]] 
					&& (farms[j].basic_cost + pigs[indices[i]] * farms[j].cost < tmp_min)) {
				tmp_min = farms[j].basic_cost + pigs[indices[i]] * farms[j].cost;
				rslt[indices[i]] = j;
			}
		}

		/* 无养殖场课分配 */
		if(INT_MAX == tmp_min) {
			printf("NO\n");

			return 0;
		}
		else {
			total_min += tmp_min;
			farms[rslt[indices[i]]].stat = 1;
		}
	}

	/*
	/* 贪心后更新分配养殖场的编号（比较恶心的约束）
	 *
	 * 已知在两层循环中，批次为indices[i]的猪的数量 <= 批次为indices[j]的猪的数量
	 *  case 1：批次为indices[i]分配的养殖场的每头猪仔的成本 = 批次为indices[j]分配的养殖场的每头猪仔的成本，且批次为indices[j]的养猪场能容纳批次为indices[i]的猪
	 *  case 2：批次为indices[i]的猪的数量 = 批次为indices[j]的猪的数量
	 *
	 * 若此时批次为indices[i]的猪的id大于批次为indices[j]的猪的id，根据题目要求需要更换两个批次的养殖场
	 */
	for(i = 0; i < 3; ++i)
		for(j = i + 1; j < 3; ++j)
			if(((farms[rslt[indices[i]]].cost == farms[rslt[indices[j]]].cost
				&& farms[rslt[indices[j]]].capacity >= pigs[indices[i]]) || (pigs[indices[i]] == pigs[indices[j]]))
				&& farms[rslt[indices[i]]].id > farms[rslt[indices[j]]].id) {
				tmp = rslt[i];
				rslt[i] = rslt[j];
				rslt[j] = tmp;
			}

	printf("%d\n", total_min);

	for(i = 0; i < 3; ++i)
		printf("%d ", farms[rslt[i]].id);

	printf("\n");

	return 0;
}
