/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:30:47 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/04 14:00:08 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	has_ber_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".ber") == 0);
}

int	has_right_dimensions(char *filename)
{
	char	*line;
	size_t	width;
	size_t	height;
	size_t	n;
	int		fd;

	fd = open(filename, O_RDONLY);
	get_width_and_height(fd, &width, &height);
	close(fd);
	n = 0;
	fd = open(filename, O_RDONLY);
	while (n < height)
	{
		line = get_next_line(fd);
		if (get_width(line) != width)
		{
			free(line);
			return (0);
		}
		free(line);
		n++;
	}
	return (1);
}

int has_walls(char *filename)
{
	char	*line;
	int n;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		n = 0;
		while (line[n] != '\n')
		{
			if (line[n] != '1')
			{
				
			}
			n++;
		}
		free(line);
		n++;
	}
	return (1);
}

void	check_errors(char *filename)
{
	int	ignored;

	if (has_ber_extension(filename) == 0)
	{
		ignored = write(1, "Error\nExtensión no válida.\n", 29);
		(void)ignored;
		exit(1);
	}
	if (has_right_dimensions(filename) == 0)
	{
		ignored = write(1, "Error\nDimensiones del mapa no válidas.\n", 39);
		(void)ignored;
		exit(1);
	}
}
