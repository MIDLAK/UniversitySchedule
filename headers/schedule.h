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
    struct lessons_cycle *lescycle;    /* цикл занятий */
    struct room          *room;       /* аудитория для проведения занятия */
    struct time_interval *pair_times; /* неделя, день, номер пары */
};

struct schedule_chromosome
{
    int cycles_num;    /* кол-во циклов занятий */
    struct gene *gens;
};

#endif /* __SCHEDULE */
