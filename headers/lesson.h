#ifndef __LESSON
#define __LESSON

#include "teacher.h"
#include "discipline.h"
#include "academclaster.h"
#include "room.h"

/* типов занятий в перспективе больше, чем типов аудиторий */
enum ltype
{
    LECTURE,
    PRACTICE,
    LAB
};

/* TODO: подумать про интенсивность занятий */
struct lessons_cycle
{
    struct teacher        *teacher;
    struct discipline     *discipline;
    struct academ_claster *claster;     /* подгруппа, группа или поток */

    enum ltype type;

    int length;    /* число занятий в цикле */
    int intensity; /* 1 - одно занятие в неделю, 2 - два занятия в неделю, ... */  
};

#endif /* __LESSON */
