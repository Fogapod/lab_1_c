#include <stdio.h>
#include <stdlib.h>

#define __USE_XOPEN
#include <time.h>


int main(void)
{
	unsigned int d, m, y;
	struct tm tm;
	time_t t;
	char str[256];
	int day_num;
	char *week_day_names[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

	printf("Please, enter date in format dd mm yyyy: ");

	if (scanf("%d %d %d", &d, &m, &y) != 3 || d < 1 || d > 31 || m < 1 || m > 12)
	{
		printf("Error: bad input!\n");
		exit(1);
	}

	if (y < 1970)
	{
		printf("Error: can't show day of the week before 1970 01 01\n");
		exit(1);
	}

	sprintf(str, "%d %d %d", d, m, y);

	if (strptime(str, "%d %m %Y", &tm) != NULL)
	{
		t = mktime(&tm);

		day_num = (localtime(&t)->tm_wday);

		if (day_num >= 0 && day_num < 12)
			printf("%s\n", week_day_names[day_num]);
		else
			printf("Error\n");
	}

	return 0;
}
