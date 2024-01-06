/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstarov <dstarov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:13:25 by dmytro            #+#    #+#             */
/*   Updated: 2023/07/02 15:16:03 by dstarov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_dec(int n);
int	ft_print_hex(unsigned int n, char fcase);
int	ft_print_unsign(unsigned int ui);
int	ft_print_ptr(uintptr_t ptr);

#endif
