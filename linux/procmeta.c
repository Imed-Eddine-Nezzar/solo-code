#include <stdio.h>
/* #define _GNU_SOURCE */
#define __USE_GNU
#include <errno.h>

extern char etext,    /* &etext: end address of text segment*/
            edata,    /* &edata: end address of initialized data segment*/
            end;      /* &end: end address of unintialized data segment */

extern char **environ;  /* environment variables */

int main()
{
  printf("program name (long):  %s\n"
         "program name (short): %s\n\n",
         program_invocation_name,
         program_invocation_short_name);

  printf("end of text segment:                %p\n"
         "end of initialized data segment:    %p\n"
         "end of uninitialized data segment:  %p\n",
         &etext, &edata, &end);

  printf("envrionment variables:\n");
  for (char **env = environ; *env; ++env)
    puts(*env);

  return 0;
}
