/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:08:15 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/27 19:02:21 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void do_sprite(t_game *game, int j, int i, int direction)
// {
//     void *sprite_images[4];
//     int current_sprite = 0;
//     struct timeval now;
//     gettimeofday(&now, NULL);
//     if ((now.tv_sec > last_sprite_change.tv_sec) || 
//         ((now.tv_sec == last_sprite_change.tv_sec) && (now.tv_usec - last_sprite_change.tv_usec >= 500000)))
//     {
//         current_sprite++;
//         if (current_sprite >= 4) {
//             current_sprite = 0;
//         }
//         last_sprite_change = now;
//     }

//     mlx_put_image_to_window(mlx_ptr, win_ptr, sprite_images[current_sprite], sprite_x, sprite_y);
// }

void do_sprite_player_up(t_game *game, int j, int i, int direction)
{
    struct timeb now;
    ftime(&now);

    int diff = (int) (1000.0 * (now.time - last_sprite_change.time)
       + (now.millitm - last_sprite_change.millitm));

    if (diff >= 500) // Change sprite every 500 milliseconds
    {
        last_sprite_change = now;

        // Assuming sprite1, sprite2, and sprite3 are initialized with the correct images
        static int sprite_state = 0;
        if (sprite_state == 0)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player->backfacing_idle.img_mlx, j, i);
            sprite_state++;
        }
        else if (sprite_state == 1)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player->backfacing_walk_1.img_mlx, j, i);
            sprite_state++;
        }
        else // sprite_state == 2
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player->backfacing_walk_2.img_mlx, j, i);
            sprite_state = 0; // Reset to the first sprite
        }
    }
}

void put_image_player_1(t_game *game, int j, int i)
{
    if (game->img_player->code == 1)
    {
        if (game->img_player->nb_pas == 0)
            do_sprite_player_up_1(game, j, i);
        else if (game->img_player->nb_pas == 1)
            do_sprite_player_up_2(game, j, i);
    }
    if (game->img_player->code == 2)
    {
        if (game->img_player->nb_pas == 0)
            do_sprite_player_right_1(game, j, i);
        else if (game->img_player->nb_pas == 1)
            do_sprite_player_right_2(game, j, i);
    }
     
}

void put_image_player_2(t_game *game, int i, int j)
{
    if (game->img_player->code == 3)
    {
        if (game->img_player->nb_pas == 0)
            do_sprite_player_down_1(game, j, i);
        else if (game->img_player->nb_pas == 1)
            do_sprite_player_down_2(game, j, i);
    }
    if (game->img_player->code == 4)
    {
        if (game->img_player->nb_pas == 0)
            do_sprite_player_left_1(game, j, i);
        else if (game->img_player->nb_pas == 1)
            do_sprite_player_left_2(game, j, i);
    }
}