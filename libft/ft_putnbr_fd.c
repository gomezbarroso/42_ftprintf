/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:26:55 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/22 21:54:52 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd((n + 48), fd);
	}
	return (0);
}
