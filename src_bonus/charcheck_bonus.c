/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:08:02 by dimolin2          #+#    #+#             */
/*   Updated: 2023/03/31 19:08:03 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	check_shape(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->win.y)
	{
		if (ft_strlen(g->map[i]) != g->win.x)
			map_error("Map must be rectangular!", g, 2);
		if (g->map[i][0] != '1' || g->map[i][g->win.x - 1] != '1')
			map_error("Map not sorrounded by wall!", g, 2);
		i++;
	}
	i = 0;
	while (g->map[0][i] && g->map[g->win.y - 1][i])
	{
		if (g->map[0][i] != '1' || g->map[g->win.y - 1][i] != '1')
			map_error("Map not sorrounded by wall!", g, 2);
		i++;
	}
}

int	check_char(t_game *g)
{
	int	i;
	int	pl;
	int	e;

	pl = 0;
	e = 0;
	g->count.collect = 0;
	i = 0;
	while (g->mapstr[i])
	{
		if (g->mapstr[i] == 'P')
			pl++;
		if (g->mapstr[i] == 'C')
			g->count.collect++;
		if (g->mapstr[i] == 'E')
			e++;
		i++;
	}
	if (pl > 0 && e == 1 && g->count.collect >= 1)
		return (1);
	return (0);
}

int	ft_checkset(char *set, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_strchr(set, str[i]))
			return (0);
		i++;
	}
	return (1);
}
