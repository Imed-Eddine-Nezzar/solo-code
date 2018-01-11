#include <unistd.h>
#include <err.h>

#include "dupx.h"

int main(int argc, char **argv)
{
  int dupstdout;
  if ((dupstdout = dup(STDOUT_FILENO)) == -1)
  { /* unable to duplicate STDOUT_FILENO */
    err(1, "unable to duplicate STDOUT_FILENO");
  }

  if (write(dupstdout, "dupx test\n", 10) != 10)
  { /* test failed? */
    err(1, "write() failed");
  }

  if (dup2(STDOUT_FILENO, STDIN_FILENO) == -1)
  { /* unable to make STDIN_FILENO another STDOUT_FILENO */
    err(1, "unable to make STDIN_FILENO a duplicate STDOUT_FILENO");
  }

  /* tests passed */

  if (write(STDIN_FILENO, "test passed!\n", 13) == -1)
  { /* tests passed? */
    err(1, "write(STDIN_FILENO) failed");
  }
  return 0;
}
