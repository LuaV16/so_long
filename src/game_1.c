/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:49:47 by lvargas-          #+#    #+#             */
/*   Updated: 2025/08/17 20:12:30 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_collectibles(t_game *paquita)
{
	int	i;
	int	j;

    paquita->collectibles = 0;
	i = 0;
	while (paquita->map[i])
	{
		j = 0;
		while (paquita->map[i][j] != '\n' && paquita->map[i][j] != '\0')
		{
			if (paquita->map[i][j] == 'C')
				paquita->collectibles++;
			j++;
		}
		i++;
	}
}

void move_character(t_game *paquita, int x, int y)
{
    int new_x;
    int new_y;

    new_x = paquita->player_x + x;
    new_y = paquita->player_y + y;
    if (paquita->map[new_y][new_x] == '1')
        return ;
    else if (paquita->map[new_y][new_x] == 'E' && paquita->collectibles != 0)
        return ;
    else if (paquita->map[new_y][new_x] == 'C')
        paquita->collectibles--;
    else if (paquita->map[new_y][new_x] == 'E' && paquita->collectibles == 0)
    {
        paquita->win_condition = 1;
        paquita->map[paquita->player_y][paquita->player_x] = '0';
        paquita->moves++;
        put_map(paquita);
        return ;
    }
    paquita->map[paquita->player_y][paquita->player_x] = '0';
    paquita->player_x = new_x;
    paquita->player_y = new_y;
    paquita->map[paquita->player_y][paquita->player_x] = 'P';
    paquita->moves++;
    put_map(paquita);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            move_character(game, 0, -1);
        else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            move_character(game, 0, 1);
        else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            move_character(game, -1, 0);
        else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            move_character(game, 1, 0);
        else if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(game->mlx);
	}
}
