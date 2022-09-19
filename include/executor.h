#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "./struct.h"
#include "../include/utiles.h"
#include <sys/types.h>
#include <fcntl.h>

void trim_cmd_argv(t_cmd *cmd, const char *set, int size);

#endif