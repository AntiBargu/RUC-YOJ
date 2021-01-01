#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
	int i, j, k, l, points[4][3], rslt[1000][3], rslt_cnt, dist, min_dist = INT_MAX;
	int interval[2][3] = {{INT_MAX, INT_MAX, INT_MAX}, {INT_MIN, INT_MIN, INT_MIN}};

	for(i = 0; i < 4; ++i) {
		for(j = 0; j < 3; ++j) {
			scanf("%d", &points[i][j]);

			if(points[i][j] < interval[0][j])
				interval[0][j] = points[i][j];

			if(points[i][j] > interval[1][j])
				interval[1][j] = points[i][j];
		}
	}

	/* 
	 * sqrt(x)要比pow(x, 0.5)快得多
	 * 本题中用pow(x, 0.5)会TLE
	 */
	for(i = interval[0][0]; i < interval[1][0]; ++i)
		for(j = interval[0][1]; j < interval[1][1]; ++j)
			for(k = interval[0][2]; k < interval[1][2]; ++k) {
				for(l = 0, dist = 0; l < 4; ++l) {
					dist += (int)sqrt((points[l][0] - i) * (points[l][0] - i) + 
						(points[l][1] - j) * (points[l][1] - j) + (points[l][2] - k) * (points[l][2] - k));
				}
				
				if(dist < min_dist) {
					min_dist = dist;

					rslt_cnt = 0;
					rslt[rslt_cnt][0] = i;
					rslt[rslt_cnt][1] = j;
					rslt[rslt_cnt][2] = k;
					++rslt_cnt;
				}
				else if(dist == min_dist) {
					rslt[rslt_cnt][0] = i;
					rslt[rslt_cnt][1] = j;
					rslt[rslt_cnt][2] = k;
					++rslt_cnt;
				}
			}

	printf("%d %d\n", min_dist, rslt_cnt);

	for(i = 0; i < rslt_cnt; ++i)
		printf("%d %d %d\n", rslt[i][0], rslt[i][1], rslt[i][2]);

	return 0;
}
