/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:58:11 by blax              #+#    #+#             */
/*   Updated: 2023/06/08 12:21:51 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void cpy_map(t_data *map, t_data *tmp_map)
{
	tmp_map->size.y = map->size.y;
    tmp_map->size.x = map->size.x;
	tmp_map->player.pos.y = map->player.pos.y;
    tmp_map->player.pos.x = map->player.pos.x;
	tmp_map->collectibles = map->collectibles;
	tmp_map->max_collectibles = map->max_collectibles;
	tmp_map->find = map->find;
}

int is_exitable(t_game *game)
{
	t_data *tmp_map;
	int find;

	find = 0;
	tmp_map = (t_data *) malloc(sizeof(t_data));
	if(!tmp_map)
		ft_error(game, "Memory allocation of tmp_map failed !\n");
	tmp_map->tab = make_area(game->map->tab, game->map->size.x, game->map->size.y);
	cpy_map(game->map, tmp_map);
	f_efill(tmp_map, tmp_map->player.pos.y, tmp_map->player.pos.x);
	find = tmp_map->find;
    free_map(&tmp_map);
	if(find)
		return (1);
	else
		return (0);
}

void f_efill(t_data *map, int row, int col)
{
    if (row < 0 || col < 0 || row >= map->size.y || col >= map->size.x ||
		map->tab[row][col] == '1' ||
		map->tab[row][col] == 'F' || map->find == 1)
        	return ;
	if (map->tab[row][col] == '0' || map->tab[row][col] == 'P' ||
		map->tab[row][col] == 'C' || map->tab[row][col] == 'M')
			map->tab[row][col] = 'F';
    if (map->tab[row][col] == 'E')
	{
		map->find = 1;
		map->tab[row][col] = 'F';
	}

	f_efill(map, row -1, col);
    f_efill(map, row +1, col);
    f_efill(map, row, col - 1);
    f_efill(map, row, col + 1);
}

int is_collectables(t_game *game)
{
	t_data *tmp_map;
	int collectibles;

	collectibles = 0;
	tmp_map = (t_data *) malloc(sizeof(t_data));
	if(!tmp_map)
		ft_error(game, "Memory allocation of tmp_map failed !\n");
	tmp_map->tab = make_area(game->map->tab, game->map->size.x, game->map->size.y);
	cpy_map(game->map, tmp_map);
	f_cfill(tmp_map, tmp_map->player.pos.y, tmp_map->player.pos.x);
	collectibles = tmp_map->collectibles;
    free_map(&tmp_map);
	if(game->map->max_collectibles == collectibles)
		return (1);
	else
		return (0);
}

void f_cfill(t_data *map, int row, int col)
{
    if (row < 0 || col < 0 || row >= map->size.y || col >= map->size.x ||
		map->tab[row][col] == '1' ||
		map->tab[row][col] == 'F' || map->collectibles == map->max_collectibles)
        	return ;
	if (map->tab[row][col] == '0' || map->tab[row][col] == 'P' ||
		map->tab[row][col] == 'E' || map->tab[row][col] == 'M')
			map->tab[row][col] = 'F';
    if (map->tab[row][col] == 'C')
	{
		map->collectibles += 1;
		map->tab[row][col] = 'F';
	}

	f_cfill(map, row -1, col);
    f_cfill(map, row +1, col);
    f_cfill(map, row, col - 1);
    f_cfill(map, row, col + 1);
}

int is_mechable(t_game *game)
{
	t_data *tmp_map;
	int enemy;

	enemy = 0;
	tmp_map = (t_data *) malloc(sizeof(t_data));
	if(!tmp_map)
		ft_error(game, "Memory allocation of tmp_map failed !\n");
	tmp_map->tab = make_area(game->map->tab, game->map->size.x, game->map->size.y);
	cpy_map(game->map, tmp_map);
	f_cfill(tmp_map, tmp_map->player.pos.y, tmp_map->player.pos.x);
	enemy = tmp_map->nb_enemy;
    free_map(&tmp_map);
	if(game->map->max_enemy == enemy)
		return (1);
	else
		return (0);
}

void f_mfill(t_data *map, int row, int col)
{
    if (row < 0 || col < 0 || row >= map->size.y || col >= map->size.x ||
		map->tab[row][col] == '1' ||
		map->tab[row][col] == 'F' || map->nb_enemy == map->max_enemy)
        	return ;
	if (map->tab[row][col] == '0' || map->tab[row][col] == 'P' ||
		map->tab[row][col] == 'E' || map->tab[row][col] == 'C')
			map->tab[row][col] = 'F';
    if (map->tab[row][col] == 'M')
	{
		map->nb_enemy += 1;
		map->tab[row][col] = 'F';
	}

	f_cfill(map, row -1, col);
    f_cfill(map, row +1, col);
    f_cfill(map, row, col - 1);
    f_cfill(map, row, col + 1);
}