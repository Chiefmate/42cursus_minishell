/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:24:54 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/09 19:24:54 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ln_list.h"

/* Allocates dynamic memory for a list head node and returns its address to caller
	return	head node pointer
			NULL if overflow
*/
t_list *create_list(void)
{
	t_list *ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (0);
	ret->count = 0;
	ret->head = NULL;
	return (ret);
}

/* Deletes all data in list and recycles memory
*/
void destroy_list(t_list *plist)
{
	t_node	*temp;

	while (plist->head)
	{
		temp = plist->head;
		plist->head = plist->head->next;
		destroy_token(temp->data);
		free(temp);
	}
	plist->count = 0;
	free(plist);
	return ;
}

/* interface to search function
	Argu	key being sought
	dataOut	contains found data
	return	1 successful
			0 not found
*/
int search_list(t_list *plist, t_token *pargu, t_token **data_out_ptr)
{
	int		ret;
	t_node	*p_pre;
	t_node	*p_loc;

	ret = _search(plist, &p_pre, &p_loc, pargu);
	if (!ret)
		return (0);
	*data_out_ptr = p_loc->data;
	return (1);
}

/* returns number of nodes in list
*/
int count_list(t_list *plist)
{
	return (plist->count);
}

/* returns	1 empty
			0 list has data
*/
int empty_list(t_list *plist)
{
	return (plist->count == 0);
}