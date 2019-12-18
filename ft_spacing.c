/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:17:06 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/17 21:01:21 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_spacing_num(t_format **fmt, char *data, size_t len)
{
	int		mxzr;
	int		mxsp;

	mxzr = 0;
	mxsp = 0;
	if ((*fmt)->zero && !(*fmt)->mins && (*fmt)->prec < 0)
		mxzr = (*fmt)->minw - len;
	else if ((*fmt)->prec >= 0)
		mxzr = (*fmt)->prec - len;
	if (mxzr < 0)
		mxzr = 0;
	if (ft_atoi(data) < 0 && ((*fmt)->prec) >= (long)len)
		mxzr += 1;
	mxsp = (*fmt)->minw - (mxzr + len);
	(*fmt)->mxzr = mxzr >= 0 ? mxzr : 0;
	(*fmt)->mxsp = mxsp >= 0 ? mxsp : 0;
}

void	ft_spacing_string(t_format **fmt, size_t len)
{
	int		mxzr;
	int		mxsp;

	mxzr = 0;
	mxsp = 0;
	if ((*fmt)->zero && !(*fmt)->mins)
		mxzr = (*fmt)->minw - len;
	if (mxzr < 0)
		mxzr = 0;
	mxsp = (*fmt)->minw - (mxzr + len);
	(*fmt)->mxzr = mxzr >= 0 ? mxzr : 0;
	(*fmt)->mxsp = mxsp >= 0 ? mxsp : 0;
}

void	ft_spacing_hex(t_format **fmt, size_t len)
{
	int		mxzr;
	int		mxsp;

	mxzr = 0;
	mxsp = 0;
	if ((*fmt)->zero && !(*fmt)->mins && (*fmt)->prec < 0)
		mxzr = (*fmt)->minw - len;
	else if ((*fmt)->prec >= 0)
		mxzr = (*fmt)->prec - len;
	if (mxzr < 0)
		mxzr = 0;
	mxsp = (*fmt)->minw - (mxzr + len);
	(*fmt)->mxzr = mxzr >= 0 ? mxzr : 0;
	(*fmt)->mxsp = mxsp >= 0 ? mxsp : 0;
}

void	ft_spacing_char(t_format **fmt)
{
	int		mxzr;
	int		mxsp;

	mxzr = 0;
	mxsp = 0;
	if ((*fmt)->zero && !((*fmt)->mins) && (*fmt)->minw)
		mxzr = (*fmt)->minw - 1;
	else if ((*fmt)->minw)
		mxsp = (*fmt)->minw - 1;
	(*fmt)->mxzr = mxzr >= 0 ? mxzr : 0;
	(*fmt)->mxsp = mxsp >= 0 ? mxsp : 0;
}

void	ft_spacing(t_format **fmt, char *data, char f)
{
	long	lent;
	long	len;
	int		prec;

	lent = ft_strlen(data);
	prec = (*fmt)->prec;
	len = f == 's' && prec < lent && prec > -1 ? prec : lent;
	if (f == 's')
		ft_spacing_string(fmt, len);
	else if (ft_find("%c", f))
		ft_spacing_char(fmt);
	else if (ft_find("Ddiu", f))
		ft_spacing_num(fmt, data, len);
	else if (ft_find("xXp", f))
		ft_spacing_hex(fmt, len);
}
