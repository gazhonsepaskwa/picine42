/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:41:12 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/18 22:04:50 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strcpy(char *str)
{
	char	*cpy;
	char	*start;

	if (!str)
		return (NULL);
	cpy = (char *)malloc(leng(str) + 1);
	if (!cpy)
		return (NULL);
	start = cpy;
	while (*str)
		*cpy++ = *str++;
	*cpy = '\0';
	return (start);
}

int	leng(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i]);
	return (i);
}

struct s_stock_str	*ft_strs_to_struct_grp(int ac, char **av)
{
	int					i;
	struct s_stock_str	*struct_grp;

	struct_grp = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!av || !struct_grp || ac < 0)
		return (NULL);
	i = 0;
	while (i < ac && av[i])
	{
		struct_grp[i].str = ft_strcpy(av[i]);
		struct_grp[i].cpy = ft_strcpy(av[i]);
        struct_grp[i].size = leng(av[i++]);
	}
	struct_grp[i].str = '\0';
	return (struct_grp);
}
