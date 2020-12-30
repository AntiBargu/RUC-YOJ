#include <stdio.h>
#include <string.h>

int main()
{
	int i, m, n;
	size_t len = 0;
	char cmd[5], *line = NULL;

	scanf("%d", &n);
	scanf("%s%d\n", cmd, &m);

	if(0 == strcmp(cmd, "head")) {
		for(i = 0; i < n; ++i) {
			getline(&line, &len, stdin);

			if(i < m)
				printf("%s", line);
		}
	}
	else {
		for(i = 0; i < n; ++i) {
			getline(&line, &len, stdin);

			if(i + m >= n)
				printf("%s", line);
		}
	}

	return 0;
}
