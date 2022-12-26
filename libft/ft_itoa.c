/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:00:31 by agomez-b          #+#    #+#             */
/*   Updated: 2022/11/10 02:47:55 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_digit_counter(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		count ++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count ++;
	}
	return (count);
}

static char	*ft_min_int_to_str(void)
{
	char	*str;

	str = malloc(12);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, "-2147483648", 12);
	return (str);
}

static char	*ft_zero_to_str(void)
{
	char	*str;

	str = malloc(2);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, "0", 2);
	return (str);
}

static void	ft_check_sign(int *sign, unsigned int *digits, int *n)
{
	*sign = 0;
	if (*n < 0)
	{
		*sign = 1;
		*n = *n * (-1);
	}
	*digits = ft_digit_counter(*n) + *sign;
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	digits;
	int				sign;

	if (n == -2147483648)
		return (ft_min_int_to_str());
	if (n == 0)
		return (ft_zero_to_str());
	ft_check_sign(&sign, &digits, &n);
	str = malloc(sizeof(char) * digits + 1);
	if (str == NULL)
		return (str);
	str[digits--] = 0;
	while (n > 0)
	{
		str[digits--] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == 1)
		*(str) = '-';
	return (str);
}
