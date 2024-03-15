#ifndef __ACADEMCLASTER
#define __ACADEMCLASTER

enum claster_type
{
    THREAD,
    GROUP,
    SUBGROUP
};

/* TODO: сделать отдельные структуры для потоков, групп и подгрупп? */
struct academ_claster
{
    int students_num;       /* кол-во студентов */
    enum claster_type type; /* признак потока, группы или подгруппы */
};

#endif /* __ACADEMCLASTER */
