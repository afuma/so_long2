/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:41:48 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/26 14:17:56 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_path_image_collectibles(t_game *game)
{
    check_path_image(game, COLLECT_1);
    check_path_image(game, COLLECT_2);
    check_path_image(game, COLLECT_3);
}

void check_path_image_ennemi(t_game *game)
{
    check_path_image(game, ENNEMI_1);
    check_path_image(game, ENNEMI_2);
    check_path_image(game, ENNEMI_3);
    check_path_image(game, ENNEMI_4);
}

void check_path_image_exit(t_game *game)
{
    check_path_image(game, EXIT_1);
    check_path_image(game, EXIT_2);
    check_path_image(game, EXIT_3);
    check_path_image(game, EXIT_4);
}

void check_path_image_player(t_game *game)
{
    check_path_image(game, PLAYER_BACKFACING_IDLE);
    check_path_image(game, PLAYER_BACKFACING_WALK_1);
    check_path_image(game, PLAYER_BACKFACING_WALK_2);
    check_path_image(game, PLAYER_FRONTFACING_IDLE);
    check_path_image(game, PLAYER_FRONTFACING_WALK_1);
    check_path_image(game, PLAYER_FRONTFACING_WALK_2);
    check_path_image(game, PLAYER_LEFTFACING_IDLE);
    check_path_image(game, PLAYER_LEFTFACING_WALK_1);
    check_path_image(game, PLAYER_LEFTFACING_WALK_2);
    check_path_image(game, PLAYER_RIGHTFACING_IDLE);
    check_path_image(game, PLAYER_RIGHTFACING_WALK_1);
    check_path_image(game, PLAYER_RIGHTFACING_WALK_2);
}

void check_path_image_wall(t_game *game)
{
    check_path_image(game, WALL_1);
    check_path_image(game, WALL_2);
    check_path_image(game, WALL_3);
}