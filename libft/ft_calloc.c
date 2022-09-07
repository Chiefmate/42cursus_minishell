/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:57:27 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/10 12:03:07 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  ft_memset used
void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	ret = malloc(num * size);
	if (!ret)
		return (0);
	ft_memset(ret, 0, num * size);
	return (ret);
}
