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

#define MAX_ATTEMPT_COUNT 100
    int attempt_count = -1;
    do {
        attempt_count++;
        /* подбор кабинета и пар для циклов */
        for (int i = 0; i < cycles_num; i++) {
            schedule.gens[i].lescycle = &cycles[i];

            /* TODO: пытаться размещать занятия в одном корпусе и выбирать нужные типы */
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
    } while(schedule_test(&schedule) && attempt_count < MAX_ATTEMPT_COUNT);

    printf("[debug]: attepmt_count = %d", attempt_count);
    return schedule;
}

int schedule_test(struct schedule_chromosome *schedule)
{
    int rconflict = rooms_conflict(schedule);
    if (rconflict == 0 && teachers_conflict(schedule) == 0 && 
            correct_room_type_and_capacity(schedule) == 0)
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
                        for (int m = 0; m < schedule->gens[j].pair_times_len; m++) {
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

/* 0 - наложение нет, 1 - наложения есть */
int teachers_conflict(struct schedule_chromosome *schedule)
{
    for (int i = 0; i < schedule->cycles_num; i++) {
        int main_teacher_id = schedule->gens[i].lescycle->teacher->id;

        /* другие циклы занятий */
        for (int j = 0; j < schedule->cycles_num; j++) {
            if (i != j) {
                int teacher_id = schedule->gens[j].lescycle->teacher->id; 

                if (main_teacher_id == teacher_id) {
                    for(int t = 0; t < schedule->gens[i].pair_times_len; t++) {
                        for (int m = 0; m < schedule->gens[j].pair_times_len; m++) {
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


/* 0 - аудитории соответсвуют типам, 1 - есть несоотвествия */
int correct_room_type_and_capacity(struct schedule_chromosome *schedule)
{
    for (int i = 0; i < schedule->cycles_num; i++) {
        struct gene *g = &schedule->gens[i];
        int room_capacity = g->room->capacity;
        int students_num = g->lescycle->claster->students_num;

        if (room_capacity >= students_num) {
            enum ltype lescycle_type = g->lescycle->type;
            enum rtype room_type = g->room->type;

            if ((lescycle_type == LAB && room_type != LABORATORY) ||
                (lescycle_type == PRACTICE && room_type != PRACTICAL) ||
                (lescycle_type == LECTURE && (room_type != BIG_LECTURE || 
                    room_type != MEDIUM_LECTURE || room_type != SMALL_LECTURE))
               )
                return 1;

        } else { return 2; }
    }

    return 0;
}
