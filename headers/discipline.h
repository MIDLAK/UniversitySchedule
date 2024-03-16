#ifndef __DISCIPLINE
#define __DISCIPLINE

struct discipline {
    int id;
    char *name;
};

struct discipline new_discipline(int id, char *name);

#endif /* __DISCIPLINE */
