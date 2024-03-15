#include <stdlib.h>

#include "../headers/room.h"
#include "../headers/department.h"

struct room* rooms_generate(int rooom_num, int building_num, int max_capacity, 
        int min_capacity, struct department *departments)
{
    struct room *rooms = (struct room*)malloc(sizeof(struct room) * rooom_num);
    struct department *deps = (struct department*)malloc(
            sizeof(struct department) * building_num);

    for (int i = 0; i < rooom_num; i++);

    return rooms;
}
