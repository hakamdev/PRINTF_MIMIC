/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:25:22 by ehakam            #+#    #+#             */
/*   Updated: 2019/12/16 15:25:41 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
