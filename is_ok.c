/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:39:26 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:42 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_dbl_pos(int grid[4][4], int col, int row, int num);
int	visible_buildings(int **views, int pov, int pos, int size);

int	check_views(int **views, int col, int row)
{
	int	out;

	out = 1;
	if (!(visible_buildings(views, 0, col, 4) <= views[0][col]))
		out = 0;
	else if (!(visible_buildings(views, 1, col, 4) <= views[1][col]))
		out = 0;
	else if (!(visible_buildings(views, 2, row, 4) <= views[2][row]))
		out = 0;
	else if (!(visible_buildings(views, 3, row, 4) <= views[3][row]))
		out = 0;
	return (out);
}

int	is_ok(int grid[4][4], int row, int col, int **views)
{
	if (!(check_dbl_pos(grid, col, row, grid[col][row]))
				&& check_views(views, col, row))
		return (1);
	else
		return (0);
}
