#include <stdio.h>

#if 0
int binary_search(const int *primes, int prime_cnt, int tar)
{
	int low = 0, high = prime_cnt - 1, mid;

	while(low <= high) {
		mid = (low + high) / 2;

		if(tar == primes[mid])
			return mid;

		if(tar < primes[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}
#endif

void get_primes(int *primes, int *prime_cnt, int *primes_map)
{
	int i, times;

	for(i = 2; i < 1000; ++i)
		if(!primes_map[i])
			for(times = 2; i * times < 1000000; ++times)
				primes_map[i * times] = 1;

	for(i = 0; i < 1000000; ++i)
		if(!primes_map[i])
			primes[(*prime_cnt)++] = i;
}

int main()
{
	int i, j, n, even, latest, combin_cnt;
	int primes[100000], prime_cnt = 0, primes_map[1000000] = {1, 1};

	get_primes(primes, &prime_cnt, primes_map);

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		scanf("%d", &even);

		for(j = 0, combin_cnt = 0; j < prime_cnt && primes[j] <= even / 2; ++j) {
			if(!primes_map[even - primes[j]]) {
				latest = primes[j];

				if(!combin_cnt++)
					printf("%d+%d ", primes[j], even - primes[j]);
			}
		}

		printf("%d+%d %d\n", latest, even - latest, combin_cnt);
	}

	return 0;
}
