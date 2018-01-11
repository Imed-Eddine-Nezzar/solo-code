#include <stdio.h>
#include <getopt.h>
#include <fcntl.h>    /* open, close */
#include <unistd.h>   /* write, read, STDIN_FILENO, STDOUT_FILENO */
#include <sys/stat.h> /* O_I*, S_I* */
#include <err.h>      /* err() */

#define OPT_APND 0x1
#define OPT_IGNI 0x2
#define OPT_DIAG 0x4

/* prototypes */
void exit_usage(const char *);

int main(int argc, char **argv)
{
  if (argc < 2)
    exit_usage(*argv);

  /* options mask */
  short optmsk = 0;
  int opt;
  while ((opt = getopt(argc, argv, "aip")) != -1)
  {
    switch (opt)
    {
      case 'a':   /* append to file */
        optmsk |= OPT_APND;
        break;
      case 'i':   /* ignore inturrupts */
        optmsk |= OPT_IGNI;
        break;
      case 'p':   /* diagnose errors */
        optmsk |= OPT_DIAG;
        break;
      default:
        exit_usage(*argv);
    }
  }

  int oflgs = O_WRONLY |    /* write only */
              O_CREAT  |    /* create if not found */
              ((optmsk & OPT_APND) ?
                O_APPEND :  /* don't overwrite, append */
                0);

  if (optmsk & OPT_IGNI)
  { /* not implemented */
  }

  if (optmsk & OPT_DIAG)
  { /* not implemented */
  }

  /* file creation mode -rw-rw-r-- */
  mode_t m = S_IRUSR | S_IWUSR |  /* user */
             S_IRGRP | S_IWGRP |  /* group */
             S_IROTH;             /* other */

  int ofd;
  if ((ofd = open(argv[optind], oflgs, m)) == -1)
  { /* failed to open file */
    err(1, "open() failed: Can't open file %s", argv[optind]);
  }

#define RDBUFFSIZE 1024
  char buf[RDBUFFSIZE];
  ssize_t rd;
  ssize_t wr;
  while ((rd = read(STDIN_FILENO, buf, RDBUFFSIZE)) > 0)
  {
    if (((wr = write(ofd, buf, rd)) != rd) ||
        ((wr = write(STDOUT_FILENO, buf, rd)) != rd))
    { /* failed to write to file descriptor */
      err(1, "write() failed");
    }
  }

  if (rd == -1)
  { /* failed to read from file */
    err(1, "read() failed");
  }

  /* no errors */
  close(ofd);
  return 0;
}

#include <stdlib.h>

void exit_usage(const char *prgm)
{
  fprintf(stderr, "Usage: %s [-i][-p][-a] FILE\n"
                  "\t-a\t append to the given FILE, do not overwrite.\n"
                  "\t-i\t ignore inturrupt singnals.\n"
                  "\t-p\t diagnose errors writing to non pipes.\n"
                  , prgm);
  exit(EXIT_FAILURE);
}
