/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:18:03 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 13:24:53 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
