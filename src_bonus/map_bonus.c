/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:10:52 by dimolin2          #+#    #+#             */
/*   Updated: 2023/03/31 18:10:55 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	ft_check_format(char *path, t_game *g)
{
	if (ft_strrncmp(path, ".ber", 4))
		map_error("Invalid map format, please use .ber files!", g, 0);
}

void	ft_search_pos(t_game *g, char c, int x, int y)
{
	if (c == 'P')
	{
		g->pos.plx = x;
		g->pos.ply = y;
	}
	if (c == 'E')
	{
		g->pos.ex = x;
		g->pos.ey = y;
	}
	if (c == 'G')
	{
		g->pos.gx = x;
		g->pos.gy = y;
	}
}

void	ft_setpos(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->win.y)
	{
		x = 0;
		while (g->map[y][x] != '\0')
		{
			ft_search_pos(g, g->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	check_error(t_game *g)
{	
	g->tmp = NULL;
	if (ft_checkset("10PCEG\n", g->mapstr) == 0)
		map_error("Invalid char type!", g, 1);
	if (check_char(g) == 0)
		map_error("map must have at least 1E, 1P & 1C!", g, 1);
	g->map = ft_split(g->mapstr, '\n');
	g->tmp = ft_split(g->mapstr, '\n');
	g->win.x = ft_strlen(g->map[0]);
	free(g->mapstr);
	check_shape(g);
	ft_setpos(g);
	g->pl.x = g->pos.plx;
	g->pl.y = g->pos.ply;
	if (find_solution(g->tmp, g->win, g->pl))
	{
		ft_free_matrix(g->tmp);
		map_error("The chosen map has no valid solution!", g, 2);
	}
	ft_free_matrix(g->tmp);
}

void	read_map(char *path, t_game *g)
{
	int		fd;
	char	*line;

	ft_check_format(path, g);
	g->win.y = 1;
	g->mapstr = ft_calloc(1, 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		map_error("map not found!", g, 0);
	}
	line = get_next_line(fd);
	while (line)
	{
		g->mapstr = ft_strjoin_free(g->mapstr, line);
		line = get_next_line(fd);
		if (line)
			g->win.y++;
	}
	close(fd);
	check_error(g);
}
