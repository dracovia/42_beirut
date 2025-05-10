/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:30:40 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/12 10:48:28 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printing(int i)
{
	char	c;

	c = i / 10 + '0';
	write (1, &c, 1);
	c = i % 10 + '0';
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	j;
	int	i;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			printing(i);
			write (1, " ", 1);
			printing(j);
			if (!(i == 98 && j == 99))
			{
				write (1, ",", 1);
				write (1, " ", 1);
			}
			j++;
		}
		i++;
	}
}
