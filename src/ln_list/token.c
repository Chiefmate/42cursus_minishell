/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:29:03 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/09 19:29:03 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ln_list.h"

/* Allocates dynamic memory for a token structure, initialize fields(type, value) and returns its address to caller
	return	token structure pointer
			NULL if overflow
*/
t_token *create_token(int type, char *value)
{
	t_token	*ret;

	ret = (t_token *)malloc(sizeof(t_token));
	if (!ret)
		return (0);
	ret->type = type;
	ret->value = value;
	return (ret);
}

/* Deletes all data in token structure and recycles memory
*/
void destroy_token(t_token *ptoken)
{
	if (!ptoken)
		return ;
	if (!(ptoken->value))
		free(ptoken->value);
	free(ptoken);
	return ;
}

// compares two names in token structures
// for create_token function
int cmp_token( const t_token *ptoken1, const t_token *ptoken2)
{
	int	ret;

	ret = ft_strcmp(ptoken1->value, ptoken2->value);
	if (!ret)
		return (ptoken1->type - ptoken2->type);
	else
		return (ret);
}

// prints contents of token structure
// for traverse_list and traverse_list_r functions
void print_token(const t_token *data_ptr)
{
	printf("%d\t%s\n", data_ptr->type, data_ptr->value);
	return ;
}