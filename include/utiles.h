#ifndef UTILES_H
#define UTILES_H

#include <signal.h>
#include <sys/errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define SHE 0
#define DFL 1
#define IGN 2

void print_err(char *str);
int ft_close(int fd);
int ft_open(char *fname, int oflag, int mode);

#endif