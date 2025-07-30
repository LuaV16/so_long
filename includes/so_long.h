/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:02:37 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 13:26:10 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strcmp(char *s1, char *s2);
void	check_errors(char *filename, size_t width, size_t height);
void	get_width_and_height(int fd, size_t *width, size_t *height);
size_t	get_width(const char *s);
void	free_map(char **map);
void	start_window(char **map, size_t width, size_t height);
void	put_collectibles(char **map, mlx_t *mlx, size_t width, size_t height);
void	put_enemys(char **map, mlx_t *mlx, size_t width, size_t height);

#endif