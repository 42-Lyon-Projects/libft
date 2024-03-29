/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimmy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:20:20 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/19 15:45:26 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_is_space(int character);
int				ft_is_sign(int character);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
long			ft_atoi_long(const char *nptr);
long long		ft_ll_overflow_atoi(const char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_putchar_fd(char c, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_put_unsigned_nbr_fd(unsigned int n, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_base(long long int number, int base_number, \
char base_array[], int value);

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_str_tab_len(char **tab);

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putendl_fd(char *s, int fd);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *hs, const char *needle, size_t len);
char			*ft_strdup(const char *source);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
void			ft_free_split(char **words_list);

/* BONUS PART */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));

/* GNL PART */

typedef enum t_boolean
{
	_false,
	_true
}	t_boolean;

enum t_boolean	ft_has_new_line(char *buffer, char **returned_line);

void			ft_mem_switch(char *buffer, int len);
void			ft_fill_of_zero(char *buffer, int index);
char			*ft_str_join(char *r_line, char *buf, int ch_read, int l_line);
char			*ft_growth_line(char *r_line, char *buf, int ch_readed);
char			*get_next_line(int file_descriptor);

/* PRINTF PART */
int				ft_printf(const char *str, ...);
int				ft_args_handler(char c, va_list params);
int				ft_get_char(va_list param);
int				ft_get_string(va_list param);
int				ft_get_integer(va_list param);
int				ft_get_unsigned_integer(va_list param);
int				ft_get_address(va_list param, char *base_array);
int				ft_get_base16(va_list param, char *base);

#endif
