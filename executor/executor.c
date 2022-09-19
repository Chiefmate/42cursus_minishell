#include "../include/executor.h"

void executor(t_cmd *cmd_head, t_env *env_head)
{
  t_cmd *cmd_cur;

  cmd_cur = cmd_head;
  if (check_valid_synax(cmd_head) == -1)
    return (clear_cmd(cmd_head));
  if (init_heredoc(cmd_cur) == -1)
    return (clear_cmd(cmd_head));
}