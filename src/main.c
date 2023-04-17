/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:56:13 by dimolin2          #+#    #+#             */
/*   Updated: 2023/03/31 17:56:14 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	start_game(t_game *g)
{
	g->mlx_id = mlx_init();
	g->mlx_win = mlx_new_window(g->mlx_id, g->win.x * SIZE, \
			g->win.y * SIZE, "so_long");
	ft_setsprite(g);
	g->count.moves = 0;
	g->count.pickedup = 0;
	g->count.dir = 0;
	ft_printf("%sGAME STARTED!\n\n%sCollect all gold and escape!\n\n", GREEN, BLUE);
	mlx_loop_hook(g->mlx_id, ft_render, (void *)g);
	mlx_hook(g->mlx_win, 17, 0, ft_exit, (void *)g);
	mlx_key_hook(g->mlx_win, key_hook, (void *)g);
	mlx_loop(g->mlx_id);
}

int	main(int ac, char **av)
{
	char	*map_path;
	t_game	g;

	map_path = av[1];
	if (ac == 2)
	{
		read_map(map_path, &g);
		start_game(&g);
	}
	else if (ac > 2)
		map_error("Too many arguments!", &g, 0);
	else
		map_error("You need to choose a map to start the game!", &g, 0);
}
