/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:56:39 by mfassad           #+#    #+#             */
/*   Updated: 2025/05/01 13:43:04 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	isinstring(char c, char *st)
{
	int	i;

	i = 0;
	if (!st)
		return (0);
	while (st[i])
	{
		if (c == st[i])
			return (1);
		i++;
	}
	return (0);
}

int	countwords(char *st, char *charset)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	if (!st || !st[0])
		return (0);
	while (st[i])
	{
		if (!isinstring(st[i], charset)
			&& (isinstring(st[i + 1], charset) || st[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

char	*cutstring(char *string, int pre, int cur)
{
	int		i;
	char	*new;

	if (cur <= pre)
		return (NULL);
	new = malloc(cur - pre + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (pre < cur)
		new[i++] = string[pre++];
	new[i] = '\0';
	return (new);
}

char	**savewords(char *st, char *charset, char **r, int word_count)
{
	int	counter;
	int	pre;
	int	cur;

	pre = 0;
	cur = 0;
	counter = 0;
	if (!st || !charset)
		return (NULL);
	while (st[cur] && counter < word_count)
	{
		while (st[cur] && isinstring(st[cur], charset))
			cur++;
		pre = cur;
		while (st[cur] && !isinstring(st[cur], charset))
			cur++;
		if (cur > pre)
		{
			r[counter] = cutstring(st, pre, cur);
			if (!r[counter])
				return (NULL);
			counter++;
		}
	}
	return (r);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	int		word_count;

	if (!str || !charset)
		return (NULL);
	word_count = countwords(str, charset);
	r = malloc(sizeof(char *) * (word_count + 1));
	if (!r)
		return (NULL);
	r[word_count] = NULL;
	savewords(str, charset, r, word_count);
	return (r);
}
