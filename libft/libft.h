/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunhole <hyunhole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:21:16 by hyunhole          #+#    #+#             */
/*   Updated: 2021/12/03 17:08:40 by hyunhole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

extern int		ft_atoi(const char *s);
extern void		ft_bzero(void *s, size_t n);
extern void		*ft_calloc(size_t num, size_t size);
extern int		ft_isalnum(int c);
extern int		ft_isalpha(int c);
extern int		ft_isascii(int c);
extern int		ft_isdigit(int c);
extern int		ft_isprint(int c);
extern char		*ft_itoa(int n);
extern void		ft_lstadd_back(t_list **lst, t_list *new);
extern void		ft_lstadd_front(t_list **lst, t_list *new);
extern void		ft_lstclear(t_list **lst, void (*del)(void *));
extern void		ft_lstdelone(t_list *lst, void (*del)(void *));
extern void		ft_lstiter(t_list *lst, void (*f)(void *));
extern t_list	*ft_lstlast(t_list *lst);
extern t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));
extern t_list	*ft_lstnew(void *content);
extern int		ft_lstsize(t_list *lst);
extern void		*ft_memchr(const void *buf, int c, size_t count);
extern int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern void		*ft_memmove(void *dst, const void *src, size_t len);
extern void		*ft_memset(void *b, int c, size_t n);
extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putendl_fd(char *s, int fd);
extern void		ft_putnbr_fd(int n, int fd);
extern void		ft_putstr_fd(char *s, int fd);
extern char		**ft_split(char const *s, char c);
extern char		*ft_strchr(const char *s, int c);
extern char		*ft_strdup(const char *s);
extern void		ft_striteri(char *s, void (*f)(unsigned int, char *));
extern char		*ft_strjoin(char const *s1, char const *s2);
extern size_t	ft_strlcat(char *dest, const char *src, size_t size);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t size);
extern size_t	ft_strlen(const char *s);
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern char		*ft_strnstr(const char *big, const char *little, size_t len);
extern char		*ft_strrchr(const char *s, int c);
extern char		*ft_strtrim(char const *s1, char const *set);
extern char		*ft_substr(char const *s, unsigned int start, size_t len);
extern int		ft_tolower(int c);
extern int		ft_toupper(int c);

#endif
