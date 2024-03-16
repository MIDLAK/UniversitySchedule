#ifndef __ROOM
#define __ROOM

#include "department.h"

enum rtype 
{
    BIG_LECTURE,    /* более 3-х групп */
    MEDIUM_LECTURE, /* 3 группы */
    SMALL_LECTURE,  /* мньше 3-х групп */
    PRACTICAL,
    LABORATORY,

    RTYPE_LEN       /* размер перечисления */
};

struct room 
{
    int room_num;
    int building_num;                /* номер корпуса */
    int capacity;
    enum rtype type;
    struct department *department;   /* к какой кафедре относится аудитория */
};

/* building_num - общее количество корпусов университета
 * room_in_floor - сколько кабинетов на одном этаже
 * room_qty - сколько комнат сгенерировать всего */
struct room* rooms_generate(int rooom_qty, int building_num, int room_in_floor,
        int max_capacity, int min_capacity, struct department *departments,
        int departmens_num);

#endif /* __CLASSROOM */
