/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:16:21 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:16:26 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_o_num(t_format *f, char *data, char lf)
{
	size_t	count;

	count = 0;
	if (!(f->mins))
		count += ft_putchar(' ', f->mxsp);
	if (ft_atoi(data) < 0)
		count += ft_putchar('-', 1);
	count += ft_putchar('0', f->mxzr);
	count += ft_putstr(data, -1, lf);
	if (f->mins)
		count += ft_putchar(' ', f->mxsp);
	return (count);
}

static int	ft_o_string(t_format *f, char *data, char lf)
{
	size_t	count;

	count = 0;
	if (!(f->mins))
		count += ft_putchar(' ', f->mxsp);
	count += ft_putchar('0', f->mxzr);
	count += ft_putstr(data, f->prec, lf);
	if (f->mins)
		count += ft_putchar(' ', f->mxsp);
	return (count);
}

static int	ft_o_char(t_format *f, char *data)
{
	size_t	count;

	count = 0;
	if (!(f->mins))
		count += ft_putchar(' ', f->mxsp);
	if (f->zero && !(f->mins) && f->mxzr)
		count += ft_putchar('0', f->mxzr);
	count += ft_putchar(*data, 1);
	if (f->mins)
		count += ft_putchar(' ', f->mxsp);
	return (count);
}

static int	ft_o_hex(t_format *f, char *data, char lf)
{
	size_t	count;

	count = 0;
	if (!(f->mins))
		count += ft_putchar(' ', f->mxsp);
	count += ft_putchar('0', f->mxzr);
	count += ft_putstr(data, -1, lf);
	if (f->mins)
		count += ft_putchar(' ', f->mxsp);
	return (count);
}

int			ft_output(char *flgs, va_list *l)
{
	size_t		count;
	t_format	*f;
	char		*data;
	char		lf;

	count = 0;
	lf = flgs[ft_strlen(flgs) - 1];
	f = ft_format(&flgs, l);
	data = ft_data(lf, l, f->prec);
	ft_spacing(&f, data, lf);
	if (ft_find("Ddiu", lf))
		count += ft_o_num(f, data, lf);
	else if (ft_find("s", lf))
		count += ft_o_string(f, data, lf);
	else if (ft_find("Xxp", lf))
		count += ft_o_hex(f, data, lf);
	else if (ft_find("%c", lf))
		count += ft_o_char(f, data);
	free(data);
	free(f);
	return (count);
}
