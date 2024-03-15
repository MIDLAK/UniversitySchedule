#include <stdio.h>
#include <stdlib.h>

#include "../headers/teacher.h"

int main(int argc, char **argv)
{
    struct teacher *pavel = new_teacher(100, "Павел", "Ананьев", "Иванович");

    printf("%d: %s %s %s", pavel->id, pavel->surname, pavel->name, pavel->midname);

    return 0;
}
