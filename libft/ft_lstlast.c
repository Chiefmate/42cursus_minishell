/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:05:35 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 16:40:16 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	handled empty list
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;
	t_list	*cursor;

	ret = lst;
	cursor = lst;
	while (cursor)
	{
		ret = cursor;
		cursor = cursor->next;
	}
	return (ret);
}
