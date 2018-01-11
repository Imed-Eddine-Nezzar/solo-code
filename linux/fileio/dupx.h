#ifndef _DUPX_H
#define _DUPX_H

#include <unistd.h>  /* close() */
#include <fcntl.h>  /* fcntl() */
#include <errno.h>  /* errno */

int dup(int oldfd)
{
  return fcntl(oldfd, F_DUPFD, 0);
}

int dup2(int oldfd, int newfd)
{
  if (fcntl(oldfd, F_GETFL) != -1)
  { /* newfd refers an open file descriptor */
    if (close(newfd) == -1)
    { /* error closing file */
      return -1;
    }
  }

  if ((newfd = fcntl(oldfd, F_DUPFD, newfd)) == -1)
  {
    if (errno == EINVAL)
    { /* newfd < 0 or newfd > RLIMIT_NOFILE */
      errno = EBADF;
    }
    return -1;
  }

  return newfd;
}

#endif /* _DUPX_H */
