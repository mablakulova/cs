#include <stdio.h>

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int day_of_year(int year, int month, int day) {
    int leap;
    char *c;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    c = daytab[leap];
    while (month-- > 1)
       day += *++c;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int month, leap;
    char *c;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    c = daytab[leap];
    month = 1;

    while (yearday > *++c) {
        yearday -= *c;
        month++;
    }
    *pmonth = month;
    *pday = yearday;
}

int main(void) {
    int *month, *day;
    int dyear = day_of_year(2025, 5, 31);
    month_day(2025, dyear, month, day);
    
    printf("Date: 2025.%d.%d\n", *month, *day);
    return 0;
}