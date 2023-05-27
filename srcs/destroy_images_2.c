/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:44:18 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/26 14:22:40 by edesaint         ###   ########.fr       */
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

void destroy_images_player(t_game *game)
{
    destroy_image(game, &game->img_player.backfacing_idle);
    destroy_image(game, &game->img_player.backfacing_walk_1);
    destroy_image(game, &game->img_player.backfacing_walk_2);
    destroy_image(game, &game->img_player.frontfacing_idle);
    destroy_image(game, &game->img_player.frontfacing_walk_1);
    destroy_image(game, &game->img_player.frontfacing_walk_2);
    destroy_image(game, &game->img_player.leftfacing_idle);
    destroy_image(game, &game->img_player.leftfacing_walk_1);
    destroy_image(game, &game->img_player.leftfacing_walk_2);
    destroy_image(game, &game->img_player.rightfacing_idle);
    destroy_image(game, &game->img_player.rightfacing_walk_1);
    destroy_image(game, &game->img_player.rightfacing_walk_2);
}

void destroy_image_wall(t_game *game)
{
    destroy_image(game, &game->img_wall.wall_1);
    destroy_image(game, &game->img_wall.wall_2);
    destroy_image(game, &game->img_wall.wall_3);
}
