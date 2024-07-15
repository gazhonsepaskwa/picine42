/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:17:22 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:27 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_num(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	ft_print_int(int i)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
}

void	ft_print_char(char c)
{
	write(1, &c, 1);
}
