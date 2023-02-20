/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:46:50 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/17 14:20:21 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define WALL_PATH "./assets/wall.xpm"
# define FLOOR_PATH "./assets/floor.xpm"
# define COLLECTIBLE_PATH "./assets/key.xpm"
# define EXIT_CLOSED_PATH "./assets/trapdoor_closed.xpm"
# define PLAYER_DOWN_PATH "./assets/player_down.xpm"
# define SPRITES_SIZE 32
# define NB_SPRITES 5
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2 
# define CLOSE 53

typedef struct s_img {
	void	*mat[NB_SPRITES];
	int		w;
	int		h;
}			t_img;

typedef struct s_player {
	int		x;
	int		y;
	int		moves;
	int		items;
}				t_player;

typedef struct s_mlx {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_img		img;
	t_player	player;
}				t_mlx;

/* args */
int		check_args(int ac, char **av);

/* game */
void	exit_game(t_mlx *mlx, char *str);
int		close_window(t_mlx *mlx);
int		key_pressed(int key, t_mlx *mlx);

/* map */
void	check_valid_map(char **map);
void	init_map(char **map, t_mlx *mlx);
char	**parse_map(char *file);
int		get_map_size(char **map);
int		get_map_height(char **map);
int		get_map_width(char **map);
void	free_map(char **map);

/* player */
void	move_player(int keycode, t_mlx *mlx);

/* sprites */
void	init_sprites(t_mlx *mlx);
void	set_floor_sprite(t_mlx *mlx, int x, int y);
void	set_wall_sprite(t_mlx *mlx, int x, int y);
void	set_collectible_sprite(t_mlx *mlx, int x, int y);
void	set_exit_closed_sprite(t_mlx *mlx, int x, int y);
void	set_player_sprite(t_mlx *mlx, int x, int y);

/* utils */
int		ft_strlen(char *str);
int		print_error(char *str);
void	exit_error(char *str);
void	exit_free_error(char *str, char **map);

#endif
