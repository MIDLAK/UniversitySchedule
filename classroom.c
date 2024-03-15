#ifndef __CLASSROOM
#define __CLASSROOM

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
    int room_number;
    int building_number; /* номер корпуса */
    int capacity;
    enum rtype type;
    int department;      /* к какой кафедре относится аудитория */
};

#endif /* __CLASSROOM */
