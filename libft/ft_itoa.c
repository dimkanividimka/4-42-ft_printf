/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:07:27 by dmytro            #+#    #+#             */
/*   Updated: 2023/07/01 14:01:24 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* VERSION 2.0
 * This function transforms given number as integer into a string
 *
 * Parameters:
 * - n: the integer to be transformed.
 * 
 * Return:
 * - new string with a given number followed by string-terminating
 * character.
 * - NULL if memory allocation failed.
 */
size_t	n_dept(int n)
{
	size_t	dept;

	dept = 0;
	if (n <= 0)
		dept++;
	while (n != 0)
	{
		n = n / 10;
		dept++;
	}
	return (dept);
}

char	*ft_itoa(int n)
{
	size_t			n_len;
	unsigned int	n_tmp;
	char			*n_str;

	n_len = n_dept(n);
	n_str = malloc(sizeof(char) * (n_len + 1));
	if (!n_str)
		return (NULL);
	n_str[n_len] = '\0';
	if (n < 0)
	{
		n_str[0] = '-';
		n_tmp = -n;
	}
	else
		n_tmp = n;
	while (n_tmp / 10 != 0)
	{
		n_str[--n_len] = n_tmp % 10 + '0';
		n_tmp = n_tmp / 10;
	}
	n_str[--n_len] = n_tmp % 10 + '0';
	return (n_str);
}
