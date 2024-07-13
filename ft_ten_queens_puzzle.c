/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:45:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/07/12 09:21:14 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RANGE 10

#include <unistd.h>

int g_solution_count = 0;
int positions[RANGE];

void print_nbr(int n)
{
    if (n < 0)
        write(1, '-', 1)
        un = (unsigned int)(-n);
    else
        un = (unsigned int)(n);
    write (1,&(n + '0'));
}

void print_solution(void)
{
    int i;
    
    i = 0;
    while (i < RANGE)
    {
        print_nbr(positions[i]);
        i++;
    }
    write (1,'$',1);
    write (1, '\n', 1);
}

int is_safe(int col, int row)
{
    int i;
    int pos;
    
    i = 0;
    while (i < col)
    {
        pos = positions[i];
        if (pos == row || col - row == i - pos || col + row == i + pos) {
            return (0);
        }
        i++;
    }
    return (1);
}

void solve(int col)
{
    int row;

    row = 0;
    if (col == RANGE)
    {
        print_solution();
        g_solution_count++;
        return ;
    }

    while (row < RANGE)
    {
        if (is_safe(col, row))
        {
            positions[col] = row;
            solve(col + 1);
        }
        row++;
    }
}

int ft_ten_queens_puzzle(void)
{
    solve(0);
    return g_solution_count;
}

/*#include <stdio.h>

int main(void)
{
    int total_solutions = ft_ten_queens_puzzle();
    printf("Total solutions: %d\n", total_solutions);
    return 0;
}*/