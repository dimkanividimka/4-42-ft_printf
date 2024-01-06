/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:25:32 by dmytro            #+#    #+#             */
/*   Updated: 2023/07/02 15:16:48 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(va_list args, char ftype)
{
	int	res;

	res = 0;
	if (ftype == 'c')
		res = ft_print_char(va_arg(args, int));
	else if (ftype == 's')
		res = ft_print_str(va_arg(args, char *));
	else if (ftype == 'd' || ftype == 'i')
		res = ft_print_dec(va_arg(args, int));
	else if (ftype == 'x' || ftype == 'X')
		res = ft_print_hex(va_arg(args, unsigned int), ftype);
	else if (ftype == 'u')
		res = ft_print_unsign(va_arg(args, unsigned int));
	else if (ftype == '%')
		res = ft_print_char('%');
	else if (ftype == 'p')
		res = ft_print_ptr(va_arg(args, uintptr_t));
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_conversions(args, str[i + 1]);
			i++;
		}
		else
			size += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
