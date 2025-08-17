/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:48:59 by lvargas-          #+#    #+#             */
/*   Updated: 2025/08/11 16:42:13 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'F' && map[i][j] != 'C')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	get_char_position(t_game *paquita)
{
	int	i;
	int	j;

	i = 0;
	while (paquita->map[i])
	{
		j = 0;
		while (paquita->map[i][j] != '\n' && paquita->map[i][j] != '\0')
		{
			if (paquita->map[i][j] == 'P')
			{
				paquita->player_x = j;
				paquita->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int get_counters(char **map, int *character, int *exit, int *collectibles)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				(*character)++;
			else if (map[i][j] == 'E')
				(*exit)++;
			else if (map[i][j] == 'C')
				(*collectibles)++;
			j++;
		}
		i++;
	}
	if(*character != 1 || *exit != 1 || *collectibles == 0)
		return(1);
	return (0);
}

void flood_fill(char **map, int row, int col, int *collectibles_count, int *exit_count)
{
	if (*collectibles_count == 0 && *exit_count == 0)
			return ;
	
	if (row < 0 || col < 0 || map[row] == NULL || map[row][col] == '\0')
			return ;
	
	if (map[row][col] == '1' || map[row][col] == 'V')
		return ;
	
	if (map[row][col] == 'C')
		(*collectibles_count)--;
	if (map[row][col] == 'E')
		(*exit_count)--;

	map[row][col] = 'V';
		
	flood_fill(map, row + 1, col, collectibles_count, exit_count);
	flood_fill(map, row - 1, col, collectibles_count, exit_count);
	flood_fill(map, row, col + 1, collectibles_count, exit_count);
	flood_fill(map, row, col - 1, collectibles_count, exit_count);
	
}

void	check_map(t_game *paquita)
{
	int	ignored; // CAMBIAR EN ALGUN MOMENTO
	int character_count;
	int exit_count;
	int collectibles_count;

	paquita->player_x = 0;
	paquita->player_y = 0;
	character_count = 0;
	exit_count = 0;
	collectibles_count = 0;
	get_char_position(paquita);
	if (check_valid_chars(paquita->map) == 1)
	{
		ignored = write(1, "Error\nCaracter inválido en el mapa.\n", 37);
		(void)ignored;
		exit(1);
	}
	if (get_counters(paquita->map, &character_count, &exit_count, &collectibles_count) == 1)
	{
		ignored = write(1, "Error\nNumero de componentes del mapa erróneo.\n", 47);
		(void)ignored;
		exit(1);
	}
	flood_fill(paquita->map, paquita->player_y, paquita->player_x, &collectibles_count, &exit_count);
	if (collectibles_count != 0 || exit_count != 0)
	{
		ignored = write(1, "Error\nNo es posible completar el mapa.\n", 40);
		(void)ignored;
		exit(1);
	}
}
