#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INTEGER 1
#define DOUBLE	2
#define STRING	3

int main()
{
	double f;
	size_t len = 0;
	char *str = NULL;
	int i = 0, n, type = INTEGER;

	getline(&str, &len, stdin);

	if('-' == str[i])
		++i;

	for( ; str[i] != '\n' && type != STRING; ++i) {
		if(INTEGER == type && !isdigit(str[i])) {
			if('.' == str[i])
				type = DOUBLE;
			else
				type = STRING;
		}
		else if(DOUBLE == type && !isdigit(str[i]))
			type = STRING;
	}

	if(INTEGER == type) {
		sscanf(str, "%d", &n);
		printf("%d\n", n + 1);
	}
	else if(DOUBLE == type) {
		sscanf(str, "%lf", &f);
		printf("%d\n", (int)f);
	}
	else {
		for(i = 0; str[i]; ++i) {
			if(islower(str[i]))
				str[i] -= 32; /* 'a' - 'A' */

			putchar(str[i]);
		}
	}

	free(str);

	return 0;
}
