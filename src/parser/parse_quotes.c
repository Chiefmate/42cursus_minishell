/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:32:25 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/17 14:32:25 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_quotes(char c, int quotes, t_cmd *cmd)
{
	int	ret;

	ret = quotes;
	if (c == '$')
		cmd->is_dollar = true;
	else if (c == '\'')
	{
		if (quotes == 1)
			ret = 0;
		else if (quotes == 2)
			ret = 2;
		else
			ret = 1;
	}
	else if (c == '\"')
	{
		if (quotes == 2)
			ret = 0;
		else if (quotes == 1)
			ret = 1;
		else
			ret = 2;
	}
	return (ret);
}