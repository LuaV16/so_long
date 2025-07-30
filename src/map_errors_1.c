/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:30:47 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 13:31:09 by lvargas-         ###   ########.fr       */
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

int	has_right_dimensions(char *filename, size_t width, size_t height)
{
	char	*line;
	size_t	n;
	int		fd;

	n = 0;
	fd = open(filename, O_RDONLY);
	while (n < height)
	{
		line = get_next_line(fd);
		if (get_width(line) != width)
		{
			free(line);
			line = NULL;
			return (0);
		}
		free(line);
		n++;
	}
	close(fd);
	return (1);
}

int	check_line_walls(char *line, size_t width, size_t j, size_t height, int fd)
{
	size_t	i;

	if (j == 0 || j == height - 1)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] != '1')
				return (free(line), close(fd), 0);
			i++;
		}
	}
	else
	{
		if (line[0] != '1' || line[width - 1] != '1')
			return (free(line), close(fd), 0);
	}
	return (1);
}

int	has_walls(char *filename, size_t width, size_t height)
{
	char	*line;
	size_t	j;
	int		fd;

	fd = open(filename, O_RDONLY);
	j = 0;
	while (j < height)
	{
		line = get_next_line(fd);
		if (!check_line_walls(line, width, j, height, fd))
			return (0);
		free(line);
		j++;
	}
	close(fd);
	return (1);
}

void	check_errors(char *filename, size_t width, size_t height)
{
	int	ignored; // CAMBIAR EN ALGUN MOMENTO

	if (has_ber_extension(filename) == 0)
	{
		ignored = write(1, "Error\nExtensión no válida.\n", 29);
		(void)ignored;
		exit(1);
	}
	if (has_right_dimensions(filename, width, height) == 0)
	{
		ignored = write(1, "Error\nDimensiones del mapa no válidas.\n", 40);
		(void)ignored;
		exit(1);
	}
	if (has_walls(filename, width, height) == 0)
	{
		ignored = write(1, "Error\nEl mapa debe tener paredes.\n", 34);
		(void)ignored;
		exit(1);
	}
}
