/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <gomezbarroso.a@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:45:04 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/25 22:20:01 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexnbr_fd(size_t n, char c, int fd)
{
	int		nbr;
	char	*hexa_str;
	char	*hexa_str_caps;

	nbr = 0;
	hexa_str = "0123456789abcdef";
	hexa_str_caps = "0123456789ABCDEF";
	if (n >= 16)
		nbr = nbr + ft_puthexnbr_fd(n / 16, c, fd);
	if (c == 'p' || c == 'x')
		nbr = nbr + ft_putchar_fd(hexa_str[n % 16], fd);
	if (c == 'X')
		nbr = nbr + ft_putchar_fd(hexa_str_caps[n % 16], fd);
	return (nbr);
}
