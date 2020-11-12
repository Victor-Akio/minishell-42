/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:08:42 by vminomiy          #+#    #+#             */
/*   Updated: 2020/03/03 17:50:14 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;

void				*ft_memmove(void *dst, const void *src,
						unsigned long int len);
void				ft_bzero(void *s, unsigned long int n);
unsigned long int	ft_strlen(const char *s);
unsigned long int	ft_strlcat(char *dst, const char *src,
						unsigned long int size);
unsigned long int	ft_strlcpy(char *dst, const char *src, size_t size);
void				*ft_memset(void *b, int c, unsigned long int len);
int					ft_strncmp(const char *s1, const char *s2,
						unsigned long int n);
char				*ft_strnstr(const char *haystack, const char *needle,
						unsigned long int len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memcpy(void *dst, const void *src, unsigned long int n);
void				*ft_memccpy(void *dst, const void *src, int c,
						unsigned long int n);
void				*ft_memchr(const void *s, int c, unsigned long int n);
int					ft_memcmp(const void *s1, const void *s2,
						unsigned long int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *src);
void				*ft_calloc(unsigned long int count,
						unsigned long int size);
int					ft_atoi(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_itoa(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_putchar(int c);
char				*ft_strlowcase(char *str);
int					ft_isupper(int c);
char				*ft_strnew(size_t size);
int					ft_isspace(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isxdigit(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **str);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
char				ft_str_is_alpha(char *str);
char				ft_str_is_lowercase(char *str);
char				ft_str_is_uppercase(char *str);
char				ft_str_is_printable(char *str);
char				ft_str_is_numeric(char *str);
char				*ft_strcapitalize(char *str);
int					ft_strcasecmp(char const *s1, char const *s2);
char				*ft_strcasestr(char const *haystack,
						char const *needle);
char				*ft_strcat(char *dest, char *src);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				ft_strequ(const char *str1, const char *str2);
void				ft_inter(char *s1, char *s2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strncat(char *dest, char *src, int nb);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strupcase(char *str);
char				*strtok(char *str, const char *sep);
char				*ft_itoa_base(int value, int base);

#endif
