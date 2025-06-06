#include <stdio.h>

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int day_of_year(int year, int month, int day) {
    if (month < 1 || month > 12)
       return -1;

    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if (day < 1 || day > daytab[leap][month])
       return -1;

    for (i = 1; i < month; i++)
       day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++)
       yearday -= daytab[leap][i];

    if (i > 12 && yearday > daytab[leap][12]) {
        *pmonth = -1;
        *pday = -1;
    } else {
        *pmonth = i;
        *pday = yearday;
    }
}

int main(void) {
    int *month, *day;
    int dyear = day_of_year(2025, 5, 31);
    month_day(2025, dyear, month, day);
    
    printf("Date: 2025.%d.%d\n", *month, *day);
    return 0;
}