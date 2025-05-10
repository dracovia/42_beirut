/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:55:08 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/20 16:11:15 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rows(int row, int **grid, int input[]);
int	check_cols(int col, int **grid, int input[]);
int	is_unique(int row, int col, int val, int **grid);

void	next_cell(int row, int col, int *next_row, int *next_col)
{
	*next_col = (col + 1) % 4;
	*next_row = row;
	if (col == 3)
		*next_row = row + 1;
}

int	is_partial_valid(int row, int col, int **grid, int *input)
{
	if (col == 3 && !check_rows(row, grid, input))
		return (0);
	if (row == 3 && !check_cols(col, grid, input))
		return (0);
	return (1);
}

int	solve(int row, int col, int **grid, int input[])
{
	int	val;
	int	next_col;
	int	next_row;

	if (row == 4)
		return (1);
	next_cell(row, col, &next_row, &next_col);
	val = 1;
	while (val <= 4)
	{
		if (is_unique(row, col, val, grid))
		{
			grid[row][col] = val;
			if (solve(next_row, next_col, grid, input)
				&& is_partial_valid(row, col, grid, input))
				return (1);
			grid[row][col] = 0;
		}
		val++;
	}
	return (0);
}
