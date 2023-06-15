/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:44:18 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/28 18:09:05 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void destroy_image_collectibles(t_game *game)
{
    destroy_image(game, &game->img_collect.collect_1);
    destroy_image(game, &game->img_collect.collect_2);
    destroy_image(game, &game->img_collect.collect_3);
}

void destroy_image_ennemi(t_game *game)
{
    destroy_image(game, &game->img_ennemi.ennemi_1);
    destroy_image(game, &game->img_ennemi.ennemi_2);
    destroy_image(game, &game->img_ennemi.ennemi_3);
    destroy_image(game, &game->img_ennemi.ennemi_4);
}

void destroy_image_exit(t_game *game)
{
    destroy_image(game, &game->img_exit.exit_1);
    destroy_image(game, &game->img_exit.exit_2);
    destroy_image(game, &game->img_exit.exit_3);
    destroy_image(game, &game->img_exit.exit_4);
}

void destroy_image_player(t_game *game)
{
    destroy_image(game, &game->img_player.backfacing[0]);
    destroy_image(game, &game->img_player.backfacing[1]);
    destroy_image(game, &game->img_player.backfacing[2]);
    destroy_image(game, &game->img_player.rightfacing[0]);
    destroy_image(game, &game->img_player.rightfacing[1]);
    destroy_image(game, &game->img_player.rightfacing[2]);
    destroy_image(game, &game->img_player.frontfacing[0]);
    destroy_image(game, &game->img_player.frontfacing[1]);
    destroy_image(game, &game->img_player.frontfacing[2]);
    destroy_image(game, &game->img_player.leftfacing[0]);
    destroy_image(game, &game->img_player.leftfacing[1]);
    destroy_image(game, &game->img_player.leftfacing[2]);
}

void destroy_image_wall(t_game *game)
{
    destroy_image(game, &game->img_wall.wall_1);
    destroy_image(game, &game->img_wall.wall_2);
    destroy_image(game, &game->img_wall.wall_3);
}
