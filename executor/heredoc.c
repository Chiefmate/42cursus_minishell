#include "../include/executor.h"
static int check_heredoc(t_cmd *cmd)
{
  int idx;
  const char redir_h[3] = {-74, -74, "\0"};

  idx = -1;
  while (cmd->argv[++idx])
    if (!ft_strcmp(cmd->argv[idx], redir_h))
      break;
  if (cmd->argv[idx] == NULL)
    return (-1);
  return (idx);
}

static int do_work_heredoc(t_cmd *cmd, int lim_idx)
{
  pid_t pid;
  int ret;
  const char redir_h[3] = {-74, -74, '\0'};

  set_signal(DFL, SHE);
  pid = fork();
  if (pid == 0)
  {
    input_heredoc(cmd, lim_idx + 1);
    cmd->infile = ft_close(cmd->infile);
    exit(EXIT_SUCCESS);
  }
}

int heredoc(t_cmd *cmd_head)
{
  char *tmp_file;
  int idx;
  int exit_code;
  t_cmd *cur;

  while (1)
  {
    cur = cmd_head;
    idx = check_heredoc(cur);
    if (idx == -1)
      return (0);
    if (cur->infile > 0)
      ft_close(cur->infile);
    tmp_file = get_tmp_file_name();
    exit_code = do_work_heredoc(cur, idx);
  }
}