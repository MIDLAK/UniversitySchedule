#include <stdlib.h>
#include <time.h>

#include "../headers/room.h"
#include "../headers/department.h"

struct room* rooms_generate(int rooom_qty, int building_num, int room_in_floor,
        int max_capacity, int min_capacity, struct department *departments,
        int departments_num)
{
    struct room *rooms = (struct room*)malloc(sizeof(struct room) * rooom_qty);

    srand(time(NULL));
    /* генерация параметров аудитории */
    for (int i = 0; i < rooom_qty; i++) {
        rooms[i].room_num = room_in_floor + i;
        rooms[i].building_num = rand() % building_num + 1;
        rooms[i].capacity = rand() % (max_capacity + 1 - min_capacity) + min_capacity;
        rooms[i].type = rand() % RTYPE_LEN;
        rooms[i].department = &departments[rand() % departments_num];
    }

    return rooms;
}


