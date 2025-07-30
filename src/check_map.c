/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:48:59 by lvargas-          #+#    #+#             */
/*   Updated: 2025/07/29 12:09:47 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_char_position(char **map, t_point *initial_position)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j] != '\n' && map[i][j] != '\0')
        {
            if(map[i][j] == 'P')
            {
                initial_position->x = j;
                initial_position->y = i;
                return(0);
            }
            j++;
        }
        i++;
    }
    return(1);
}
