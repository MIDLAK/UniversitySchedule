#ifndef __TIMEINTERVAL
#define __TIMEINTERVAL

enum day_of_week
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct time_interval
{
    int week;              /* номер учебной недели начиная с 1-й */
    enum day_of_week day;  /* номер дня недели */
    int pair;              /* номер пары в течении дня начиная с 1-й */
};

#endif /* __TIMEINTERVAL */
