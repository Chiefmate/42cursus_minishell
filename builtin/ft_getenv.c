#include "../include/builtin.h"

char *ft_getenv(t_env *env_head, char *key)
{
	t_env *cur;

	cur = compare_env_key(env_head, key);
	return (cur->value);
}