#include <stdio.h>

int main()
{
	char ch;
	int i, sign = 1, sign1 = 1, sign2 = 1, flg = 0;
	int num1[2001], num2[2001], rslt[2001] = {0}, top1 = 0, top2 = 0, top_rslt = 0;

	sign = scanf("%c\n", &ch) != EOF && '+' == ch ? 1 : -1;

	while(scanf("%c", &ch) != EOF && ch != '\n'){
		if('-' == ch) {
			sign1 = -1;
			continue;
		}

		num1[top1++] = ch - '0';
	}

	while(scanf("%c", &ch) != EOF && ch != '\n'){
		if('-' == ch) {
			sign2 = -1;
			continue;
		}

		num2[top2++] = ch - '0';
	}

	sign2 *= sign;

	if(sign1 == sign2) {
		sign = sign1;

		while(top1 && top2){
			rslt[top_rslt++] = (num1[--top1] + num2[--top2] + flg) % 10;
			flg = (num1[top1] + num2[top2] + flg) / 10;
		}

		while(top1) {
			rslt[top_rslt++] = (num1[--top1] + flg) % 10;
			flg = (num1[top1] + flg) / 10;
		}

		while(top2) {
			rslt[top_rslt++] = (num2[--top2] + flg) % 10;
			flg = (num2[top2] + flg) / 10;
		}

		if(flg)
			rslt[top_rslt++] = flg;
	}
	else {
		if(top1 > top2) {
			sign = sign1;

			while(top2) {
				flg = num1[--top1] < num2[--top2] ? 1 : 0;
				rslt[top_rslt++] = num1[top1] - num2[top2] + flg * 10;

				num1[top1 - 1] -= flg;
			}

			while(top1)
				rslt[top_rslt++] = num1[--top1];
		}
		else if(top1 < top2) {
			sign = sign2;

			while(top1) {
				flg = num2[--top2] < num1[--top1] ? 1 : 0;
				rslt[top_rslt++] = num2[top2] - num1[top1] + flg * 10;

				num2[top2 - 1] -= flg;
			}

			while(top2)
				rslt[top_rslt++] = num2[--top2];
		}
		else {
			for(i = 0; num1[i] == num2[i] && i != top1; ++i)
				;

			if(i == top1) {
				sign = 1;
				rslt[top_rslt++] = 0;
			}
			else if(num1[i] > num2[i]) {
				sign = sign1;

				while(top1) {
					flg = num1[--top1] < num2[--top2] ? 1 : 0;
					rslt[top_rslt++] = num1[top1] - num2[top2] + flg * 10;

					num1[top1 - 1] -= flg;
				}
			}
			else {
				sign = sign2;

				while(top1) {
					flg = num2[--top2] < num1[--top1] ? 1 : 0;
					rslt[top_rslt++] = num2[top2] - num1[top1] + flg * 10;

					num2[top2 - 1] -= flg;
				}
			}
		}
	}

	if(-1 == sign)
		printf("-");

	while(!rslt[top_rslt - 1] && top_rslt > 1)
		--top_rslt;

	while(top_rslt)
		printf("%d", rslt[--top_rslt]);

	printf("\n");

	return 0;
}
