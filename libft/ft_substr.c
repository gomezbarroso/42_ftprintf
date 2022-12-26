/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:15:39 by agomez-b          #+#    #+#             */
/*   Updated: 2022/11/10 23:51:43 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_string(void)
{
	char	*s;

	s = malloc(1);
	if (s == NULL)
		return (NULL);
	*s = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_sub;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_empty_string());
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s_sub = malloc(sizeof(char) * (len + 1));
	if (s_sub == NULL)
		return (NULL);
	while (len > 0)
	{
		s_sub[i] = s[start];
		i ++;
		start ++;
		len --;
	}
	s_sub[i] = '\0';
	return (s_sub);
}
