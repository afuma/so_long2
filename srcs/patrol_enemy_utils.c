/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_enemy_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:00:32 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 16:22:56 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void priority_queue_create(t_game *game)
{
    game->map->queue = malloc(sizeof(t_priority_queue));
    if (game->map->queue == NULL)
        ft_error(game, "Memory allocation failed for coord queue enemy !\n");
    game->map->queue->front = NULL;
    game->map->queue->dx[0] = 0;
    game->map->queue->dx[1] = 0;
    game->map->queue->dx[2] = -1;
    game->map->queue->dx[3] = 1;
    game->map->queue->dy[0] = -1;
    game->map->queue->dy[1] = 1;
    game->map->queue->dy[2] = 0;
    game->map->queue->dy[3] = 0;
}

int priority_queue_empty(t_priority_queue *queue)
{
    return (queue->front == NULL);
}

t_node* priority_queue_pop(t_priority_queue* queue)
{
    if (priority_queue_empty(queue))
        return NULL;
    t_priority_node* tmp = queue->front;
    queue->front = queue->front->next;
    t_node* ret = tmp->point;
    free(tmp);

    return (ret);
}

t_node* node_create(int x, int y)
{
    t_node* new_node = malloc(sizeof(t_node));
    if(!new_node)
        return (NULL);
    new_node->x = x;
    new_node->y = y;
    new_node->prev = NULL;
    
    return (new_node);
}

void priority_queue_push(t_priority_queue* queue, t_node* point, int priority)
{
    t_priority_node* node;
    t_priority_node* current;

    node = malloc(sizeof(t_priority_node));
    node->point = point;
    node->priority = priority;
    if (queue->front == NULL || queue->front->priority > priority)
    {
        node->next = queue->front;
        queue->front = node;
    }
    else
    {
        current = queue->front;
        while (current->next != NULL && current->next->priority < priority)
            current = current->next;
        node->next = current->next;
        current->next = node;
    }
}
