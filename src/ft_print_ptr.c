/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:30:32 by dmytro            #+#    #+#             */
/*   Updated: 2023/07/02 15:24:20 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ptr_depth(uintptr_t n)
{
	size_t	size;

	size = 0;
	while (n)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

char	*ptr_to_str(uintptr_t ptr)
{
	size_t			size;
	char			*hex;
	unsigned int	n_temp;

	size = ptr_depth(ptr);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (ptr != 0)
	{
		n_temp = ptr % 16;
		if (n_temp < 10)
			hex[size - 1] = n_temp + '0';
		else
			hex[size - 1] = n_temp + 'W';
		ptr = ptr / 16;
		size--;
	}
	return (hex);
}

int	ft_print_ptr(uintptr_t ptr)
{
	char	*str;
	int		size;

	size = 0;
	if (!ptr)
	{
		str = "(nil)";
		ft_print_str(str);
		return (ft_strlen(str));
	}
	size += write(1, "0x", 2);
	str = ptr_to_str(ptr);
	size += ft_print_str(str);
	free(str);
	return (size);
}
