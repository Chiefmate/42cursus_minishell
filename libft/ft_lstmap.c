/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:07:17 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/11 12:29:01 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	ft_lstnew, ft_lstadd_back, ft_lstclear used
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*reader;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	reader = lst;
	ret = ft_lstnew(f(reader->content));
	if (!ret)
		return (0);
	reader = reader->next;
	while (reader)
	{
		temp = ft_lstnew(f(reader->content));
		if (!temp)
		{
			ft_lstclear(&ret, del);
			return ((void *)0);
		}
		ft_lstadd_back(&ret, temp);
		reader = reader->next;
	}
	return (ret);
}
