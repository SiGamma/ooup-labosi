#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>


typedef char const* (*PTRFUN)();
struct Animal{
  PTRFUN* vtable;
  // vtable entries:
  // 0: char const* name(void* this);
  // 1: char const* greet();
  // 2: char const* menu();
};

void* myfactory(char const* libname, char const* ctorarg) {
  char *filename = (char *)malloc ((strlen(libname) + 4) * sizeof(char));
  void *handle;
  void *(*create)();
  char *error;
  void *result;

  sprintf (filename, "./%s.so", libname);

  handle = dlopen (filename, RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit (-1);
  }
  dlerror();


  *(void **) (&create) = dlsym(handle, "create");

  if ((error = dlerror()) != NULL) {
    fprintf (stderr, "%s\n", error);
    exit (-1);
  }

  result = (*create)(ctorarg);


  return result;
}
