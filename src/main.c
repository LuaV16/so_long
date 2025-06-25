/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:01:00 by lvargas-          #+#    #+#             */
/*   Updated: 2025/06/25 18:16:31 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

size_t	ft_linelen(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*s && *s != '\0' && *s != '\n')
	{
		len++;
		s++;
	}
	return (len);
}

char **create_matrix(line_number, line_size)
{
    char **matrix;
    int n;

    matrix = (char **)malloc((line_number + 1) * sizeof(char *));
    if (matrix == NULL) {
        perror("Error al reservar memoria");
        return (NULL);
    }
    n = 0;
    while (n < line_number)
    {
        matrix[n] = (char *)malloc((line_size + 1) * sizeof(char));
        n++;
        if (matrix[n] == NULL) 
        {
            perror("Error al reservar memoria");
            return (NULL);
        }
    }
}

int check_size(fd)
{
    char    *line;
    int     line_number;
    size_t     line_size;
    int     first_time;

    first_time = 0;
    line_number = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        else
            line_number++;
        if (first_time == 0)
        {
            line_size = ft_linelen(line);
            first_time = 1;
        }
        if (ft_linelen(line) > line_size || ft_linelen(line) < line_size)
            return (-1);
    }
    return (line_number);
}

int main(void)
{
    int fd;
    int line_number;
    char **matrix;

    fd = open("./maps/valid1.ber", O_RDONLY);
    line_number = check_size(fd);
    close(fd);
    if (line_number == -1)
        perror("Todas las líneas deben ser del mismo tamaño.");
    else
    {
        fd = open("./maps/valid1.ber", O_RDONLY);
        matrix = create_matrix(line_number, //line size! meter como variable global)
    }
    return (0);
}
