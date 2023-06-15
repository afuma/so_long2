/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:22:59 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 16:43:02 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void next_move_enemy(t_game *game, t_node *current, int k)
{
    int init_i;
    int init_j;

    init_i = game->map->enemy[k].start.y;
    init_j = game->map->enemy[k].start.x;
    if (current == NULL || current->prev == NULL)
        return ;
    while (current->prev->prev != NULL)
        current = current->prev;
    if (current->prev->prev == NULL)
    {
        enemy_pass_on_object(game, init_i, init_j, k);
        enemy_on_player(game, current);
        enemy_path(game, current, k);
    }
}

void enemy_on_player(t_game *game, t_node *current)
{
    if (game->map->tab[current->y][current->x] == 'P')
    {
        free_visited(game->map);
        free(game->map->queue);
        free_all(game);
        write(1, "you lose.. !\n", 14);
        exit (EXIT_SUCCESS);
    }
}

void enemy_pass_on_object(t_game *game, int init_i, int init_j, int k)
{
    if (game->map->enemy[k].on_collectible == 1)
    {
        game->map->tab[init_i][init_j] = 'C';
        game->map->enemy[k].on_collectible = 0;
    }
    else if (game->map->enemy[k].on_exit == 1)
    {
        game->map->tab[init_i][init_j] = 'E';
        game->map->enemy[k].on_exit = 0;
    }
    else
        game->map->tab[init_i][init_j] = '0';
}

void enemy_path(t_game *game, t_node *current, int k)
{
    if (game->map->tab[current->y][current->x] == '0' ||
        game->map->tab[current->y][current->x] == 'C' ||
        game->map->tab[current->y][current->x] == 'E')
    {
        if (game->map->tab[current->y][current->x] == 'C')
            game->map->enemy[k].on_collectible = 1;
        if (game->map->tab[current->y][current->x] == 'E')
            game->map->enemy[k].on_exit = 1;
        game->map->tab[current->y][current->x] = 'M';
        game->map->enemy[k].start.x = current->x;
        game->map->enemy[k].start.y = current->y;
    }
}