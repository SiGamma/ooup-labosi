#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char const* (*PTRFUN)();

typedef struct {
  PTRFUN* vtable;
  char *name;
} Tiger;

char const *greet() {
  return "mijau";
}

char const *menu() {
  return "mlijeko";
}

char const *name(Tiger *tiger) {
  return tiger->name;
}

PTRFUN funTable[3] = {name, greet, menu};

void *create (char const* name) {
  Tiger *p = (Tiger *)malloc (sizeof (Tiger));
  p->name = (char *)name;
  p->vtable =(PTRFUN*) malloc (3*sizeof(PTRFUN*));
  memcpy (p->vtable, funTable, 3*sizeof(PTRFUN*));

  //printf ("%s\n", (p->vtable[0])());

  return (void*)p;
}
