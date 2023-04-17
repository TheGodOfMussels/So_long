/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:11:50 by dimolin2          #+#    #+#             */
/*   Updated: 2023/04/01 20:11:51 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	move_up(t_game *g)
{
	int	step;

	step = g->pos.ply;
	ft_check_move(g, g->map[g->pos.ply - 1][g->pos.plx]);
	if (g->map[--step][g->pos.plx] == '1' || g->map[step][g->pos.plx] == 'E')
		return (0);
	g->map[step][g->pos.plx] = 'P';
	g->map[g->pos.ply][g->pos.plx] = '0';
	g->pos.ply--;
	g->count.dir = 1;
	g->count.moves++;
	ft_print_on(g);
	return (0);
}

int	move_down(t_game *g)
{
	int	step;

	step = g->pos.ply;
	ft_check_move(g, g->map[g->pos.ply + 1][g->pos.plx]);
	if (g->map[++step][g->pos.plx] == '1' || g->map[step][g->pos.plx] == 'E')
		return (0);
	g->map[step][g->pos.plx] = 'P';
	g->map[g->pos.ply][g->pos.plx] = '0';
	g->pos.ply++;
	g->count.dir = 0;
	g->count.moves++;
	ft_print_on(g);
	return (0);
}

int	move_left(t_game *g)
{
	int	step;

	step = g->pos.plx;
	ft_check_move(g, g->map[g->pos.ply][g->pos.plx - 1]);
	if (g->map[g->pos.ply][--step] == '1' || g->map[g->pos.ply][step] == 'E')
		return (0);
	g->map[g->pos.ply][step] = 'P';
	g->map[g->pos.ply][g->pos.plx] = '0';
	g->pos.plx--;
	g->count.dir = 2;
	g->count.moves++;
	ft_print_on(g);
	return (0);
}

int	move_right(t_game *g)
{
	int	step;

	step = g->pos.plx;
	ft_check_move(g, g->map[g->pos.ply][g->pos.plx + 1]);
	if (g->map[g->pos.ply][++step] == '1' || g->map[g->pos.ply][step] == 'E')
		return (0);
	g->map[g->pos.ply][step] = 'P';
	g->map[g->pos.ply][g->pos.plx] = '0';
	g->pos.plx++;
	g->count.dir = -2;
	g->count.moves++;
	ft_print_on(g);
	return (0);
}

int	key_hook(int key, t_game *g)
{
	if (key == 65307)
	{
		ft_printf("\n%sYou quitted the game!\n\n", RED);
		ft_exit(g);
	}
	if (key == W_KEY || key == UP_ARROW)
		move_up(g);
	else if (key == S_KEY || key == DOWN_ARROW)
		move_down(g);
	else if (key == A_KEY || key == LEFT_ARROW)
		move_left(g);
	else if (key == D_KEY || key == RIGHT_ARROW)
		move_right(g);
	return (0);
}
