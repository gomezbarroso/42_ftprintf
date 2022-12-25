/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <gomezbarroso.a@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:02:18 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/25 21:57:18 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static int	aux_def_type(va_list ap, char conv_type)
{
	int	nbr;

	nbr = 0;
	if (conv_type == '%')
		nbr += ft_putchar_fd('%', 1);
	else if (conv_type == 'c')
		nbr += ft_putchar_fd(va_arg(ap, int), 1);
	else if (conv_type == 's')
		nbr += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (conv_type == 'p')
	{
		nbr += ft_putstr_fd("0x", 1);
		nbr += ft_puthexnbr_fd(va_arg(ap, unsigned int), conv_type, 1);
	}
	else if (conv_type == 'd')
		nbr += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (conv_type == 'i')
		nbr += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (conv_type == 'u')
		nbr += ft_putunbr_fd(va_arg(ap, unsigned int), 1);
	else if (conv_type == 'x')
		nbr += ft_puthexnbr_fd(va_arg(ap, unsigned int), conv_type, 1);
	else if (conv_type == 'X')
		nbr += ft_puthexnbr_fd(va_arg(ap, unsigned int), conv_type, 1);
	return (nbr);
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	i;
	int		nbr;

	i = 0;
	nbr = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i ++;
			nbr = nbr + aux_def_type(ap, str[i]);
		}
		else
			nbr = nbr + ft_putchar_fd(str[i], 1);
		i ++;
	}
	va_end(ap);
	return (nbr);
}
