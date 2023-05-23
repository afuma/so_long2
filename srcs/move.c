/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/23 22:26:07 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_move_player(t_game *game, int offset_x, int offset_y)
{
	int i;
	int j;
	// printf("je suis dans move_player !\n");
	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
	printf("pos.x : %d\n", game->map->player.pos.x);
	printf("pos.y : %d\n", game->map->player.pos.y);
	printf("nb_collect : %d\n", game->map->collectibles);
	// printf("offset_x : %d\n", offset_x);
	// printf("offset_y : %d\n", offset_y);
    if(i <= 0 || j <= 0 || i >= game->map->size.y - 1 || j >= game->map->size.x - 1)
        return;
    if (game->map->tab[i][j] == '1')
        return;
    if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C')
	{
		printf("c'est incroyable d'arriver la !\n");
		if (game->map->tab[i][j] == 'C')
			game->map->collectibles++;
		game->map->tab[i][j] = 'P';
		game->map->tab[i - offset_y][j - offset_x] = '0';
		game->map->player.pos.x = j;
		game->map->player.pos.y = i;
	}
    if (game->map->tab[i][j] == 'M')
    {
        free_all(game);
        write(1, "you lose.. !\n", 14);
        exit (EXIT_SUCCESS);
    }
    if (game->map->tab[i][j] == 'E' &&
        game->map->collectibles == game->map->max_collectibles)
    {
        free_all(game);
        write(1, "SUCCESS !\n", 11);
        exit (EXIT_SUCCESS);
	}
    print_map(game->map);
}

void ft_move(t_game *game, int direction)
{
	if (direction == UP)
		ft_move_player(game, 0, -1);
	if (direction == RIGHT)
		ft_move_player(game, 1, 0);
	if (direction == DOWN)
		ft_move_player(game, 0, 1);
	if (direction == LEFT)
		ft_move_player(game, -1, 0);
	game->map->player.moved = 1;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_a)
		ft_move(game, LEFT);
	if (keycode == XK_d)
		ft_move(game, RIGHT);
	if (keycode == XK_w)
		ft_move(game, UP);
	if (keycode == XK_s)
		ft_move(game, DOWN);
	if (keycode == XK_Escape)
	{
        free_all(game);
		write(1, "You have just left the game !\n", 31);
        exit (EXIT_SUCCESS);
	}
    return (0);
}

int loop_hook(t_game *game)
{
    if (game->map->player.moved == 1)
    {
        draw_map(game);
        game->map->player.moved = 0;
    }
    return (0);
}