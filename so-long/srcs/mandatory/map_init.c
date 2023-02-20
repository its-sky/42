/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/17 13:21:15 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_material(char **map, t_mlx *mlx, int x, int y)
{
	if (map[y][x] == '0')
		set_floor_sprite(mlx, x, y);
	else if (map[y][x] == '1')
		set_wall_sprite(mlx, x, y);
	else if (map[y][x] == 'C')
		set_collectible_sprite(mlx, x, y);
	else if (map[y][x] == 'E')
		set_exit_closed_sprite(mlx, x, y);
	else if (map[y][x] == 'P')
		set_player_sprite(mlx, x, y);
}

void	init_map(char **map, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	mlx->player.items = 0;
	init_sprites(mlx);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			set_material(map, mlx, x, y);
			x++;
		}
		y++;
	}
	ft_printf("Number of moves : %d\n", mlx->player.moves);
}
