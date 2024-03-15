#ifndef __ROOM
#define __ROOM

#include "department.h"

enum rtype 
{
    BIG_LECTURE,    /* более 3-х групп */
    MEDIUM_LECTURE, /* 3 группы */
    SMALL_LECTURE,  /* мньше 3-х групп */
    PRACTICAL,
    LABORATORY
};

struct room 
{
    int room_num;
    int building_num;                /* номер корпуса */
    int capacity;
    enum rtype type;
    struct department *department;   /* к какой кафедре относится аудитория */
};

struct room* rooms_generate(int rooom_num, int building_num, int max_capacity, 
        int min_capacity, struct department *departments);

#endif /* __CLASSROOM */
