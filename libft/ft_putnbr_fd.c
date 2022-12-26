/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:55 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/26 21:23:54 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	nbr;

	nbr = 0;
	if (n == -2147483648)
	{
		nbr = nbr + ft_putchar_fd('-', fd);
		nbr = nbr + ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		nbr = nbr + ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 10)
	{
		nbr = nbr + ft_putnbr_fd((n / 10), fd);
		n = n % 10;
	}
	if (n < 10)
	{
		nbr = nbr + ft_putchar_fd((n + 48), fd);
	}
	return (nbr);
}
