#include "../headers/schedule.h"
#include <stdio.h>
#include <stdlib.h>

struct schedule_chromosome schedule_generate(struct lessons_cycle *cycles, int cycles_num,
        struct room *rooms, int rooms_num,
        struct time_interval *time_intervals, int pair_times_len)
{
    struct schedule_chromosome schedule;
    schedule.cycles_num = cycles_num;
    schedule.gens = (struct gene*)malloc(sizeof(struct gene) * cycles_num);

    /* подбор кабинета и пар для циклов */
    for (int i = 0; i < cycles_num; i++) {
        schedule.gens[i].lescycle = &cycles[i];

        /* TODO: пытаться размещать занятия в одном корпусе */
        schedule.gens[i].room = &rooms[rand() % rooms_num];

        /* TODO: сделать равномерную нагрузку по неделям */
        int intensity = schedule.gens[i].lescycle->intensity;
#define WEEKS_CYCLE 2 /* вычисление, сколько пар нужно выбрать исходя из интенсовности */
        schedule.gens[i].pair_times = malloc(sizeof(struct time_interval) * intensity * WEEKS_CYCLE);
        schedule.gens[i].pair_times_len = intensity * WEEKS_CYCLE;
        for (int j = 0; j < (intensity * WEEKS_CYCLE); j++) {
            schedule.gens[i].pair_times[j] = time_intervals[rand() % pair_times_len];
        }
    }

    /* schedule_test(&schedule); */

    return schedule;
}

int schedule_test(struct schedule_chromosome *schedule)
{
    int rconflict = rooms_conflict(schedule);
    if (rconflict == 0)
        return 0;
    else
        return 1;
}

int rooms_conflict(struct schedule_chromosome *schedule)
{
    /* аудитории циклов занятий */
    for (int i = 0; i < schedule->cycles_num; i++) { 
        int main_rnum = schedule->gens[i].room->room_num;
        int main_rbuild = schedule->gens[i].room->building_num;

        /* другие циклы занятий */
        for (int j = 0; j < schedule->cycles_num; j++) {
            if (i != j) { /* не сравнивать цикл занятий с самим собой */
                int rnum = schedule->gens[j].room->room_num;
                int rbuild = schedule->gens[j].room->building_num;

                /* проверка времени, если аудитории совпали */
                if (main_rnum == rnum && main_rbuild == rbuild) {
                    for(int t = 0; t < schedule->gens[i].pair_times_len; t++) {
                        for (int m; m < schedule->gens[j].pair_times_len; m++) {
                            int main_day = schedule->gens[i].pair_times[t].day, 
                                main_week = schedule->gens[i].pair_times[t].week,
                                main_pair = schedule->gens[i].pair_times[t].pair;

                            int day = schedule->gens[j].pair_times[m].day,
                                week = schedule->gens[j].pair_times[m].week,
                                pair = schedule->gens[j].pair_times[m].pair;

                            if (main_day == day && main_week == week && main_pair == pair)
                                return 1; /* считать все конфликты нет смысла */
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

