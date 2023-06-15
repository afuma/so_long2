/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_enemy_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:38:45 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 16:38:57 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int is_valid(t_data *map, int x, int y) {
    return (x >= 0) && (x < map->size.x) && (y >= 0) && (y < map->size.y) && (map->tab[y][x] != '1');
}

int heuristic(t_node *a, t_node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void init_visited(t_data *map)
{
    map->visited = (int **) malloc(map->size.y * sizeof(int*));
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->size.y)
    {
        map->visited[i] = malloc(map->size.x * sizeof(int));
        while (j < map->size.x)
        {
            map->visited[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
}

void free_visited(t_data *map)
{
    int i;

    i = 0;
    while (i < map->size.y)
    {
        free(map->visited[i]);
        i++;
    }
    free(map->visited);
}