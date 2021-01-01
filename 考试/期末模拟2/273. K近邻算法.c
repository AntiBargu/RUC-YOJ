#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	int x, y, type, dist;
};


int dist_cmp(const void *a, const void *b)
{
	return ((struct node *)a)->dist - ((struct node *)b)->dist;
}

int main()
{
	int x, y;
	struct node nodes[10000];
	int i, j, k, node_cnt, total_cnt = 0;
	int type_cnt, types[101] = {0}, max_type = 100;

	scanf("%d%d", &type_cnt, &k);

	for(i = 1; i <= type_cnt; ++i) {
		scanf("%d", &node_cnt);

		for(j = 0; j < node_cnt; ++j) {
			scanf("%d%d", &nodes[total_cnt].x, &nodes[total_cnt].y);
			nodes[total_cnt++].type = i;
		}
	}

	scanf("%d%d", &x, &y);

	for(i = 0; i < total_cnt; ++i)
		nodes[i].dist = pow(x - nodes[i].x, 2) + pow(y - nodes[i].y, 2);

	qsort(nodes, total_cnt, sizeof(struct node), dist_cmp);

	if(total_cnt < k)
		k = total_cnt;

	for(i = 0; nodes[i].dist <= nodes[k - 1].dist && i < total_cnt; ++i) {
		++types[nodes[i].type];

		if((types[max_type] < types[nodes[i].type]) ||
				(types[max_type] == types[nodes[i].type] && max_type > nodes[i].type))
			max_type = nodes[i].type;
	}

	printf("%d\n", max_type);

	return 0;
}
