#include "../include/builtin.h"

static int is_option_n(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strncmp(str, "-n", 2))
		return (0);
	++str;
	while (*str == 'n')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

static int check_option_n(int argc, char *argv[], int *idx)
{
	int i;
	int option_n;

	i = 1;
	option_n = 0;
	if (argc == 1) //인자의 개수가 1이면 0을 리턴
		return (0);
	option_n = is_option_n(argv[i]); // option_n이 n이 들어가있는지 확인시켜줌, 맞으면 1 리턴, 틀리면 0
	// argv[1] 을 확인한다는건데
	//  0 -> echo
	//  [1] : -n
	while (i < argc && is_option_n(argv[i]))
		++i;
	*idx = i; // i < argc, 하고 idx을 넣어준다. 왜지 ?
	return (option_n);
}

int ft_echo(int argc, char *argv[])
{
	int idx;
	int option_n;

	idx = 1;
	option_n = check_option_n(argc, argv, &idx); //인덱스값이 idx에 들어가있고 , -n이 있으면 1 없으면0
	while (idx < argc && argv[idx])
	{
		ft_write(STDOUT_FILENO, argv[idx], ft_strlen(argv[idx])); //정확한 [idx] 의 의미를 모르겠음
		if (idx + 1 != argc)
			ft_write(STDOUT_FILENO, " ", 1);
		++idx;
	}
	if (option_n == 0)
		ft_write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}

// STDOUT_FILENO->fd 값 : 1 argv[idx]->그 행을 프린트한다.