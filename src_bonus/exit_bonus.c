/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:40:25 by dimolin2          #+#    #+#             */
/*   Updated: 2023/03/31 19:40:26 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

int	map_error(char *msg, t_game *g, int check)
{
	if (check == 1)
		free(g->mapstr);
	if (check == 2)
		ft_free_matrix(g->map);
	if (check == 3)
	{
		free(g->mapstr);
		ft_free_matrix(g->map);
	}	
	ft_printf("Error:\n%s%s\n", RED, msg);
	exit (0);
}

void	ft_destroy_sprites(t_game *g)
{
	mlx_destroy_image(g->mlx_id, g->sprite.wall);
	mlx_destroy_image(g->mlx_id, g->sprite.exit);
	mlx_destroy_image(g->mlx_id, g->sprite.collect);
	mlx_destroy_image(g->mlx_id, g->sprite.floor);
	mlx_destroy_image(g->mlx_id, g->sprite.pl_front);
	mlx_destroy_image(g->mlx_id, g->sprite.pl_back);
	mlx_destroy_image(g->mlx_id, g->sprite.pl_right);
	mlx_destroy_image(g->mlx_id, g->sprite.pl_left);
	mlx_destroy_image(g->mlx_id, g->sprite.r_left);
	mlx_destroy_image(g->mlx_id, g->sprite.r_right);
}

int	ft_exit(t_game *g)
{
	if (g->map)
		ft_free_matrix(g->map);
	ft_printf("\n\n%sGAME ENDED!\n%sTotal Moves: %d\n\n", GREEN, \
			BLUE, g->count.moves);
	ft_destroy_sprites(g);
	mlx_clear_window(g->mlx_id, g->mlx_win);
	mlx_destroy_window(g->mlx_id, g->mlx_win);
	mlx_destroy_display(g->mlx_id);
	free(g->mlx_id);
	exit(0);
	return (0);
}
