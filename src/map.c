/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:16:52 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/29 13:11:19 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void start_window(void)
{
    mlx_t *mlx;
    mlx_texture_t *floor_tex;
    mlx_image_t *floor_img;

    mlx = mlx_init(64, 64, "Paquita", false);
    if (!mlx)
    {
        printf("Error: mlx_init falló\n");
        return ;
    }
    floor_tex = mlx_load_png("graphics/suelo.png");
    floor_img = mlx_texture_to_image(mlx, floor_tex);
    mlx_delete_texture(floor_tex);
    mlx_image_to_window(mlx, floor_img, 0, 0);

    mlx_loop(mlx);
    mlx_terminate(mlx);
}
