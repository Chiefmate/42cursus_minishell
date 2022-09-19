#include "../include/utiles.h"

int ft_open(char *fname, int oflag, int mode)
{
  int fd;

  fd = open(fname, oflag, mode);
  if (fd < 0)
    exit_with_err(fname, strerror(errno), EXIT_FAILURE);
  return (fd);
}

int ft_close(int fd)
{
  if (close(fd) == -1)
    exit_with_err("close()", strerror(errno), EXIT_FAILURE);
  return (-2);
}
