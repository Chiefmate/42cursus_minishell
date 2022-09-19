/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:25:00 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/09 19:25:00 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ln_list.h"

/* internal insert function
	inserts data into a new node
	return	1 if successful
			0 if memory overflow
*/
int _insert(t_list *plist, t_node *p_pre, t_token *data_in_ptr)
{
	t_node	*p_new;

	p_new = (t_node *)malloc(sizeof(t_node));
	if (!p_new)
		return (0);
	p_new->data = data_in_ptr;
	if (plist->count == 0)
	{
		p_new->next = NULL;
		plist->head = p_new;
	}
	else if (!p_pre)
	{
		p_new->next = plist->head;
		plist->head = p_new;
	}
	else
	{
		p_new->next = p_pre->next;
		p_pre->next = p_new;
	}
	plist->count++;
	return (1);
}

/* internal delete function
	deletes data from a list and saves the (deleted) data to dataOut
*/
void _delete(t_list *plist, t_node *p_pre, t_node *p_loc, t_token **data_out_ptr)
{
	(*data_out_ptr) = create_token(p_loc->data->type, p_loc->data->value);
	if (!p_pre)
	{
		plist->head = p_loc->next;
	}
	else
	{
		p_pre->next = p_loc->next;
	}
	p_loc->next = NULL;
	destroy_token(p_loc->data);
	p_loc->data = NULL;
	free(p_loc);
	plist->count--;
	return ;
}

/* internal search function
	searches list and passes back address of node
	containing target and its logical predecessor
	return	1 found
			0 not found
*/
int _search(t_list *plist, t_node **p_pre, t_node **p_loc, t_token *pargu)
{
	int	ret;

	*p_pre = NULL;
	*p_loc = plist->head;
	while (*p_loc && cmp_token(pargu, (*p_loc)->data) > 0)
	{
		*p_pre = *p_loc;
		*p_loc = (*p_loc)->next;
	}
	if (!(*p_loc))
		ret = 0;
	else
	{
		if (!cmp_token(pargu, (*p_loc)->data))
			ret = 1;
		else
			ret = 0;
	}
	return (ret);
}
