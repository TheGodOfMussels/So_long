/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:03:26 by dimolin2          #+#    #+#             */
/*   Updated: 2023/04/05 20:03:27 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	reaper_right(t_game *g)
{
	int	step;

	step = g->pos.gx;
	if (g->map[g->pos.gy][--step] == '1' || g->map[g->pos.gy][step] == 'E' || \
			g->map[g->pos.gy][step] == 'P')
		return (0);
	if (g->map[g->pos.gy][step] == 'C')
		g->count.pickedup++;
	g->map[g->pos.gy][step] = 'G';
	g->map[g->pos.gy][g->pos.gx] = '0';
	g->pos.gx--;
	g->count.r_dir = 0;
	return (0);
}

int	reaper_left(t_game *g)
{
	int	step;

	step = g->pos.gx;
	if (g->map[g->pos.gy][++step] == '1' || g->map[g->pos.gy][step] == 'E' || \
			g->map[g->pos.gy][step] == 'P')
		return (0);
	if (g->map[g->pos.gy][step] == 'C')
		g->count.pickedup++;
	g->map[g->pos.gy][step] = 'G';
	g->map[g->pos.gy][g->pos.gx] = '0';
	g->pos.gx++;
	g->count.r_dir = 1;
	return (0);
}

int	reaper_down(t_game *g)
{
	int	step;

	step = g->pos.gy;
	if (g->map[++step][g->pos.gx] == '1' || g->map[step][g->pos.gx] == 'E' || \
			g->map[step][g->pos.gx] == 'P')
		return (0);
	if (g->map[step][g->pos.gx] == 'C')
		g->count.pickedup++;
	g->map[step][g->pos.gx] = 'G';
	g->map[g->pos.gy][g->pos.gx] = '0';
	g->pos.gy++;
	return (0);
}

int	reaper_up(t_game *g)
{
	int	step;

	step = g->pos.gy;
	if (g->map[--step][g->pos.gx] == '1' || g->map[step][g->pos.gx] == 'E' || \
			g->map[step][g->pos.gx] == 'P')
		return (0);
	if (g->map[step][g->pos.gx] == 'C')
		g->count.pickedup++;
	g->map[step][g->pos.gx] = 'G';
	g->map[g->pos.gy][g->pos.gx] = '0';
	g->pos.gy--;
	return (0);
}

void	ft_move_enemy(t_game *g)
{
	int	direction;

	direction = rand() % 4;
	if (direction == 0)
		reaper_up(g);
	else if (direction == 1)
		reaper_down(g);
	else if (direction == 2)
		reaper_left(g);
	else if (direction == 3)
		reaper_right(g);
}
