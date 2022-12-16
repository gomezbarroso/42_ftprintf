/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:01:16 by agomez-b          #+#    #+#             */
/*   Updated: 2022/11/07 23:27:57 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_char_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*result_str;
	size_t			i;
	size_t			len;
	size_t			j;

	i = 0;
	len = ft_strlen(s1);
	j = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_char_check(s1[i], set))
		i ++;
	while (len > i && ft_char_check(s1[len - 1], set))
		len --;
	result_str = malloc(sizeof(char) * (len - i + 1));
	if (result_str == NULL)
		return (NULL);
	while (len > i)
		result_str[j++] = s1[i++];
	result_str[j] = 0;
	return (result_str);
}
