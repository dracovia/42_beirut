/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:15:38 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/01 10:22:55 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset))
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && !in_charset(str[i], charset))
				i++;
		}
	}
	return (word);
}

char	*ft_duprange(char *start, char *end)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	len = end - start;
	str = (char *) malloc (len +1);
	while (i < len)
	{
		str[i] = start[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	char	**strs;
	char	*start;
	int		k;

	i = 0;
	words = word(str, charset);
	strs = (char **) malloc (sizeof (char *) * (words + 1));
	k = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset))
			i++;
		if (str[i])
		{
			start = &str[i];
			while (str[i] && !in_charset(str[i], charset))
				i++;
			strs[k++] = ft_duprange(start, &str[i]);
		}
	}
	strs[k] = NULL;
	return (strs);
}
