/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:30:34 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/24 19:52:31 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	basen(char *s)
{
	int	i;
	int	j;

	i = 0 ;
	if (s == NULL || s[0] == '\0' || s[1] == '\0')
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[j] != '\0')
		{
			if (s[i] == s[j] && i != j)
				return (0);
			j++;
		}
		if (s[i] == '-' || s[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	strlenn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	long	n;

	b = strlenn(base);
	n = nbr;
	if (basen(base) == 0)
	{
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write (1, "-", 1);
	}
	if (n >= b)
	{
		ft_putnbr_base(n / b, base);
	}
	write (1, &base[n % b], 1);
}
