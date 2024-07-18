/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:42:36 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/18 22:05:43 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int	leng(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i]);
	return (i);
}

void	ft_putnbr(int nb)
{
	char	out;

	if (nb < 0)
		return ;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		out = nb + 48;
		write(1, &out, 1);
	}
}

void ft_putstr(char *str)
{
	write(1, str, leng(str));
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (!par)
		return ;
	while (par[i].str)
	{
		putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		putstr(par[i].str);
        i++;
	}
}