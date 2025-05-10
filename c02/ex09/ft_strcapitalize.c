/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:21:44 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/14 18:53:03 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isalphanum(char c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 1;
	while (str[i] != '\0')
	{
		if (isalphanum(str[i]))
		{
			if (word && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - ('a' - 'A');
			else if (!word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + ('a' - 'A');
			word = 0;
		}
		else
		{
			word = 1 ;
		}
		i++;
	}
	return (str);
}
