/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:18:03 by lvargas-          #+#    #+#             */
/*   Updated: 2025/08/17 20:13:05 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	put_collectibles(char **map, mlx_t *mlx, size_t width, size_t height)
{
	size_t			x;
	size_t			y;
	mlx_texture_t	*collectible_tex;
	mlx_image_t		*collectible_img;

	collectible_tex = mlx_load_png("graphics/churro.png");
	collectible_img = mlx_texture_to_image(mlx, collectible_tex);
	mlx_delete_texture(collectible_tex);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == 'C')
			{
				mlx_image_to_window(mlx, collectible_img, y * TILE_SIZE, x
					* TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}

void	put_enemys(char **map, mlx_t *mlx, size_t width, size_t height)
{
	size_t			x;
	size_t			y;
	mlx_texture_t	*enemy_tex;
	mlx_image_t		*enemy_img;

	enemy_tex = mlx_load_png("graphics/paparazzi.png");
	enemy_img = mlx_texture_to_image(mlx, enemy_tex);
	mlx_delete_texture(enemy_tex);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == 'F')
			{
				mlx_image_to_window(mlx, enemy_img, y * TILE_SIZE, x
					* TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}

void put_counter(t_game *paquita)
{
	char *moves_str;
	char *msg;
	
	moves_str = ft_itoa(paquita->moves);
	msg = ft_strjoin("Moves: ", moves_str);
	paquita->moves_img = mlx_put_string(paquita->mlx, msg, 10, 10);
	free(moves_str);
	free(msg);
}

void put_win_img(t_game *paquita)
{
	mlx_texture_t *win_tex;
	mlx_image_t *win_img;
	int pos_x;
	int pos_y;

	win_tex = mlx_load_png("graphics/win.png");
	win_img = mlx_texture_to_image(paquita->mlx, win_tex);
	mlx_delete_texture(win_tex);
	pos_x = (paquita->mlx->width - 120) / 2;
	pos_y = (paquita->mlx->height - 104) / 2;
	mlx_image_to_window(paquita->mlx, win_img, pos_x, pos_y);
}

void put_map(t_game *paquita)
{
	put_floor(paquita->map, paquita->mlx, paquita->map_width, paquita->map_height);
	put_walls(paquita->map, paquita->mlx, paquita->map_width, paquita->map_height);
	put_character(paquita);
	put_exit(paquita->map, paquita->mlx, paquita->map_width, paquita->map_height);
	put_collectibles(paquita->map, paquita->mlx, paquita->map_width, paquita->map_height);
	put_enemys(paquita->map, paquita->mlx, paquita->map_width, paquita->map_height);
	put_counter(paquita);
	if (paquita->win_condition == 1)
		put_win_img(paquita);
}

