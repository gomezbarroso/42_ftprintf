/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:02:18 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/16 15:11:38 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int aux_def_type(va_list ap, char conv_type)
{
	int to_print;

	to_print = 0;
	if (conv_type == '%')
		to_print = to_print + ft_putchar_fd('%', 1);
	else if (conv_type == 'c')
		to_print = to_print + ft_putchar_fd(va_arg(ap, ), 1);
	else if (conv_type == 's')
		to_print = to_print + ft_putstr_fd(va_arg(ap, ), 1);
	else if (conv_type == 'p')
	{
		to_print = to_print + ft_putstr_fd("0x", 1);
		to_print = to_print + ft_puthexnbr_fd(va_arg(ap, ), 1);
	}
	else if (conv_type == 'd')
		to_print = to_print + ft_putnbr_fd(va_arg(ap, ), 1);
	else if (conv_type == 'i')
		to_print = to_print + ft_putnbr_fd(va_arg(ap, ), 1)
	else if (conv_type == 'u')
		to_print = to_print + ft_putunbr_fd(va_arg(ap, ), 1);
	else if (conv_type == 'x')
		to_print = to_print + ft_puthexnbr_fd(va_arg(ap, ), 1);
	else if (conv_type == 'X')
		to_print = to_print + ft_puthexnbr_fd(va_arg(ap, ), 1);
	return(to_print);
}

int	ft_printf(char const *str, ...)
{

}