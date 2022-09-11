/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:12:05 by hyunhole          #+#    #+#             */
/*   Updated: 2022/09/07 17:12:05 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LN_LIST
# define LN_LIST

/* malloc, free, NULL */
# include <stdlib.h>

typedef	enum e_token_type{
	ERR = -1,
	WORD,
	PIPE,
	RD
}	t_token_type;

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

typedef	struct s_node
{
	t_token			*data;
	struct s_node	*next;
}	t_node;

typedef	struct s_list
{
	int		count;
	t_node	*head;
}	t_list;

/* list.c */
t_list	*create_list(void);
void	*destroy_list(t_node *plist);
int		search_list(t_node *plist, t_token *pargu, t_token **data_out_ptr);
int		count_list(t_list *plist);
int 	empty_list(t_list *plist);

/* node.c */
int		add_node(t_node *plist, t_token *data_ptr);
int		remove_node(t_node *plist, t_token *key_ptr, t_token **data_out_ptr);

/* token.c */
t_token *create_token(int type, char *value); 
void 	destroy_token(t_token *ptoken);
int 	cmp_token( const t_token *ptoken1, const t_token *ptoken2);
void 	print_token(const t_token *data_ptr);

/* traverse.c */
void 	traverse_list(t_list *plist, void (*callback)(const t_token *));
// void 	traverse_list_r(t_list *plist, void (*callback)(const t_token *));

/* internal.c */
int _insert(t_list *plist, t_node *p_pre, t_token *data_in_ptr);
void _delete(t_list *plist, t_node *p_pre, t_node *p_loc, t_token **data_out_ptr);
int _search(t_list *plist, t_node **p_pre, t_node **p_loc, t_token *pargu);

#endif
