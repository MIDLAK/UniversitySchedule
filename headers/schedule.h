/* z_i - цикл занятий
 * a_i - аудитория
 * t_i - время проведения пар
 * 
 *  z_1   z_2  ...  z_n          z_1   z_2  ...  z_n
 *  ---   ---       ---          ---   ---       ---
 * |a_1| |a_2| ... |a_n|        |t_1| |t_2| ... |t_n|       
 *  ---   ---       ---          ---   ---       ---
 *    первая хромосома            вторая хромосома
 */

#ifndef __SCHEDULE
#define __SCHEDULE

#include "lesson.h"
#include "room.h"
#include "timeinterval.h"

struct gene
{
    struct lessons_cycle *lescycle;       /* цикл занятий */
    struct room          *room;           /* аудитория для проведения занятия */
    struct time_interval *pair_times;     /* неделя, день, номер пары */
    int                   pair_times_len; /* длина массива pair_times */ 
};

struct schedule_chromosome
{
    int cycles_num;    /* кол-во циклов занятий */
    struct gene *gens;
};

/* генерирование расписаний */
struct schedule_chromosome schedule_generate(struct lessons_cycle *cycles, int cycles_num,
        struct room *rooms, int rooms_num, 
        struct time_interval *time_intervals, int pair_times_len);

int schedule_test(struct schedule_chromosome *schedule);

/* проверка наложения аудиторий
 * 0 - наложений нет
 * 1 - наложения есть */
int rooms_conflict(struct schedule_chromosome *schedule);

#endif /* __SCHEDULE */
