/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:49:01 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 15:08:22 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int compt_elems(t_game *game, char letter)
{
    int i;
    int j;
    int cpt;

    i = 0;
    j = 0;
    cpt = 0;
    while (i < game->map->size.y)
    {
        while (j < game->map->size.x)
        {
            if (game->map->tab[i][j] == letter)
                cpt++;
            j++;
        }
        i++;
        j = 0;
    }
    return (cpt);
}

void init_size(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (game->map->tab[i][j])
        j++;
    while (game->map->tab[i])
        i++;
    game->map->size.y = i;
    game->map->size.x = j;
}

void init_player(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < game->map->size.y)
    {
        while (j < game->map->size.x)
        {
            if (game->map->tab[i][j] == 'P')
            {
                game->map->player.pos.y = i;
                game->map->player.pos.x = j;
                return;
            }
            j++;
        }
        i++;
        j = 0;
    }
}

void init_enemies(t_game *game)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (i < game->map->size.y)
    {
        while (j < game->map->size.x)
        {
            if (game->map->tab[i][j] == 'M')
            {
                game->map->enemy[k].start.y = i;
                game->map->enemy[k].start.x = j;
                k++;
            }
            j++;
        }
        i++;
        j = 0;
    }
    if (k >= 10)
        ft_error_map(game, "Too much ennemies detected in the map (>10 M) !\n");
}

int	ft_check_map_extension(char *str, char *ext)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 4;
	j = 0;
	while (str[i] && ext[j] && str[i] == ext[j])
	{
		i++;
		j++;
	}
    if (j == 4)
        return (1);
    return (0);
}