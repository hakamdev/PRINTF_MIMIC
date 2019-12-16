/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:40:43 by ehakam            #+#    #+#             */
/*   Updated: 2019/10/24 00:05:12 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*sc;
	unsigned char	*dst;

	i = 0;
	sc = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if ((dst == NULL && src == NULL) || n == 0)
		return (dst);
	if (sc == dst)
		return (dst);
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	st;

	if (!s)
		return (NULL);
	st = ft_strlen(s);
	if (!(ss = (char *)malloc(st + 1)))
		return (NULL);
	ft_memcpy(ss, s, st);
	*(ss + st) = CNULL;
	return (ss);
}
