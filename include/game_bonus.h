/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:03:20 by dimolin2          #+#    #+#             */
/*   Updated: 2023/04/05 19:03:21 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "libftprintf.h"
# include "mlx.h"
# include "keynum.h"
# include "colors.h"
# include <math.h>
# include <stdlib.h>

# define SIZE 32

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_pos
{
	int	plx;
	int	ply;
	int	ex;
	int	ey;
	int	gx;
	int	gy;
}	t_pos;

typedef struct s_win
{
	int	x;
	int	y;
}	t_win;

typedef struct s_count
{
	int		moves;
	int		collect;
	int		pickedup;
	int		exit;
	int		dir;
	int		r_dir;
	char	*mov;
	char	*picked;
}	t_count;

typedef struct s_sprite
{
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*ple_front;
	void	*ple_back;
	void	*ple_right;
	void	*ple_left;
	void	*pl_front;
	void	*pl_back;
	void	*pl_right;
	void	*pl_left;
	void	*r_left;
	void	*r_right;
}	t_sprite;

typedef struct s_game
{
	char		**map;
	char		*mapstr;
	char		**tmp;
	void		*mlx_id;
	void		*mlx_win;
	t_vector	pl;
	t_sprite	sprite;
	t_count		count;
	t_pos		pos;
	t_win		win;
}	t_game;

// map check functions
int		map_error(char *msg, t_game *g, int check);
int		check_char(t_game *g);
int		ft_checkset(char *set, char *str);
int		find_solution(char **tab, t_win size, t_vector begin);
void	read_map(char *path, t_game *g);
void	check_shape(t_game *g);
void	ft_setpos(t_game *g);
void	ft_check_format(char *path, t_game *g);
void	ft_search_pos(t_game *g, char c, int x, int y);
void	ft_flood_fill(char **temp, t_win size, t_vector pos);

// enemy movement functions
int		reaper_up(t_game *g);
int		reaper_down(t_game *g);
int		reaper_right(t_game *g);
int		reaper_right(t_game *g);
void	ft_move_enemy(t_game *g);

// render and sprites functions
int		ft_render(t_game *g);
void	ft_put_img(t_game *g, char c, int x, int y);
void	ft_setsprite(t_game *g);
void	put_reaper(t_game *g, int x, int y);
void	ft_draw_pl(t_game *g, int x, int y);
void	ft_print_string(t_game *g);

// free and close functions
int		free_matrix(char **matrix);
int		ft_exit(t_game *g);
void	check_error(t_game *g);
void	ft_destroy_sprites(t_game *g);

// key hook and movement functions
int		key_hook(int key, t_game *g);
int		move_down(t_game *g);
int		move_up(t_game *g);
int		move_left(t_game *g);
int		move_right(t_game *g);

// utils functions
void	ft_check_move(t_game *g, char c);
void	ft_print_on(t_game *g);

#endif
