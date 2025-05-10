/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:20:44 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/24 20:01:40 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	total_len(char **strs, int size, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

char	*strcopy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest + i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*ptr;
	char	*res;
	int		len;

	if (size == 0)
	{
		res = (char *) malloc (1);
		res[0] = '\0';
		return (res);
	}
	len = total_len(strs, size, sep);
	res = (char *) malloc (sizeof(char) * (len + 1));
	i = 0;
	ptr = res;
	while (i < size)
	{
		ptr = strcopy(ptr, strs[i]);
		if (i < size -1)
			ptr = strcopy(ptr, sep);
		i++;
	}
	*ptr = '\0';
	return (res);
}
