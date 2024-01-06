/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:28:52 by dstarov           #+#    #+#             */
/*   Updated: 2023/07/02 15:20:34 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ui_depth(unsigned int ui)
{
	size_t	size;

	if (ui == 0)
		return (1);
	size = 0;
	while (ui != 0)
	{
		ui = ui / 10;
		size++;
	}
	return (size);
}

char	*ui_to_str(unsigned int ui)
{
	size_t			size;
	char			*unsign;
	unsigned int	temp_ui;

	size = ui_depth(ui);
	unsign = malloc(sizeof(char) * (size + 1));
	if (!unsign)
		return (NULL);
	temp_ui = ui;
	unsign[size] = '\0';
	while (temp_ui / 10 != 0)
	{
		unsign[--size] = temp_ui % 10 + '0';
		temp_ui = temp_ui / 10;
	}
	unsign[--size] = temp_ui % 10 + '0';
	return (unsign);
}

int	ft_print_unsign(unsigned int ui)
{
	char	*unsign;
	int		size;

	unsign = ui_to_str(ui);
	size = ft_print_str(unsign);
	free(unsign);
	return (size);
}
