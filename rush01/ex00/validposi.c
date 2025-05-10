/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validposi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:04:32 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/20 17:09:54 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	visible_count(int line[])
{
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_rows(int row, int **grid, int input[])
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (visible_count(line) != input[8 + row])
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][3 - i];
		i++;
	}
	if (visible_count(line) != input[12 + row])
		return (0);
	return (1);
}

int	check_cols(int col, int **grid, int input[])
{
	int	i;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (visible_count(line) != input[col])
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[3 - i][col];
		i++;
	}
	if (visible_count(line) != input[col + 4])
		return (0);
	return (1);
}

int	is_unique(int row, int col, int val, int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == val || grid[i][col] == val)
			return (0);
		i++;
	}
	return (1);
}
