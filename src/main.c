#include <stdio.h>
#include <stdlib.h>

#include "../headers/teacher.h"
#include "../headers/schedule.h"

int main(int argc, char **argv)
{
    struct teacher *pavel = new_teacher(100, "Павел", "Ананьев", "Иванович");
    printf("[debug] id = %d: %s %s %s", pavel->id, pavel->surname, pavel->name, pavel->midname);

    /*
#define GEN_IN_ONE_CHROMOSOME 2 
    struct gene *gene = malloc(sizeof(struct gene) * GEN_IN_ONE_CHROMOSOME);
    */

    return 0;
}
