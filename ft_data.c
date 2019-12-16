/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:08:45 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:09:06 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			ft_data_zero(char **d, int prec)
{
	if (*d && !ft_strncmp(*d, "0", 3) && prec == 0)
	{
		free(*d);
		*d = ft_strdup("");
	}
	else if (*d && !ft_strncmp(*d, "0x0", 3) && prec == 0)
	{
		free(*d);
		*d = ft_strdup("0x");
	}
}

void			*ft_data(char flg, va_list *l, int prec)
{
	char	*tmp;

	if (ft_find("s", flg))
	{
		tmp = va_arg(*l, char *);
		tmp = ft_strdup(tmp ? tmp : "(null)");
	}
	else if (ft_find("Ddi", flg))
		tmp = ft_itoa(va_arg(*l, int));
	else if (ft_find("c", flg))
		tmp = ft_appendchar(NULL, va_arg(*l, int));
	else if (ft_find("Xx", flg))
		tmp = ft_itoh(va_arg(*l, unsigned int), flg);
	else if (ft_find("p", flg))
		tmp = ft_itoh(va_arg(*l, size_t), flg);
	else if (flg == 'u')
		tmp = ft_itoa(va_arg(*l, unsigned));
	else if (flg == '%')
		tmp = ft_appendchar(NULL, flg);
	else
		tmp = NULL;
	ft_data_zero(&tmp, prec);
	return (tmp);
}
