/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:04:45 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/30 18:09:32 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putnum(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 1);
		return ;
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * (-1);
	}
	if (n >= 10)
		ft_putnum(n / 10);
	c = n + '0';
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putnum(par[i].size);
		write (1, "\n", 1);
		ft_putstr(par[i].str);
		write (1, "\n", 1);
		ft_putstr(par[i].copy);
		write (1, "\n", 1);
		i++;
	}
}
