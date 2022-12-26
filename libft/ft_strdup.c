/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:12:01 by agomez-b          #+#    #+#             */
/*   Updated: 2022/11/06 13:47:49 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dst == NULL)
		return (dst);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i ++;
	}
	dst[i] = s1[i];
	return (dst);
}
