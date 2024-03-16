#ifndef __TEACHER
#define __TEACHER

/* TODO: связать преподавателя с его специальностью */
struct teacher
{
    int id;
    char *name;
    char *surname;
    char *midname; /* отчество */
};

struct teacher new_teacher(int id, char *name, char *surname, char *midname);

#endif /* __TEACHER */
