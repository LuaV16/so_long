/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:30:47 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/03 17:13:42 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int has_ber_extension(char *filename)
{
    size_t len;

    len = ft_strlen(filename);
    if (len < 4)
        return (0);
    return (ft_strcmp(filename + len - 4, ".ber") == 0);
}

int has_right_dimensions(int fd)
{
    char *line;
    int width;
    int height;

    line = get_next_line(fd);
    get_width_and_height(fd, &width, &height);
    
}

void check_errors(char *filename)
{
    int ignored;
    
    if (has_ber_extension(filename) == 0)
    {
        ignored = write(1, "Error\nExtensión no válida.\n", 29);
        (void)ignored;
        exit(1);
    }
}

