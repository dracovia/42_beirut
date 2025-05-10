/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:52:00 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/20 07:45:05 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_safe(int row, int col, int array[10])
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (array[i] == row
			|| array[i] - i == row - col
			|| array[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int col, int *count)
{
	int		i;
	char	c;

	i = 0;
	if (col == 10)
	{
		while (i < 10)
		{
			c = board[i] + '0';
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		(*count)++;
		return ;
	}
	while (i < 10)
	{
		if (is_safe(i, col, board))
		{
			board[col] = i;
			solve(board, col + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	array[10];

	solve (array, 0, &count);
	return (count);
}
