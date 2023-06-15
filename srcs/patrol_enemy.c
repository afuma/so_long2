/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:27:24 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 16:39:19 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void visited_and_push(t_game *game, t_node *current, int k)
{
    t_node *neighbour;
    int priority;
    int nx;
    int ny;
    int dir;

    dir = 0;
    while (dir < 4)
    {
        nx = current->x + game->map->queue->dx[dir];
        ny = current->y + game->map->queue->dy[dir];
        if (is_valid(game->map, nx, ny) && !game->map->visited[ny][nx])
        {
            neighbour = node_create(nx, ny);
            neighbour->prev = current;
            priority = heuristic(neighbour, &game->map->enemy[k].end);
            priority_queue_push(game->map->queue, neighbour, priority);
            // print_queue(game->map->queue, &game->map->enemy[k].end);
        }
        dir++;
    }
}

void a_star(t_game *game, int k)
{
    t_node *current;

    init_enemy(game);
    init_visited(game->map);
    priority_queue_create(game);
    priority_queue_push(game->map->queue, &game->map->enemy[k].start, 0);
    // print_queue(game->map->queue, &game->map->enemy[k].end);
    while (!priority_queue_empty(game->map->queue))
    {
        current = priority_queue_pop(game->map->queue);
        game->map->visited[current->y][current->x] = 1;
        if (heuristic(current, &game->map->enemy[k].end) == 0)
        {
            next_move_enemy(game, current, k);
            break;
        }
        visited_and_push(game, current, k);
    }
    free_visited(game->map);
    free(game->map->queue);
    if (priority_queue_empty(game->map->queue))
        printf("No solution !\n");
}

void update_enemy(t_game *game)
{
    int k;

    k = 0;
    while (k < game->map->max_enemy)
    {
        a_star(game, k);
        k++;
    }
}

void init_enemy(t_game *game)
{
    int k;

    k = 0;
    while (k < game->map->max_enemy)
    {
        game->map->enemy[k].end.x = game->map->player.pos.x;
        game->map->enemy[k].end.y = game->map->player.pos.y;
        k++;
    }
}