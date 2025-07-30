/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:16:52 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 13:28:12 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(char **map, mlx_t *mlx, size_t width, size_t height)
{
	size_t			x;
	size_t			y;
	mlx_texture_t	*floor_tex;
	mlx_image_t		*floor_img;

	floor_tex = mlx_load_png("graphics/suelo.png");
	floor_img = mlx_texture_to_image(mlx, floor_tex);
	mlx_delete_texture(floor_tex);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == '0')
			{
				mlx_image_to_window(mlx, floor_img, y * TILE_SIZE, x
					* TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}

void	put_walls(char **map, mlx_t *mlx, size_t width, size_t height)
{
	size_t			x;
	size_t			y;
	mlx_texture_t	*walls_tex;
	mlx_image_t		*walls_img;

	walls_tex = mlx_load_png("graphics/silla.png");
	walls_img = mlx_texture_to_image(mlx, walls_tex);
	mlx_delete_texture(walls_tex);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == '1')
			{
				mlx_image_to_window(mlx, walls_img, y * TILE_SIZE, x
					* TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}

void	put_character(char **map, mlx_t *mlx, size_t width, size_t height)
{
	size_t			x;
	size_t			y;
	mlx_texture_t	*character_tex;
	mlx_image_t		*character_img;

	character_tex = mlx_load_png("graphics/paquita.png");
	character_img = mlx_texture_to_image(mlx, character_tex);
	mlx_delete_texture(character_tex);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == 'P')
			{
				mlx_image_to_window(mlx, character_img, y * TILE_SIZE, x
					* TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}

void	put_exit(char **map, mlx_t *mlx, size_t width, size_t height)
{
	size_t			x;
	size_t			y;
	mlx_texture_t	*exit_tex;
	mlx_image_t		*exit_img;

	exit_tex = mlx_load_png("graphics/Navarrete.png");
	exit_img = mlx_texture_to_image(mlx, exit_tex);
	mlx_delete_texture(exit_tex);
	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			if (map[x][y] == 'E')
			{
				mlx_image_to_window(mlx, exit_img, y * TILE_SIZE, x
					* TILE_SIZE);
			}
			y++;
		}
		x++;
	}
}

void	start_window(char **map, size_t width, size_t height)
{
	mlx_t	*mlx;

	mlx = mlx_init(width * TILE_SIZE, height * TILE_SIZE, "Paquita", false);
	if (!mlx)
	{
		printf("Error: mlx_init falló\n");
		return ;
	}
	put_floor(map, mlx, width, height);
	put_walls(map, mlx, width, height);
	put_character(map, mlx, width, height);
	put_exit(map, mlx, width, height);
	put_collectibles(map, mlx, width, height);
	put_enemys(map, mlx, width, height);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
