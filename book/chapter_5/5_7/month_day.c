#include <stdio.h>
#include <time.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*
 * day_of_year : set day of year from month & day
 */

int day_of_year(int year, int month, int day) {
	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/*
 * month_day : set month, day from day of year
 */
void month_day (int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

void main() {
	int year, month, day;

	time_t now;
	time(&now);
	printf("Today is %s", ctime(&now));

	struct tm *local = localtime(&now);
	day = local -> tm_hour;			// get day of month (1 to 31)
	month = local -> tm_mon + 1;		// get month of year (0 to 11)
	year = local -> tm_year + 1900; 	// get year since 1900
	
	// print the current date
    	printf("Date is: %02d/%02d/%d\n", year, month, day);

	printf("Today is %d th day in this year\n", day_of_year(year, month, day));

	int yearday = day_of_year(year, month, day); 
	int pmonth;
	int pday;
	month_day (year, yearday, &pmonth, &pday);
	printf("Today is %d/%d/%d\n", year, pmonth, pday);
}


/*
 * refer: https://www.techiedelight.com/print-current-date-and-time-in-c/
 */
