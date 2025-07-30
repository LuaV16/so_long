/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:23:22 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/04 16:43:06 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void free_map(char **map)
{
    int n;

    n = 0;
    while (map[n])
    {
        free(map[n]);
        n++;
    }
    free(map);
}
