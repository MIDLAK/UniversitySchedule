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

    struct teacher ananyev = new_teacher(100, "Павел", "Ананьев", "Иванович");
    struct teacher troickiy = new_teacher(101, "Виктор", "Троицкий", "Сергеевич");
    struct teacher andreeva = new_teacher(102, "Ангелика", "Андреева", "Юрьевна");
    struct teacher teachers[] = {ananyev, troickiy, andreeva};

    /* генерирование аудиторий */
#define ROOM_QTY 410
    struct room* rooms = rooms_generate(ROOM_QTY, 5, 100, 10, 300, deps, 
            sizeof(deps) / sizeof(deps[0]));

    return 0;
}
