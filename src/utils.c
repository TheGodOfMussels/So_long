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

#include "game.h"

void	ft_check_move(t_game *g, char c)
{
	if (c == 'E' && g->count.pickedup == g->count.collect)
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
