#include <stdio.h>

int total;
char rslt[501];

void array_get(int *cnts, int pos, int len)
{
	int i;

	if(pos == len) {
		printf("%s\n", rslt);
		++total;
		return ;
	}

	for(i = 0; i < 26; ++i) {
		if(cnts[i] > 0) {
			rslt[pos] = i + 'a';

			--cnts[i];
			array_get(cnts, pos + 1, len);
			++cnts[i];
		}
	}
}

int main()
{
	char strs[501] = {0};
	int i, len, cnts[26] = {0};

	scanf("%d%s", &len, strs);

	for(i = 0; strs[i]; ++i)
		++cnts[strs[i] - 'a'];

	array_get(cnts, 0, len);

	printf("%d\n", total);

	return 0;
}
