/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <gomezbarroso.a@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:00:55 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/25 22:18:50 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		nbr = nbr + write(fd, &s[i], 1);
		i ++;
	}
	return (nbr);
}
