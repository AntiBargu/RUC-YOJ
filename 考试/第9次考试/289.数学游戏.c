#include <stdio.h>

int main()
{
	int i, n, k, a, b, c, d, e, x, ans1, ans2, right1, right2, score1, score2, rslt;

	scanf("%d%d", &n, &k);
	for(i = 0, right1 = right2 = 0, score1 = score2 = 0; i < n; ++i) {
		scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &x, &ans1, &ans2);

		rslt = e + x * (d + x * (c + x * (b + x * a)));

		if(ans1 == rslt) {
			++score1;
			++right1;

			if(right1 > k)
				score1 += right1 - k;
		}
		else
			right1 = 0;

		if(ans2 == rslt) {
			++score2;
			++right2;

			if(right2 > k)
				score2 += right2 - k;
		}
		else
			right2 = 0;
	}

	printf("%d %d\n", score1, score2);

	return 0;
}
