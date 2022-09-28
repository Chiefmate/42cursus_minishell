#ifndef BUILTIN_H
#define BUILTIN_H

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "struct.h"
#include "../libft/libft.h"

/* cd_utils.c */
char *get_pwd_key_value(const char *key);
void export_pwd(const char *pwd, t_env *env_head);

/* env_utils.c */
char *get_env_key(char *key_value);
char *get_env_value(char *key_value);
t_env *compare_env_key(t_env *env_head, char *key);
t_env *new_env(char *key_value);
int init_env_list(t_env *cur, char *envp[]);

/* ft_cd.c */
int ft_cd(char *path, t_env *env_head);

/* ft_echo.c */
int ft_echo(int argc, char *argv[]);

/* ft_env.c */
int ft_env(t_env *cur);

/* ft_exit.c */
int ft_exit(t_cmd *cmd);

/* ft_export_check_valid.c */
int is_starting_with_digit(char *key_value);
int is_have_space(char *key_value, char set);
int is_have_specific_char(char *key_value, char c);
int check_valid_identifier(int argc, char *argv[]);

/* ft_export_no_arg_utils.c */
t_env *dup_env_list(t_env *cur);
t_env *sort_env_list(t_env *head);
void free_env_list(t_env *env);

/* ft_export.c */
void export_key_value(t_env *env_head, char *key_value);
int ft_export(int argc, char *argv[], t_env *env_head);

/* ft_getenv.c */
char *ft_getenv(t_env *env_head, char *key);

/* ft_pwd.c */
int ft_pwd(void);

/* ft_unset.c */
int ft_unset(int argc, char *argv[], t_env *env_head);

#endif