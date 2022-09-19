#include "../include/executor.h"

int init_heredoc(t_cmd *cmd)
{
  t_cmd *cur;

  cur = cmd;
  while (cur)
  {
    if (heredoc(cur) == -1)
      return (-1);
    cur = cur->next;
  }
  return (0);
}