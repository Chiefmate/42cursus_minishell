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

typedef	enum e_token_name{
	ERR = -1,
	WORD,
	PIPE,
	RD
}	t_token_name;

typedef struct s_token
{
	int		name;
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

t_node	*create_list(void);
void	*destroy_list(t_node *plist);
int		add_node(t_node *plist, t_token *data_ptr);
int		remove_node(t_node *plist, t_token *key_ptr, t_token **data_out_ptr);
int		search_list(t_node *plist, t_token *p_argu, t_token **data_out_ptr);
int		count_list(t_node *plist);

////////////////////////////////////////////////////////////////////////////////
// Prototype declarations

/* Allocates dynamic memory for a list head node and returns its address to caller
	return	head node pointer
			NULL if overflow
*/
t_list *createList(void);

/* Deletes all data in list and recycles memory
*/
void destroyList( t_list *pList);

/* Inserts data into list
	return	0 if overflow
			1 if successful
			2 if duplicated key
*/
int addNode( t_list *pList, t_token *dataInPtr);

/* Removes data from list
	return	0 not found
			1 deleted
*/
int removeNode( t_list *pList, t_token *keyPtr, t_token **dataOutPtr);

/* interface to search function
	Argu	key being sought
	dataOut	contains found data
	return	1 successful
			0 not found
*/
int searchList( t_list *pList, t_token *pArgu, t_token **dataOutPtr);

/* returns number of nodes in list
*/
int countList( t_list *pList);

/* returns	1 empty
			0 list has data
*/
int emptyList( t_list *pList);

/* traverses data from list (forward)
*/
void traverseList( t_list *pList, void (*callback)(const t_token *));

/* traverses data from list (backward)
*/
void traverseListR( t_list *pList, void (*callback)(const t_token *));

/* internal insert function
	inserts data into a new node
	return	1 if successful
			0 if memory overflow
*/
static int _insert( t_list *pList, NODE *pPre, t_token *dataInPtr);

/* internal delete function
	deletes data from a list and saves the (deleted) data to dataOut
*/
static void _delete( t_list *pList, NODE *pPre, NODE *pLoc, t_token **dataOutPtr);

/* internal search function
	searches list and passes back address of node
	containing target and its logical predecessor
	return	1 found
			0 not found
*/
static int _search( t_list *pList, NODE **pPre, NODE **pLoc, t_token *pArgu);

////////////////////////////////////////////////////////////////////////////////
/* Allocates dynamic memory for a name structure, initialize fields(name, freq) and returns its address to caller
	return	name structure pointer
			NULL if overflow
*/
t_token *createName( char *str, char sex, int freq); 

/* Deletes all data in name structure and recycles memory
*/
void destroyName( t_token *pNode);

#endif
