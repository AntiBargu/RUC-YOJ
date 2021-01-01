#include <stdio.h>

int main()
{
	int i, j, n, top;
	size_t len;
	char *strs = NULL, stack[501];

	for(i = 0, scanf("%d\n", &n); i < n; ++i) {
		for(j = 0, top = 0, getline(&strs, &len, stdin); strs[j]; ++j) {
			if('(' == strs[j] || '{' == strs[j])
				stack[top++] = strs[j];

			else if(')' == strs[j]) {
				if('(' == stack[top - 1])
					--top;
				else
					break;
			}

			else if('}' == strs[j]) {
				if('{' == stack[top - 1])
					--top;
				else
					break;
			}
		}

		printf("%s\n", strs[j] || top ? "false" : "true");
	}

	return 0;
}
