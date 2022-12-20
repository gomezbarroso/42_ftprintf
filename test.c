/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:02:20 by agomez-b          #+#    #+#             */
/*   Updated: 2022/12/20 15:20:43 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(1, &c, 1);
}

void	ft_puthexnbr_fd(size_t n, char c, int fd)
{
	char	*hexa_str;
	char	*hexa_str_caps;

	hexa_str = "0123456789abcdef";
	hexa_str_caps = "0123456789ABCDEF";
	if (n >= 16)
		ft_puthexnbr_fd(n / 16, c, fd);
	if (c == 'p' || c == 'x')
		ft_putchar_fd(hexa_str[n % 16], fd);
	if (c == 'X')
		ft_putchar_fd(hexa_str_caps[n % 16], fd);
}

int	main(void)
{
	ft_puthexnbr_fd(25828, 'X', 1);
	return (0);
}
