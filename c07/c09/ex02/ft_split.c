/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:56:39 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/01 13:17:10 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	return (0);/* code */
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !in_charset(str[i], charset))
				i++;
		}
	}
	return (count);
}

char	*ft_strdup(char *start, char *end)
{
	char	*res;
	int		i;
	int		size;

	size = end - start;
	res = (char *) malloc (size +1);
	i = 0;
	while (i < size)
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		words;
	char	**strs;
	char	*start;
	int		k;

	words = count_word(str, charset);
	strs = (char **)malloc(sizeof (char *) * (words + 1));
	i = 0;
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
			strs[k++] = ft_strdup(start, &str[i]);
		}
	}
	strs[k++] = 0;
	return (strs);
}

int main(int argc, char** argv)
{
	char ** r = ft_split(argv[1] , " ");
	int i = 0; 
	if(argc > 1)
	{
		while (i < 5)
		{
			printf("%s\n",r[i]);
			i++;
		}
		
	}
	
	return (0);
}