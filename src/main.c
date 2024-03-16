#include <stdio.h>
#include <stdlib.h>

#include "../headers/teacher.h"
#include "../headers/schedule.h"
#include "../headers/room.h"
#include "../headers/department.h"

int main(int argc, char **argv)
{
    struct teacher *pavel = new_teacher(100, "Павел", "Ананьев", "Иванович");
    printf("[debug] id = %d: %s %s %s", pavel->id, pavel->surname, pavel->name, pavel->midname);

    struct department deps[] = {{1}, {2}, {3}};

#define ROOM_QTY 410
    struct room* rooms = rooms_generate(ROOM_QTY, 5, 100, 10, 300, deps, 
            sizeof(deps) / sizeof(deps[0]));
    for (int i = 0; i < ROOM_QTY; i++) {
        printf("r_num = %d, r_build = %d, r_capacity = %d, r_type = %d, r_dep = %d\n",
                rooms[i].room_num, rooms[i].building_num, rooms[i].capacity, rooms[i].type, 
                rooms[i].department->id);
    }

    return 0;
}
