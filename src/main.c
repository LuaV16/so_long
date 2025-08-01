/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:01:00 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/30 12:21:39 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void	get_width_and_height(int fd, size_t *width, size_t *height)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	*width = 0;
	*height = 0;
	if (line)
	{
		tmp = line;
		while (*line && *line != '\n')
		{
			(*width)++;
			line++;
		}
		(*height)++;
		free(tmp);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*height)++;
	}
	free(line);
}

char	**fill_matrix(int fd, int width, int height)
{
	char	*line;
	char	**map;
	int		y;

	map = (char **)malloc((height + 1) * sizeof(char **));
	if (!map)
		return (free(map), map = NULL, NULL);
	y = 0;
	while (y < height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[y] = (char *)malloc((width + 1) * sizeof(char));
		if (!map[y])
			return (free(map), map = NULL, NULL);
		ft_strncpy(map[y], line, width);
		map[y][width] = '\0';
		free(line);
		y++;
	}
	return (map);
}

char	**read_map(char *filename, size_t width, size_t height)
{
	int		fd1;
	int		fd2;
	char	**map;

	fd1 = open(filename, O_RDONLY);
	if (fd1 < 0)
	{
		// Meter error
	}
	close(fd1);
	fd2 = open(filename, O_RDONLY);
	if (fd2 < 0)
	{
		// Meter error
	}
	map = fill_matrix(fd2, width, height);
	close(fd2);
	return (map);
}

int	main(void)
{
	char **map;
	int fd;
	size_t	width;
	size_t	height;
	
	fd = open("maps/valid1.ber", O_RDONLY);
	get_width_and_height(fd, &width, &height);
	check_errors("maps/valid1.ber", width, height);
	map = read_map("maps/valid1.ber", width, height);

	start_window(map, width, height);
	
	free_map(map);
	return (0);
}
