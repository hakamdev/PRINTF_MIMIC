/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:18:17 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:18:24 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long	ft_putstr(char *s, long n, char lf)
{
	long	count;
	int		minus;
	long	i;

	count = 0;
	i = 0;
	minus = 0;
	count = n > -1 ? n : ft_strlen(s);
	if (s != NULL)
	{
		if (ft_atoi(s) < 0 && ft_find("Ddi", lf))
		{
			i++;
			minus = 1;
		}
		while (i < count && s[i])
			write(1, &s[i++], 1);
	}
	return (i - minus);
}
