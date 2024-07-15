/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcherry <<edcherry@student.s19.be>>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:18:52 by cvan-wal          #+#    #+#             */
/*   Updated: 2024/07/14 23:05:35 by edcherry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_character(char c)
{
	return (c >= '1' && c <= '4');
}

int	count_fours(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i <= 31 && str[i] != '\0')
	{
		if (str[i] == '4')
		{
			count++;
		}
		i += 2;
	}
	return (count);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

int	check_format(char *str)
{
	int	i;

	if (ft_strlen(str) != 31)
	{
		return (0);
	}
	i = 0;
	while (i < 15)
	{
		if (str[2 * i + 1] != ' ')
		{
			return (0);
		}
		if (!is_valid_character(str[2 * i]))
		{
			return (0);
		}
		i++;
	}
	if (count_fours(str) > 4)
	{
		return (0);
	}
	return (1);
}
