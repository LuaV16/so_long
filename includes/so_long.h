/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:02:37 by lvargas-          #+#    #+#             */
/*   Updated: 2025/08/17 20:09:16 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53

# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_game
{
    mlx_t   *mlx;
    char    **map;
    int     player_x;
    int     player_y;
    int map_width;
    int map_height;
    int     moves;
    mlx_image_t  *moves_img;
    int collectibles;
    mlx_image_t *win;
    int win_condition;
}   t_game;

char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);
void	check_errors(char *filename, t_game *paquita);
void	get_width_and_height(int fd, t_game *paquita);
size_t	get_width(const char *s);
void	free_map(char **map);
void	start_window(t_game *paquita);
void	put_collectibles(char **map, mlx_t *mlx, size_t width, size_t height);
void	put_enemys(char **map, mlx_t *mlx, size_t width, size_t height);
void	check_map(t_game *paquita);
void    key_hook(mlx_key_data_t keydata, void *param);
void	put_floor(char **map, mlx_t *mlx, size_t width, size_t height);
void	put_walls(char **map, mlx_t *mlx, size_t width, size_t height);
void	put_character(t_game *paquita);
void	put_exit(char **map, mlx_t *mlx, size_t width, size_t height);
void    put_map(t_game *paquita);
void    get_collectibles(t_game *paquita);

#endif