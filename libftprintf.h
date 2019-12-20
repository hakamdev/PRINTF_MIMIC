/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:49:16 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/16 15:20:52 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef CNULL
#  define CNULL '\0'
# endif

# ifndef MXINT
#  define MXINT 2147483647
# endif

typedef struct	s_format
{
	int		zero;
	int		mins;
	int		minw;
	int		prec;
	int		mxzr;
	int		mxsp;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_find(const char *s, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long			ft_output(char *flgs, va_list *l);
long			ft_putchar(char c, long n);
long			ft_putstr(char *s, long n, char lf);
char			*ft_itoh(size_t value, int flg);
char			*ft_appendchar(char *str, char c);
char			*ft_flags(char *fmt);
char			*ft_itoa(long long n);
char			*ft_strdup(const char *s);
void			ft_spacing(t_format **fmt, char *data, char f);
void			*ft_data(char flg, va_list *l, int prec);
void			*ft_memcpy(void *dest, const void *src, size_t n);
t_format		*ft_format(char **f, va_list *l);
long long		ft_atoi(const char *str);
size_t			ft_strlen(const char *s);

#endif
