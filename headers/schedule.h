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

/* 0 - наложение нет, 1 - наложения есть */
int teachers_conflict(struct schedule_chromosome *schedule);

/* 0 - аудитории соответсвуют типам, 1 - есть несоотвествия, 2 - недостаточно места */
int correct_room_type_and_capacity(struct schedule_chromosome *schedule);

#endif /* __SCHEDULE */
