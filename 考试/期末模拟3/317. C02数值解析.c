#include <stdio.h>
#include <ctype.h>

int main()
{
	size_t i, len = 0;
	char *line  = NULL;
	long long sum = 0, tmp = 0;

	getline(&line, &len, stdin);

	for(i = 0; line[i]; ++i) {
		if(!isdigit(line[i])) {
			sum += tmp;
			tmp = 0;
			continue;
		}

		tmp *= 10;
		tmp += line[i] - '0';
	}

	printf("%lld\n", sum);

	return 0;
}
