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
                                       new_discipline(4, "ППО"),
                                       new_discipline(5, "Защита информации"),
                                       new_discipline(6, "Тестирование и отладка ПО"),
                                       new_discipline(7, "Проектирование ч-м интерфейсов"),
                                       new_discipline(8, "Метрология и документирование ПО")};

    /* преподаватели */
    struct teacher ananyev = new_teacher(100, "Павел", "Ананьев", "Иванович");
    struct teacher troickiy = new_teacher(101, "Виктор", "Троицкий", "Сергеевич");
    struct teacher irina = new_teacher(102, "Ирина", "Головичёва", "Эмильевна");
    struct teacher jacob = new_teacher(103, "Яков", "Ерёмин", "Борисович");
    struct teacher andrey = new_teacher(104, "Андрей", "Потупчик", "Иванович");
    struct teacher angelica = new_teacher(105, "Ангелика", "Андреева", "Юрьевна");
    struct teacher teachers[] = {ananyev, troickiy, irina, jacob, andrey, angelica};
    
    /* циклы занятий */
    struct lessons_cycle cycles[] = {{&ananyev, &disciplines[1], &clasters[1], PRACTICE, 15, 2},
                                     {&troickiy, &disciplines[0], &clasters[2], LECTURE, 7, 2},
                                     {&troickiy, &disciplines[4], &clasters[0], LECTURE, 7, 2},
                                     {&irina, &disciplines[2], &clasters[1], LAB, 14, 1},
                                     {&ananyev, &disciplines[3], &clasters[1], LAB, 10, 2},
                                     {&jacob, &disciplines[5], &clasters[0], LAB, 10, 2},
                                     {&andrey, &disciplines[7], &clasters[0], PRACTICE, 10, 1},
                                     {&angelica, &disciplines[6], &clasters[0], LECTURE, 10, 2}};
    int cycles_num = sizeof(cycles)/sizeof(cycles[0]);

    /* генерирование аудиторий */
#define ROOM_QTY 410
    struct room *rooms = rooms_generate(ROOM_QTY, 5, 100, 10, 300, deps, 
            sizeof(deps) / sizeof(deps[0]));

    /* интервалы времени */
    struct time_interval intervals[] = {{1, 1, 1}, {1, 1, 2}, {1, 1, 3}, {1, 1, 4}, 
                                        {1, 2, 1}, {1, 2, 2}, {1, 2, 3}, {1, 2, 4},
                                        {1, 3, 1}, {1, 3, 2}, {1, 3, 3}, {1, 3, 4},
                                        {1, 4, 1}, {1, 4, 2}, {1, 4, 3}, {1, 4, 4},
                                        {1, 5, 1}, {1, 5, 2}, {1, 5, 3}, {1, 5, 4},
                                        {2, 1, 1}, {2, 1, 2}, {2, 1, 3}, {2, 1, 4}, 
                                        {2, 2, 1}, {2, 2, 2}, {2, 2, 3}, {2, 2, 4},
                                        {2, 3, 1}, {2, 3, 2}, {2, 3, 3}, {2, 3, 4},
                                        {2, 4, 1}, {2, 4, 2}, {2, 4, 3}, {2, 4, 4},
                                        {2, 5, 1}, {2, 5, 2}, {2, 5, 3}, {2, 5, 4}};
    struct schedule_chromosome schedule = schedule_generate(cycles, cycles_num, rooms,
            ROOM_QTY, intervals, sizeof(intervals)/sizeof(intervals[0]));

    for (int i = 0; i < cycles_num; i++) {
        struct gene *g = &schedule.gens[i];
        printf("\n[%d] disc = %s (%d), room = %d (%d), teacher = %s", 
                i, g->lescycle->discipline->name, g->lescycle->type, g->room->room_num, 
                g->room->type, g->lescycle->teacher->surname);
        for (int j = 0; j < g->lescycle->intensity * 2; j++)
            printf(" [ %d.%d.%d]", g->pair_times[j].week, 
                    g->pair_times[j].day, g->pair_times[j].pair);
    }

    int test_schedule = schedule_test(&schedule);
    printf("\ntest = %d", test_schedule);

    int teacher_test = teachers_conflict(&schedule);
    printf("\nteacher test = %d", teacher_test);

    int room_conflict_test = rooms_conflict(&schedule);
    printf("\nrooms conflict test = %d", room_conflict_test);

    int room_type_test = correct_room_type_and_capacity(&schedule);
    printf("\nrooms type test = %d", room_conflict_test);

    return 0;
}
