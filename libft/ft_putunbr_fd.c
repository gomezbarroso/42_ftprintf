/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:26:21 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/26 21:25:14 by agomez-b         ###   ########.fr       */
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
	return (nbr);
}
