/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:03:23 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 19:03:10 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

//	limits.h used for INT_MIN
void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	if (n == INT_MIN)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd((-1) * (n % 10), fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		temp = '0' + n;
		write(fd, &temp, 1);
	}
	return ;
}
