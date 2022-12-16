/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-b <agomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:31:54 by agomez-b          #+#    #+#             */
/*   Updated: 2022/11/10 23:51:07 by agomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i ++;
		else
		{
			word_count ++;
			while (s[i] != '\0' && s[i] != c)
				i ++;
		}
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;

	str = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i ++;
		else
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i ++;
			str[j] = ft_substr(s, start, i - start);
			j ++;
		}
	}
	str[j] = NULL;
	return (str);
}
