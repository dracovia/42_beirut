/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:23:19 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/15 22:09:16 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	dlen = i;
	slen = ft_strlen(src);
	j = 0;
	if (size > 0 && dlen < size)
	{
		while (src[j] != '\0' && (dlen + j) < size - 1)
		{
			dest[dlen + j] = src[j];
			j++;
		}
		dest[i + dlen] = '\0';
	}
	return ((unsigned int)(dlen + slen));
}
