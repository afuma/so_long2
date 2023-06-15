/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/06/15 16:43:29 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_move_player(t_game *game, int direction, int offset_x, int offset_y)
{
	int i;
	int j;

	i = game->map->player.pos.y + offset_y;
	j = game->map->player.pos.x + offset_x;
    if(i <= 0 || j <= 0 || i >= game->map->size.y - 1 || j >= game->map->size.x - 1)
        return;
    if (game->map->tab[i][j] == '1')
        return;
    if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C')
	{
		if (game->map->tab[i][j] == 'C')
			game->map->collectibles++;
		if (game->map->player.on_exit == 1)
		{
			game->map->tab[i - offset_y][j - offset_x] = 'E';
			game->map->player.on_exit = 0;
		}
		else
			game->map->tab[i - offset_y][j - offset_x] = '0';
		game->map->tab[i][j] = 'P';
		game->map->player.pos.x = j;
		game->map->player.pos.y = i;
		game->map->player.moved = 1;
		game->current_sprite = 0;
		update_player_code(game, direction);
		update_enemy(game);
	}
	if (game->map->tab[i][j] == 'E' &&
        game->map->collectibles != game->map->max_collectibles)
    {
        game->map->tab[i][j] = 'P';
		game->map->tab[i - offset_y][j - offset_x] = '0';
		game->map->player.pos.x = j;
		game->map->player.pos.y = i;
		game->map->player.moved = 1;
		game->map->player.on_exit = 1;
		game->current_sprite = 0;
		update_player_code(game, direction);
		update_enemy(game);
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
	// printf("-----------------------------\n");
    // print_map(game->map);
}

void update_player_code(t_game *game, int direction)
{
	if (direction == UP)
		game->img_player.code = 1;
	if (direction == RIGHT)
		game->img_player.code = 2;
	if (direction == DOWN)
		game->img_player.code = 3;
	if (direction == LEFT)
		game->img_player.code = 4;
}

void ft_move(t_game *game, int direction)
{
	if (direction == UP)
		ft_move_player(game, UP, 0, -1);
	if (direction == RIGHT)
		ft_move_player(game, RIGHT, 1, 0);
	if (direction == DOWN)
		ft_move_player(game, DOWN, 0, 1);
	if (direction == LEFT)
		ft_move_player(game, LEFT, -1, 0);
	game->map->player.moves += 1;
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_a || keycode == XK_Left)
		ft_move(game, LEFT);
	if (keycode == XK_d || keycode == XK_Right)
		ft_move(game, RIGHT);
	if (keycode == XK_w || keycode == XK_Up)
		ft_move(game, UP);
	if (keycode == XK_s || keycode == XK_Down)
		ft_move(game, DOWN);
	if (keycode == XK_Escape)
	{
        free_all(game);
		write(1, "You have just left the game !\n", 31);
        exit (EXIT_SUCCESS);
	}
    if (keycode == XK_Control_L || keycode == XK_Control_R)
        game->ctrl_pressed = 1;
    else if (keycode == XK_c && game->ctrl_pressed)
    {
        free_all(game);
        write(1, "You have just left the game with Ctrl + C !\n", 44);
        exit(EXIT_SUCCESS);
    }
    else
        game->ctrl_pressed = 0;
    
    return (0);
}