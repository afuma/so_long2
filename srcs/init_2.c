/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:08:40 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/28 23:11:14 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_offset_img_player(t_game *game)
{
    game->img_player.backfacing[0].offset.x = 0;
    game->img_player.backfacing[0].offset.y = 50;
    game->img_player.backfacing[1].offset.x = 0;
    game->img_player.backfacing[1].offset.y = 25;
    game->img_player.backfacing[2].offset.x = 0;
    game->img_player.backfacing[2].offset.y = 0;
    game->img_player.rightfacing[0].offset.x = -50;
    game->img_player.rightfacing[0].offset.y = 0;
    game->img_player.rightfacing[1].offset.x = -25;
    game->img_player.rightfacing[1].offset.y = 0;
    game->img_player.rightfacing[2].offset.x = 0;
    game->img_player.rightfacing[2].offset.y = 0;
    game->img_player.frontfacing[0].offset.x = 0;
    game->img_player.frontfacing[0].offset.y = -50;
    game->img_player.frontfacing[1].offset.x = 0;
    game->img_player.frontfacing[1].offset.y = -25;
    game->img_player.frontfacing[2].offset.x = 0;
    game->img_player.frontfacing[2].offset.y = 0;
    game->img_player.leftfacing[0].offset.x = 50;
    game->img_player.leftfacing[0].offset.y = 0;
    game->img_player.leftfacing[1].offset.x = 25;
    game->img_player.leftfacing[1].offset.y = 0;
    game->img_player.leftfacing[2].offset.x = 0;
    game->img_player.leftfacing[2].offset.y = 0;
}

void ft_init_var_map(t_game *game)
{
    game->map->find = 0;
    game->map->collectibles = 0;
    game->map->max_collectibles = compt_collectibles(game);
    game->map->player.moved = 0;
    game->map->player.moves = 0;
    game->map->player.velocity = 70000;
}