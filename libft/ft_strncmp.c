/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:44:12 by agomez-b          #+#    #+#             */
/*   Updated: 2022/11/05 19:32:03 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (*(s1 + i) && *(s2 + i) && *(s1 + i) == *(s2 + i) && (i < (n - 1)))
	{
		i ++;
	}
	return ((unsigned char)(*(s1 + i)) - (unsigned char)(*(s2 + i)));
}
