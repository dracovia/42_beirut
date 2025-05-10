/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:04:37 by mfassad           #+#    #+#             */
/*   Updated: 2025/04/20 16:15:23 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include<stdlib.h>

void	print_grid(int **grid);
int		is_valid_input(char *str);
int		*parse_input(char *str);
int		solve(int row, int col, int **grid, int input[]);

int	**initialize(void)
{
	int	**grid;
	int	i;
	int	j;

	grid = (int **)malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);
	i = 0;
	j = 0;
	while (i < 4)
	{
		grid[i] = (int *)malloc(sizeof(int) * 4);
		if (!grid[i])
			return (NULL);
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

int	main(int argc, char *argv[])
{
	int	*input;
	int	**grid ;

	grid = initialize();
	if (argc != 2 || !is_valid_input(argv[1]))
	{
		write(1, "error\n", 6);
		return (1);
	}
	input = parse_input(argv[1]);
	if (solve(0, 0, grid, input))
	{
		print_grid(grid);
	}
	else
	{
		write(1, "error\n", 6);
	}
	free(input);
	return (0);
}
