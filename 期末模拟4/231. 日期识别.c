#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	size_t len;
	int i, nums[3];
	char *line = NULL, mon[15];
	const char *patterns[3] = {
		"%d.%d.%d", 
		"%d/%d/%d", 
		"%d-%d-%d"
	};
	const char *months[12] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	getline(&line, &len, stdin);

	if(isdigit(line[0])) {
		for(i = 0; i < 3; ++i)
			sscanf(line, patterns[i], &nums[0], &nums[1], &nums[2]);

		if(nums[0] > 999)
			printf("%d%02d%02d\n", nums[0], nums[1], nums[2]);
		else
			printf("%d%02d%02d\n", nums[2], nums[0], nums[1]);
	}
	else {
		sscanf(line, "%s%d,%d", mon, &nums[0], &nums[1]);

		for(i = 0; i < 12 && strcmp(mon, months[i]); ++i)
			;

		printf("%d%02d%02d\n", nums[1], i + 1, nums[0]);
	}

	free(line);

	return 0;
}
