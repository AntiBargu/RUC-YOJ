#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, k, m, n, graph_cnt = 0;
	char graph[50][50] = {{0}}, graphs[4][50][50] = {{{0}}};

	scanf("%d%d\n", &n, &m);

	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j)
			scanf("%c", &graph[i][j]);

		getchar();
	}

	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			graphs[graph_cnt][i][j] = graph[i][n - 1 - j];

	++graph_cnt;

	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			graphs[graph_cnt][i][j] = graph[n - 1 - i][j];

	/* 判断新获取的图片与之前记录的图片是否相同，若相同就丢弃；不同则保留 */
	for(i = graph_cnt - 1; i >= 0 && memcmp(graphs[i], graphs[graph_cnt], sizeof(graph)); --i)
		;

	if(i < 0)
		++graph_cnt;

	if(1 == m) {
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
				graphs[graph_cnt][i][j] = graph[n - 1 - j][n - 1 - i];
			
		for(i = graph_cnt - 1; i >= 0 && memcmp(graphs[i], graphs[graph_cnt], sizeof(graph)); --i)
			;

		if(i < 0)
			++graph_cnt;

		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
				graphs[graph_cnt][i][j] = graph[j][i];

		for(i = graph_cnt - 1; i >= 0 && memcmp(graphs[i], graphs[graph_cnt], sizeof(graph)); --i)
			;

		if(i < 0)
			++graph_cnt;
	}

	printf("%d\n", graph_cnt);

	for(i = 0; i < graph_cnt; ++i) {
		for(j = 0; j < n; ++j) {
			for(k = 0; k < n; ++k)
				printf("%c", graphs[i][j][k]);

			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
