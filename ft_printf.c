/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:56:27 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/17 15:57:38 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long	ft_printf_body(char **fmt, va_list *list)
{
	char	*flgs;
	long	count;

	count = 0;
	flgs = ft_flags(*fmt);
	if (flgs)
	{
		count += ft_output(flgs, list);
		*fmt += ft_strlen(flgs);
		free(flgs);
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	list;
	long	count;
	char	*fmt;

	if (format)
		va_start(list, format);
	count = 0;
	fmt = (char *)format;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if ((count += ft_printf_body(&fmt, &list)) == -1)
				return (count);
		}
		else if (*fmt != CNULL)
			count += ft_putchar(*fmt++, 1);
	}
	va_end(list);
	return (count > MXINT ? -1 : count);
}
