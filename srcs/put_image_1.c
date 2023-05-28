/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:08:15 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/28 23:11:54 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void update_sprite(t_game *game, int j, int i, t_img img[3])
{
    gettimeofday(&game->now, NULL);

    if ((game->now.tv_sec > game->last_sprite_change.tv_sec) || 
        ((game->now.tv_sec == game->last_sprite_change.tv_sec) && 
        (game->now.tv_usec - game->last_sprite_change.tv_usec >= game->map->player.velocity)))
    {
        game->current_sprite++;
        if (game->current_sprite >= 3)
        {
            game->current_sprite = 0;
            game->map->player.moved = 0;
            return ;
        }
        game->last_sprite_change = game->now;
        put_image(game, &game->img_ground,
            j + img[game->current_sprite - 1].offset.x,
            i + img[game->current_sprite - 1].offset.y);
        put_image(game, &img[game->current_sprite],
            j + img[game->current_sprite].offset.x,
            i + img[game->current_sprite].offset.y);
        // mlx_do_sync(game->mlx_ptr);
    }
}

void put_image_player_1(t_game *game, int j, int i)
{
    if (game->img_player.code == 1)
    {
        if (game->map->player.moved == 1)
            update_sprite(game, j, i, game->img_player.backfacing);
    }
    if (game->img_player.code == 2)
    {
        if (game->map->player.moved == 1)
            update_sprite(game, j, i, game->img_player.rightfacing);
    }
}

void put_image_player_2(t_game *game, int j, int i)
{
    if (game->img_player.code == 3)
    {
        if (game->map->player.moved == 1)
            update_sprite(game, j, i, game->img_player.frontfacing);
    }
    if (game->img_player.code == 4)
    {
        if (game->map->player.moved == 1)
            update_sprite(game, j, i, game->img_player.leftfacing);
    }
}