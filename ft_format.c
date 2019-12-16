/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:10:37 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:10:45 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_format	*ft_finit(void)
{
	t_format	*fmt;

	if (!(fmt = malloc(sizeof(t_format))))
		return (NULL);
	fmt->mins = 0;
	fmt->zero = 0;
	fmt->mxzr = 0;
	fmt->mxsp = 0;
	fmt->minw = 0;
	fmt->prec = -1;
	return (fmt);
}

static void		ft_zero_minus(t_format **fmt, char **f)
{
	while (*f && **f && (**f == '0' || **f == '-'))
	{
		if (**f == '0' && !(*fmt)->zero)
			(*fmt)->zero = 1;
		else if (**f == '-' && !(*fmt)->mins)
			(*fmt)->mins = 1;
		(*f)++;
	}
}

static void		ft_num_astrisk(t_format **fmt, char **f, va_list *l, char w_p)
{
	int		tmp;

	tmp = 0;
	if (*f && **f && ((**f >= '0' && **f <= '9') || **f == '-'))
	{
		tmp = ft_atoi(*f);
		while (**f >= '0' && **f <= '9')
			(*f)++;
	}
	else if (*f && **f && **f == '*')
	{
		tmp = va_arg(*l, int);
		while (**f == '*')
			(*f)++;
	}
	if (w_p == 'w')
		(*fmt)->minw = tmp;
	else if (w_p == 'p')
		(*fmt)->prec = tmp;
}

t_format		*ft_format(char **f, va_list *l)
{
	t_format	*fmt;

	if (!(fmt = ft_finit()))
		return (NULL);
	ft_zero_minus(&fmt, f);
	ft_num_astrisk(&fmt, f, l, 'w');
	if (*f && **f == '.')
	{
		(*f)++;
		ft_num_astrisk(&fmt, f, l, 'p');
		fmt->prec = fmt->prec < 0 ? -1 : fmt->prec;
	}
	if (fmt->minw < 0)
	{
		fmt->minw = -(fmt->minw);
		fmt->mins = 1;
	}
	return (fmt);
}
