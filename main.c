/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:46:07 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:31 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	check_ac(int ac);
int	check_format(char *str);
int	check_opposite(char *str);
int	**ft_spliter(const char *str);
int	ft_solve(int grid[4][4], int row, int col, int **views);

void	code(char *av[])
{
	int	**views;
	int	grid[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	views = ft_spliter(av[1]);
	ft_solve(grid, 0, 0, views);
}

int	main(int ac, char *av[])
{
	if (check_ac(ac) && check_format(*av)
		&& check_opposite(*av))
	{
		code(av);
	}
	else
	{
		write(1, "Error", 5);
	}
	return (0);
}
