#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char const* (*PTRFUN)();

typedef struct {
  PTRFUN* vtable;
  char *name;
} Parrot;

char const *greet() {
  return "mijau";
}

char const *menu() {
  return "konzerviranu tunjevinu";
}

char const *name() {
  return "ime";
}

PTRFUN funTable[3] = {name, greet, menu};

void *create (char const* name) {
  Parrot *p = (Parrot *)malloc (sizeof (Parrot));
  p->name = name;
  p->vtable = funTable;

  return p;
}
