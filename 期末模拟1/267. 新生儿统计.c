#include <stdio.h>
#include <stdlib.h>

struct week_st {
	int baby_cnt, boy_cnt, id;
};

int normal_calendar[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int leap_calendar[] = {
	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int date_to_dayid(int year, int mon, int day)
{
	int i, day_id, *calendar;

	day_id = (year - 1969) / 4 * (365 * 4 + 1);
	day_id += (year - 1969) % 4 * 365;

	calendar = (3 == (year - 1969) % 4) ? leap_calendar : normal_calendar;

	for(i = 0; i < mon - 1; ++i)
		day_id += calendar[i];

	day_id += day;

	/*
	 * 将星期和日期对齐：1969.1.1是星期三 编号是1，修正后编号为3，
	 * 目的是方便后续计算周期运算时的一些列模运算
	 */
	day_id += 2;

	return day_id;
}

void dayid_to_date(int day_id, int year, int *mon, int *day)
{
	int i, *calendar;

	/*
	 * 是date_to_dayid的逆运算
	 * 同上，将星期和日期对齐：1969.1.1是星期三 编号是1，修正后编号为3
	 */
	day_id -= 2;

	day_id -= (year - 1969) / 4 * (365 * 4 + 1);
	day_id -= (year - 1969) % 4 * 365;

	calendar = (3 == (year - 1969) % 4) ? leap_calendar : normal_calendar;

	for(i = 0, *mon = 1; i < 11 && day_id > calendar[i]; ++i, ++*mon)
		day_id -= calendar[i];

	/*
	 * 边界：不足一年和超过一年的日期按照1.1和12.31处理
	 * 其余的case：即是非边界条件，直接把减剩下的day_id赋值给day即可
	 */
	if(day_id < 1)
		*day = 1;
	else if(day_id > 31)
		*day = 31;
	else
		*day = day_id;
}

int week_cmp(const void *a, const void *b)
{
	return ((struct week_st *)b)->baby_cnt - ((struct week_st *)a)->baby_cnt;
}

int main()
{
	struct week_st week_map[3000] = {{0}};
	int i, m, n, baby_id, year, mon, day, is_boy, day_id;

	for(i = 0; i < 3000; ++i)
		week_map[i].id = i;

	scanf("%d%d%d", &year, &n, &m);

	for(i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &baby_id, &mon, &day, &is_boy);

		day_id = date_to_dayid(year, mon, day);

		++week_map[day_id / 7].baby_cnt;

		if(is_boy)
			++week_map[day_id / 7].boy_cnt;
	}

	qsort(week_map, 3000, sizeof(struct week_st), week_cmp);

	for(i = 0; i < m; ++i) {
		dayid_to_date(week_map[i].id * 7, year, &mon, &day);
		printf("[%2d.%2d-", mon, day);

		dayid_to_date(week_map[i].id * 7 + 6, year, &mon, &day);
		printf("%2d.%2d]:%d(B%d)\n", mon, day,
				week_map[i].baby_cnt, week_map[i].boy_cnt);
	}

	return 0;
}
