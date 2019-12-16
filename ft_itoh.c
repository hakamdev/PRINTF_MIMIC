/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:15:15 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:15:21 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	c;

	i = 0;
	length = ft_strlen(str) - 1;
	while (i < length)
	{
		c = str[i];
		str[i] = str[length];
		str[length] = c;
		length--;
		i++;
	}
	return (str);
}

char		*ft_appendchar(char *str, char c)
{
	int		len;
	char	*tmp;

	if (!str)
	{
		if (!(str = malloc(2)))
			return (NULL);
		str[0] = c;
		str[1] = CNULL;
		return (str);
	}
	len = ft_strlen(str);
	tmp = str;
	if (!(str = malloc(len + 2)))
		return (NULL);
	ft_memcpy(str, tmp, len);
	str[len] = c;
	str[len + 1] = CNULL;
	free(tmp);
	return (str);
}

char		*ft_itoh(size_t value, int flg)
{
	char	*hex;
	char	*out;
	int		i;

	out = NULL;
	hex = "0123456789abcdef";
	if (value == (size_t)0)
		out = ft_appendchar(out, '0');
	while (value > (size_t)0)
	{
		i = value % 16;
		if (hex[i] >= 'a' && hex[i] <= 'f')
			out = ft_appendchar(out, hex[i] -
					(flg == 'X' ? 32 : 0));
		else
			out = ft_appendchar(out, hex[i]);
		value /= 16;
	}
	if (flg == 'p')
	{
		out = ft_appendchar(out, 'x');
		out = ft_appendchar(out, '0');
	}
	out = ft_strrev(out);
	return (out);
}
