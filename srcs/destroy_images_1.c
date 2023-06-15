/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:44:16 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/26 21:01:42 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void destroy_image(t_game *game, t_img *img)
{
    if (img->mlx_img != NULL)
        mlx_destroy_image(game->mlx_ptr, img->mlx_img);
}

void destroy_images(t_game *game)
{
    destroy_image_collectibles(game);
    destroy_image_ennemi(game);
    destroy_image_exit(game);
    destroy_image_player(game);
    destroy_image_wall(game);
    destroy_image(game, &game->img_ground);
}