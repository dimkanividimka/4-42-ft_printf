/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:33:59 by dmytro            #+#    #+#             */
/*   Updated: 2023/07/02 15:17:06 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int n)
{
	char	*dec;
	int		size;

	dec = ft_itoa(n);
	size = ft_print_str(dec);
	free(dec);
	return (size);
}
