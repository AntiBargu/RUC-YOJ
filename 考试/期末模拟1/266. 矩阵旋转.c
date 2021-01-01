#include <stdio.h>

int main()
{
	int i, j, m, n, matrix[50][50] = {{0}}, cmd;

	scanf("%d%d", &m, &n);

	for(i = 0; i < m; ++i)
		for(j = 0; j < n; ++j)
			scanf("%d", &matrix[i][j]);

	scanf("%d", &cmd);

	cmd = ((cmd / 90) + 40000) % 4;

	switch(cmd) {
		/* 90 */
		case 1 :
			for(i = 0; i < n; ++i) {
				for(j = m - 1; j >= 0; --j)
					printf("%d ", matrix[j][i]);

				printf("\n");
			}

			break;

		/* 180 */
		case 2 :	
			for(i = m - 1; i >= 0; --i) {
				for(j = n - 1; j >= 0; --j)
					printf("%d ", matrix[i][j]);

				printf("\n");
			}

			break;

		/* 270 */
		case 3 :
			for(i = n - 1; i >= 0; --i) {
				for(j = 0; j < m; ++j)
					printf("%d ", matrix[j][i]);

				printf("\n");
			}

			break;

		/* 360 */
		default :
			for(i = 0; i < m; ++i) {
				for(j = 0; j < n; ++j)
					printf("%d ", matrix[i][j]);

				printf("\n");
			}
	}

	return 0;
}
