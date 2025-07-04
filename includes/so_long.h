/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:02:37 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/04 13:17:03 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"

char *ft_strncpy(char *dest, const char *src, int n);
int ft_strcmp(char *s1, char *s2);
int has_ber_extension(char *filename);
void check_errors(char *filename);
void	get_width_and_height(int fd, size_t *width, size_t *height);
size_t	get_width(const char *s);

#endif