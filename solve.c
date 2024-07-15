/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:40:02 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:30 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_ok(int grid[4][4], int row, int col, int **views);
int		ft_print_int(int i);
int		ft_print_char(char c);

void	ft_print_sol(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_print_int(grid[i][j]);
			j++;
		}
		ft_print_char('\n');
		i++;
	}
}

int	ft_solve(int grid[4][4], int row, int col, int **views)
{
	int	num;

	num = 1;
	if (row == 4)
	{
		row = 0;
		col++;
		if (col == 4)
		{
			ft_print_sol(grid);
			return (1);
		}
	}
	while (num <= 4)
	{
		if (is_ok(grid, row, col, views))
		{
			grid[row][col] = num;
			if (ft_solve(grid, row + 1, col, views))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

/*
col = actual_column
row = actual_row
*/