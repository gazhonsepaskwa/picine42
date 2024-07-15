/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:46:27 by edcherry          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:36 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	check_dbl_col(int grid[4][4], int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_dbl_row(int grid[4][4], int row, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	check_dbl_pos(int grid[4][4], int col, int row, int num)
{
	if (check_dbl_col(grid, col, num) || check_dbl_row(grid, row, num))
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	int grid[4][4] = {
		{1, 2, 3, 4},
		{4, 3, 2, 1},
		{2, 4, 1, 3},
		{3, 1, 4, 2}
	};

	int col = 0;
	int row = 0;
	int num = 6;

	if (check_dbl_pos(grid, col, row, num))
		printf("number %d exists in row %d or col %d\n", num, row, col);
	else
		printf("number %d does not exists in row %d or col %d\n", num, row,
			col);
}*/
