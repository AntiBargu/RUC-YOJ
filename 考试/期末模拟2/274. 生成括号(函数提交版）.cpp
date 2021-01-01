#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40
#define M 300000


char allRes[M][N] = {{0}};    //保存所有结果
char szRes[N] = {0};        // 全局变量，保存n对括号组成的一个序列

void genParentheses(int left_cnt, int right_cnt, int pos, int &res_cnt)
{
	if(left_cnt > right_cnt)
		return ;

	if(0 == left_cnt && 0 == right_cnt) {
		strncpy(allRes[res_cnt++], szRes, pos);
		return ;
	}

	if(left_cnt > 0) {
		szRes[pos] = '(';
		genParentheses(left_cnt - 1, right_cnt, pos + 1, res_cnt);
	}

	if(right_cnt > 0) {
		szRes[pos] = ')';
		genParentheses(left_cnt, right_cnt - 1, pos + 1, res_cnt);
	}
}


int main()
{
    int n, nRes = 0, i;
    
    scanf("%d", &n);
    genParentheses(n, n, 0, nRes);

    printf("%d\n", nRes);
    for(i = 0; i < nRes; i ++)
        printf("%s\n", allRes[i]);

    return 0;
}
