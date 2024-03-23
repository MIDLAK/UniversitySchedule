#include <stdio.h>
#include <stdlib.h>

#include "../headers/teacher.h"
#include "../headers/schedule.h"
#include "../headers/room.h"
#include "../headers/department.h"

int main(int argc, char **argv)
{
    /* генерация данных */
    struct department deps[] = {{1}, {2}, {3}};
    struct academ_claster clasters[] = {{30, GROUP}, {15, SUBGROUP}, {90, THREAD}};
    struct discipline disciplines[] = {new_discipline(1, "Программирование"), 
                                       new_discipline(2, "Базы данных"), 
                                       new_discipline(3, "Линейная алгебра"),
                                       new_discipline(4, "ППО")};

    /* преподаватели */
    struct teacher ananyev = new_teacher(100, "Павел", "Ананьев", "Иванович");
    struct teacher troickiy = new_teacher(101, "Виктор", "Троицкий", "Сергеевич");
    struct teacher irina = new_teacher(102, "Ирина", "Головичёва", "Эмильевна");
    struct teacher teachers[] = {ananyev, troickiy, irina};
    
    /* циклы занятий */
    struct lessons_cycle cycles[] = {{&ananyev, &disciplines[1], &clasters[1], PRACTICE, 15, 2},
                                     {&troickiy, &disciplines[0], &clasters[2], LECTURE, 7, 2},
                                     {&irina, &disciplines[2], &clasters[1], LAB, 14, 1},
                                     {&ananyev, &disciplines[3], &clasters[1], LAB, 10, 2}};
    int cycles_num = sizeof(cycles)/sizeof(cycles[0]);

    /* генерирование аудиторий */
#define ROOM_QTY 410
    struct room* rooms = rooms_generate(ROOM_QTY, 5, 100, 10, 300, deps, 
            sizeof(deps) / sizeof(deps[0]));

    /* генерация интервалов времени */
    struct time_interval intervals[] = {{1, 1, 1}, {1, 1, 2}, {1, 1, 3}, {1, 1, 4}, 
                                        {1, 2, 1}, {1, 2, 2}, {1, 2, 3}, {1, 2, 4},
                                        {2, 1, 1}, {2, 1, 2}, {2, 1, 3}, {2, 1, 4}};
    struct schedule_chromosome schedule = schedule_generate(cycles, cycles_num, rooms,
            ROOM_QTY, intervals, sizeof(intervals)/sizeof(intervals[0]));

    for (int i = 0; i < cycles_num; i++) {
        struct gene *g = &schedule.gens[i];
        printf("\n[%d] disc = %s, room = %d, time = [%d.%d.%d, %d.%d.%d, ...], teacher = %s", 
                i, g->lescycle->discipline->name, g->room->room_num, g->pair_times[0].week,
                g->pair_times[0].day, g->pair_times[0].pair, g->pair_times[1].week, 
                g->pair_times[1].day, g->pair_times[1].pair, g->lescycle->teacher->surname);
    }

    int test_schedule = schedule_test(&schedule);
    printf("\ntest = %d", test_schedule);

    int teacher_test = teachers_conflict(&schedule);
    printf("\nteacher test = %d", teacher_test);

    return 0;
}
