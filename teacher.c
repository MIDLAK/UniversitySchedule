#include "teacher.h"
#include <stdlib.h>
#include <string.h>

struct teacher* new_teacher(int id, char* name, char* surname, char *midname)
{
    struct teacher *newteacher = malloc(sizeof(struct teacher));
    newteacher->name = malloc(strlen(name));
    newteacher->surname = malloc(strlen(surname));
    newteacher->midname = malloc(strlen(midname));

    newteacher->id = id;
    strcpy(newteacher->name, name);
    strcpy(newteacher->surname, surname);
    strcpy(newteacher->midname, midname);

    return newteacher;
}
