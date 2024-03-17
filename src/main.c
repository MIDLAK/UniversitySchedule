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
                                       new_discipline(3, "Линейная алгебра")};

    /* преподаватели */
    struct teacher ananyev = new_teacher(100, "Павел", "Ананьев", "Иванович");
    struct teacher troickiy = new_teacher(101, "Виктор", "Троицкий", "Сергеевич");
    struct teacher irina = new_teacher(102, "Ирина", "Головичёва", "Эмильевна");
    struct teacher teachers[] = {ananyev, troickiy, irina};
    
    /* циклы занятий */
    struct lessons_cycle cycles[] = {{&ananyev, &disciplines[1], &clasters[1], 15, 1},
                                     {&troickiy, &disciplines[0], &clasters[2], 7, 2},
                                     {&irina, &disciplines[2], &clasters[1], 14, 1}};

    /* генерирование аудиторий */
#define ROOM_QTY 410
    struct room* rooms = rooms_generate(ROOM_QTY, 5, 100, 10, 300, deps, 
            sizeof(deps) / sizeof(deps[0]));

    return 0;
}
