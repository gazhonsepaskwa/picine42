/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:35:40 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:29 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(char c);
int		ft_is_num(char c);

int	**ft_add_to_array(const char *str, int **array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_is_num(str[i]))
		{
			array[j][k] = ft_atoi(str[i]);
			k++;
			if (k == 4)
			{
				k = 0;
				j++;
			}
		}
		i++;
	}
	return (array);
}

int	**ft_spliter(const char *str)
{
	int	i;
	int	**array;

	array = malloc(sizeof * array * 4);
	i = 0;
	while (i < 4)
	{
		array[i] = malloc(sizeof * array[i] * 4);
		i++;
	}
	ft_add_to_array(str, array);
	return (array);
}

void	free_array(int **array)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
   test

#include <stdio.h>

int	main(void) {
const char* str = "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4";
int** result = ft_spliter(str);

printf("tab{{");
for (int i = 0; i < 4; i++) {
printf("{");
for (int j = 0; j < 4; j++) {
printf("[%d]", result[i][j]);
}
printf("}");
if (i < 3) {
printf(" ");
}
}
printf("}}\n");
free_array(result);

return (0);
}
*/
