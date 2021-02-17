#include <stdio.h>

int main()
{
	int i, n, num, map[20001] = {0}, max_num = 0, num_cnt = 0;

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		scanf("%d", &num);

		++map[num + 10000];

		if(1 == map[num + 10000])
			++num_cnt;

		if(map[num + 10000] > map[max_num + 10000] || (map[num + 10000] == map[max_num + 10000] && num > max_num))
			max_num = num;
	}

	if(num_cnt * map[max_num + 10000] == n)
		printf("NO\n");
	else
		printf("%d %d\n", max_num, map[max_num + 10000]);

	return 0;
}
