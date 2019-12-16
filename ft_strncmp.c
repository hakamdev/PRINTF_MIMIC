/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:34:47 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/01 16:33:06 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ss1;
	unsigned char	*ss2;
	int				cmp;

	i = 0;
	cmp = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n && (s1[i] || s2[i]))
	{
		if (ss1[i] == ss2[i])
			i++;
		else
		{
			cmp = ss1[i] - ss2[i];
			break ;
		}
	}
	return (cmp);
}
