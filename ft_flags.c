/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:10:04 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/15 21:10:16 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_find(const char *s, char c)
{
	int		i;

	if (s)
	{
		i = 0;
		while ((char)s[i])
		{
			if ((char)s[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_flags(char *fmt)
{
	char	*flgs;

	flgs = NULL;
	while ((*fmt >= '0' && *fmt <= '9') ||
	*fmt == '-' || *fmt == '.' || *fmt == '*')
		flgs = ft_appendchar(flgs, *fmt++);
	if (ft_find("%cspdiuxXD", *fmt))
	{
		flgs = ft_appendchar(flgs, *fmt);
		return (flgs);
	}
	else
		free(flgs);
	return (NULL);
}
