#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int similarity[100];

int similarity_cmp(const void *a, const void *b)
{
	if(similarity[*(int *)a] == similarity[*(int *)b])
		return *(int *)a - *(int *)b;

	return similarity[*(int *)a] - similarity[*(int *)b];
}

int main()
{
	int i, j, n, k, f, len1, len2, v1[16] = {0}, v2[16], indices[100];

	for(i = 0, scanf("%d",&len1); i < len1; ++i) {
		scanf("%d", &f);
		++v1[f / 16];
	}

	for(i = 0, scanf("%d%d", &n, &k); i < n; ++i) {
		indices[i] = i;

		memset(v2, 0 ,sizeof(v2));

		for(j = 0, scanf("%d", &len2); j < len2; ++j) {
			scanf("%d", &f);
			++v2[f / 16];
		}

		for(j = 0; j < 16; ++j)
			similarity[i] += (v1[j] - v2[j]) * (v1[j] - v2[j]);
	}

	qsort(indices, n, sizeof(int), similarity_cmp);

	for(i = 0; i < k; ++i)
		printf("%d ", indices[i]);

	printf("\n");

	return 0;

}