/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:57:26 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:08:10 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	ft_atoi(const char *str)
{
	int			i;
	int			n;
	long long	r;
	char		*s;

	i = 0;
	r = 0;
	n = 1;
	s = (char *)str;
	while (s && *s > 0 && *s <= ' ')
	{
		if (*s == 27)
			return (INULL);
		s++;
	}
	if (s && *s == '-')
	{
		n = -1;
		s++;
	}
	else if (s && *s == '+')
		s++;
	while (s && s[i] >= '0' && s[i] <= '9')
		r = r * 10 + (s[i++] - '0');
	return (r * n);
}
