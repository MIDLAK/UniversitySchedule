#include "../headers/discipline.h"

#include <string.h>
#include <stdlib.h>

struct discipline new_discipline(int id, char *name)
{
    struct discipline disc;
    disc.name = malloc(strlen(name));

    disc.id = id;
    strcpy(disc.name, name);

    return disc;
}
