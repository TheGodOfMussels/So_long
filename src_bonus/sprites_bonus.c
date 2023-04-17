/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:24:21 by dimolin2          #+#    #+#             */
/*   Updated: 2023/04/01 19:24:22 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	ft_setsprite(t_game *g)
{
	int	size;

	size = SIZE;
	g->sprite.wall = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/wall.xpm", &size, &size);
	g->sprite.floor = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/floor.xpm", &size, &size);
	g->sprite.collect = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/collectible.xpm", &size, &size);
	g->sprite.exit = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/exit.xpm", &size, &size);
	g->sprite.pl_front = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/player/player_front.xpm", &size, &size);
	g->sprite.pl_back = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/player/player_back.xpm", &size, &size);
	g->sprite.pl_left = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/player/player_left.xpm", &size, &size);
	g->sprite.pl_right = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/player/player_right.xpm", &size, &size);
	g->sprite.r_left = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/enemy/reaper_left.xpm", &size, &size);
	g->sprite.r_right = mlx_xpm_file_to_image(g->mlx_id, \
					"sprites/enemy/reaper_right.xpm", &size, &size);
}

void	ft_draw_pl(t_game *g, int x, int y)
{
	if (g->count.dir == 0)
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.pl_front,
			x * SIZE, y * SIZE);
	else if (g->count.dir == 1)
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.pl_back,
			x * SIZE, y * SIZE);
	else if (g->count.dir == 2)
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.pl_left,
			x * SIZE, y * SIZE);
	else if (g->count.dir == -2)
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.pl_right,
			x * SIZE, y * SIZE);
}

void	put_reaper(t_game *g, int x, int y)
{
	if (g->count.r_dir == 1)
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.r_right,
			x * SIZE, y * SIZE);
	else if (g->count.r_dir == 0)
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.r_left,
			x * SIZE, y * SIZE);
}

void	ft_put_img(t_game *g, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.floor,
			x * SIZE, y * SIZE);
	else if (c == '1')
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.wall,
			x * SIZE, y * SIZE);
	else if (c == 'P')
		ft_draw_pl(g, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.collect,
			x * SIZE, y * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx_id, g->mlx_win, g->sprite.exit,
			x * SIZE, y * SIZE);
	else if (c == 'G')
		put_reaper(g, x, y);
	ft_print_string(g);
}

int	ft_render(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->win.y)
	{
		x = 0;
		while (g->map[y][x])
		{
			ft_put_img(g, g->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (0);
}
