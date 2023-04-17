/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:36:26 by dimolin2          #+#    #+#             */
/*   Updated: 2023/04/01 20:36:27 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	ft_check_move(t_game *g, char c)
{
	if (c == 'G')
	{
		ft_printf("\n\n%sOhh no, the reaper got you!\n", RED);
		g->count.moves++;
		ft_exit(g);
	}
	else if (c == 'E' && g->count.pickedup == g->count.collect)
	{
		ft_printf("\n\n%sCongratulations, you won!\n", GREEN);
		g->count.moves++;
		ft_exit(g);
	}
	else if (c == 'C')
		g->count.pickedup++;
}

void	ft_print_on(t_game *g)
{
	ft_printf("\n%sTotal moves: %d", BLUE, g->count.moves);
}

void	ft_print_string(t_game *g)
{
	g->count.mov = ft_itoa(g->count.moves);
	mlx_string_put(g->mlx_id, g->mlx_win, 160, 21, 0xFFFFFF, g->count.mov);
	free(g->count.mov);
	mlx_string_put(g->mlx_id, g->mlx_win, 80, 20, 0xFFFF00, "Total moves:");
	g->count.picked = ft_itoa(g->count.collect - g->count.pickedup);
	mlx_string_put(g->mlx_id, g->mlx_win, 340, 21, 0xFFFFFF, g->count.picked);
	free(g->count.picked);
	mlx_string_put(g->mlx_id, g->mlx_win, 190, 20, 0xFFFF00, \
			"Remaining collectibles:");
	if (g->count.collect == g->count.pickedup)
		mlx_string_put(g->mlx_id, g->mlx_win, 440, 20, 0xFFFF00, \
			"Reach the exit!!!");
}
