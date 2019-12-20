/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:17:47 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:17:54 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long	ft_putchar(char c, long n)
{
	unsigned char	cc;
	long			nn;

	cc = (unsigned char)c;
	nn = n;
	while (n-- > 0)
		write(1, &cc, 1);
	return (nn);
}
