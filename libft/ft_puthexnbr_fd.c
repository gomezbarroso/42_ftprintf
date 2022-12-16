/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:45:04 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/16 13:43:30 by agomez-b         ###   ########.fr       */
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
		ft_putchar_fd(hexa_str[n % 16], fd);
	if (c == 'X')
		ft_putchar_fd(hexa_str_caps[n % 16], fd);
	return (nbr);
}
