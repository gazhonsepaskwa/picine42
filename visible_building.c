/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible_building.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:46:39 by edcherry          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:26 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	visible_top(int **views, int pos, int size)
{
	int	i;
	int	max_high;
	int	nb_vis;

	i = 0;
	nb_vis = 0;
	max_high = 0;
	while (i < size)
	{
		if (views[i][pos] > max_high)
		{
			max_high = views[i][pos];
			nb_vis++;
		}
		i++;
	}
	return (nb_vis);
}

int	visible_bottom(int **views, int pos, int size)
{
	int	i;
	int	max_high;
	int	nb_vis;

	i = 0;
	nb_vis = 0;
	max_high = 0;
	while (i < size)
	{
		if (views[size - i - 1][pos] > max_high)
		{
			max_high = views[size - i - 1][pos];
			nb_vis++;
		}
		i++;
	}
	return (nb_vis);
}

int	visible_left(int **views, int pos, int size)
{
	int	i;
	int	max_high;
	int	nb_vis;

	i = 0;
	nb_vis = 0;
	max_high = 0;
	while (i < size)
	{
		if (views[pos][i] > max_high)
		{
			max_high = views[pos][i];
			nb_vis++;
		}
		i++;
	}
	return (nb_vis);
}

int	visible_right(int **views, int pos, int size)
{
	int	i;
	int	max_high;
	int	nb_vis;

	i = 0;
	nb_vis = 0;
	max_high = 0;
	while (i < size)
	{
		if (views[pos][size - i - 1] > max_high)
		{
			max_high = views[pos][size - i - 1];
			nb_vis++;
		}
		i++;
	}
	return (nb_vis);
}

int	visible_buildings(int **views, int pov, int pos, int size)
{
	if (pov == 0)
		return (visible_top(views, pos, size));
	else if (pov == 1)
		return (visible_bottom(views, pos, size));
	else if (pov == 2)
		return (visible_left(views, pos, size));
	else if (pov == 3)
		return (visible_right(views, pos, size));
	else
		return (0);
}
/*
int	main(void)
{
	int size = 4;
	int i, j;

	int **views = (int **)malloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
	{
		views[i] = (int *)malloc(sizeof(int) * size);
		i++;
	}

	int test[4][4] = {
		{1, 2, 3, 4},
		{2, 3, 4, 1},
		{3, 4, 1, 2},
		{4, 1, 2, 3}
	};

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			views[i][j] = test[i][j];
			i++;
		}
		j++;
	}

	printf("\n");
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			printf("%d ", views[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


	printf("\n%d\n", visible_buildings(views, 0, 1, size));
	printf("%d\n", visible_buildings(views, 1, 2, size));
	printf("%d\n", visible_buildings(views, 2, 3, size));
	printf("%d\n", visible_buildings(views, 3, 0, size));
}*/
