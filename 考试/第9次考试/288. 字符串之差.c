#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(const char *s1, const char *s2)
{
	int i;

	for(i = 0; s1[i] == s2[i]; ++i)
		;

	return s1[i] - s2[i];
}

int main()
{
	size_t len1, len2;
	char *s1 = NULL, *s2 = NULL;

	getline(&s1, &len1, stdin);
	getline(&s2, &len2, stdin);

	printf("%d\n", my_strcmp(s1, s2));

	free(s1);
	free(s2);

	return 0;
}
