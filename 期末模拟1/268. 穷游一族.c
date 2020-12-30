#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 节点信息：
 * @dist: 到源点的距离
 * @parent: 在最短路径树上的父亲节点
 */
struct node {
	int dist, parent;
} nodes[50];

/* 已知找到destination，根据@parent信息递归地打印最短路径 */
void shortpath_print(int i)
{
	if(INT_MAX == nodes[i].parent) {
		printf("%d", i);
		return ;
	}

	shortpath_print(nodes[i].parent);
	printf("->%d", i);
}

/*
 * 对下标数组indices排序，排序规则：
 * 到源点距离的非降序排序，若到源点的距离相同，则按序号（唯一）升序排序
 */
int dist_cmp(const void *a, const void *b)
{
	if(nodes[*(int *)a].dist == nodes[*(int *)b].dist)
		return *(int *)a - *(int *)b;

	return nodes[*(int *)a].dist - nodes[*(int *)b].dist;
}

int main()
{
	/* 
	 * @indices：被@select分为两个部分：
	 *  select左边是Dijkstra筛选出最短路径树节点的下标集；右边是待筛选集。
	 *  筛选的机制就是Dijkstra，即选个离最短路径树节点集最近的节点。
	 */
	int i, j, city_cnt, src, dest, map_matrix[50][50], indices[50], select_cnt;

	scanf("%d%d%d", &city_cnt, &src, &dest);

	/* 初始化下标集和节点信息，默认到源点的距离@dist无穷远，@parent顺路用不合法值INT_MAX */
	for(i = 0; i < city_cnt; ++i) {
		indices[i] = i;
		nodes[i].dist = nodes[i].parent = INT_MAX;
	}

	for(i = 0; i < city_cnt; ++i)
		for(j = 0; j < city_cnt; ++j)
			scanf("%d", &map_matrix[i][j]);

	/* Dijkstra */
	for(select_cnt = 0, nodes[src].dist = 0; select_cnt < city_cnt; ++select_cnt) {
		/* 这里可以维护一个堆，用排序替代了 */
		qsort(&indices[select_cnt], city_cnt - select_cnt, sizeof(int), dist_cmp);

		i = indices[select_cnt];

		/* 找到destination或无路径就退出循环 */
		if(i == dest || INT_MAX == nodes[i].dist)
			break;

		for(j = 0; j < city_cnt; ++j) {
			if(-1 == map_matrix[i][j])
				continue;

			/* Relax */
			if(nodes[j].dist > nodes[i].dist + map_matrix[i][j]) {
				nodes[j].dist = nodes[i].dist + map_matrix[i][j];
				nodes[j].parent = i;
			}
		}
	}

	if(nodes[i].dist != INT_MAX)
		shortpath_print(i);
	else
		printf("-1");

	printf("\n");

	return 0;
}
