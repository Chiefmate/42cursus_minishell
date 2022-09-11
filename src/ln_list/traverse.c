/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:27:50 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/09 19:27:50 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ln_list.h"

/* traverses data from list (forward)
*/
void traverse_list(t_list *plist, void (*callback)(const t_token *))
{
	t_node	*temp;

	temp = plist->head;
	while (temp != NULL)
	{
		callback(temp->data);
		temp = temp->next;
	}
	return ;
}

/* traverses data from list (backward)
*/
// void traverse_list_r(t_list *plist, void (*callback)(const t_token *))
// {
// 	t_node	*temp;

// }
