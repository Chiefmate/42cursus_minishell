/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:25:04 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/09 19:25:04 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ln_list.h"

/* Inserts data into list
	return	0 if overflow
			1 if successful
*/
int add_node(t_list *plist, t_token *data_in_ptr)
{
	t_node	*p_pre;
	t_node	*p_loc;
	int		ret;

	ret = 0;
	p_pre = NULL;
	p_loc = plist->head;
	while (p_loc)
	{
		p_pre = p_loc;
		p_loc = p_loc->next;
	}
	ret = _insert(plist, p_pre, data_in_ptr);
	return (ret);
}

/* Removes data from list
	return	0 not found
			1 deleted
*/
int remove_node(t_list *plist, t_token *key_ptr, t_token **data_out_ptr)
{
	int		ret;
	t_node	*p_pre;
	t_node	*p_loc;

	ret = _search(plist, &p_pre, &p_loc, key_ptr);
	if (!ret)
		return (0);
	else
		_delete(plist, p_pre, p_loc, data_out_ptr);
	return (1);
}
