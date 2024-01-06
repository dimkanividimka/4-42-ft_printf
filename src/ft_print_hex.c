/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:20:15 by dmytro            #+#    #+#             */
/*   Updated: 2023/07/02 15:28:05 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	num_depth(unsigned int n)
{
	size_t	depth;

	depth = 0;
	while (n)
	{
		depth++;
		n = n / 16;
	}
	return (depth);
}

char	*int_to_hexstr(unsigned int n, char fcase)
{
	size_t			size;
	char			*hex;
	unsigned int	n_temp;

	size = num_depth(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	n_temp = n;
	while (n != 0)
	{
		n_temp = n % 16;
		if (n_temp < 10)
			hex[size - 1] = n_temp + '0';
		else
			hex[size - 1] = n_temp + fcase;
		n = n / 16;
		size--;
	}
	return (hex);
}

int	ft_print_hex(unsigned int n, char fcase)
{
	char	*str;
	int		size;

	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	if (fcase == 'X')
		fcase = 55;
	else
		fcase = 87;
	str = int_to_hexstr(n, fcase);
	size = ft_print_str(str);
	free(str);
	return (size);
}
