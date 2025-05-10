/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 08:31:46 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/20 16:17:00 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(grid[i][j] + '0');
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	is_valid_input(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i % 2 == 0) && (str[i] >= '1' && str[i] <= '4'))
		{
			if (!(str[i] >= '1' && str[i] <= '4'))
				return (0);
		}
		if (i % 2 == 1 && str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (i == 31);
}

int	*parse_input(char *str)
{
	int	*input;
	int	i;
	int	j;

	i = 0;
	j = 0;
	input = (int *)malloc (16 * sizeof (int));
	while (str[i] && j < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			input[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (input);
}
