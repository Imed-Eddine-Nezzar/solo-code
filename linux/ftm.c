/*
 * feature test macros
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) 
{
#ifdef _POSIX_SOURCE
  puts("_POSIX_SOURCE defined");
#endif

#ifdef _POSIX_C_SOURCE
  printf("_POSIX_C_SOURCE defined: %ld\n", (long) _POSIX_C_SOURCE);
#endif

#ifdef _ISOC99_SOURCE
  puts("_ISOC99_SOURCE defined");
#endif // _ISOC99_SOURCE

#ifdef _ISOC11_SOURCE
  puts("_ISOC11_SOURCE defined");
#endif // _ISOC11_SOURCE

#ifdef _XOPEN_SOURCE
  printf("_XOPEN_SOURCE defined: %ld\n", (long)_XOPEN_SOURCE);
#endif // _XOPEN_SOURCE

#ifdef _XOPEN_SOURCE_EXTENDED
  puts("_XOPEN_SOURCE_EXTENDED defined");
#endif // _XOPEN_SOURCE_EXTENDED

#ifdef _BSD_SOURCE
  puts("_BSD_SOURCE defined");
#endif // _BSD_SOURCE

#ifdef _SVID_SOURCE
  puts("_SVID_SOURCE defined");
#endif // _SVID_SOURCE

#ifdef _DEFAULT_SOURCE
  puts("_DEFAULT_SOURCE defined");
#endif // _DEFAULT_SOURCE

#ifdef _ATFILE_SOURCE
  puts("_ATFILE_SOURCE defined");
#endif // _ATFILE_SOURCE

#ifdef _GNU_SOURCE
  puts("_GNU_SOURCE defined");
#endif // _GNU_SOURCE

#ifdef _THREAD_SAFE
  puts("_THREAD_SAFE defined");
#endif // _THREAD_SAFE

  return EXIT_SUCCESS;
}
