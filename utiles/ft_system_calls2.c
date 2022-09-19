#include "../include/utiles.h"

void *ft_malloc(size_t size, size_t n)
{
  void *ret;

  ret = malloc(size * n);
  if (ret == NULL)
    exit_with_err("malloc()", strerror(errno), EXIT_FAILURE);
  return (ret);
}