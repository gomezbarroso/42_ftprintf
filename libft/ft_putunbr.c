/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <gomezbarroso.a@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:26:21 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/25 22:13:39 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	nbr;

	nbr = 0;
	if (n >= 10)
	{
		nbr = nbr + ft_putunbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		nbr = nbr + ft_putchar_fd((n + 48), fd);
	return (0);
}
