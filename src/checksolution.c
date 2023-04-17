/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:39:57 by dimolin2          #+#    #+#             */
/*   Updated: 2023/04/01 18:39:58 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_flood_fill(char **temp, t_win size, t_vector pos)
{
	if (pos.x < 0 || pos.x > size.x || pos.y < 0 || pos.y >= size.y
		|| temp[pos.y][pos.x] == '1')
		return ;
	if (temp[pos.y][pos.x] == 'E')
	{
		temp[pos.y][pos.x] = '1';
		return ;
	}
	temp[pos.y][pos.x] = '1';
	ft_flood_fill(temp, size, (t_vector){pos.x + 1, pos.y});
	ft_flood_fill(temp, size, (t_vector){pos.x - 1, pos.y});
	ft_flood_fill(temp, size, (t_vector){pos.x, pos.y + 1});
	ft_flood_fill(temp, size, (t_vector){pos.x, pos.y - 1});
}

int	find_solution(char **tab, t_win size, t_vector begin)
{
	int	y;
	int	x;

	y = 0;
	ft_flood_fill(tab, size, begin);
	while (tab[y] != 0)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] != '0' && tab[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
