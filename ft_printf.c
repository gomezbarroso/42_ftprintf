/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:02:18 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/22 15:35:44 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static void	aux_def_type(va_list ap, char conv_type)
{
	if (conv_type == '%')
		ft_putchar_fd('%', 1);
	else if (conv_type == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (conv_type == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (conv_type == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_puthexnbr_fd(va_arg(ap, unsigned int), conv_type, 1);
	}
	else if (conv_type == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (conv_type == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (conv_type == 'u')
		ft_putunbr_fd(va_arg(ap, unsigned int), 1);
	else if (conv_type == 'x')
		ft_puthexnbr_fd(va_arg(ap, unsigned int), conv_type, 1);
	else if (conv_type == 'X')
		ft_puthexnbr_fd(va_arg(ap, unsigned int), conv_type, 1);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i ++;
			aux_def_type(ap, str[i]);
		}
		else
			ft_putchar_fd(str[i], 1);
		i ++;
	}
	va_end(ap);
}
