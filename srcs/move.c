/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:33:33 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/27 19:19:37 by edesaint         ###   ########.fr       */
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
	// printf("pos.x : %d\n", game->map->player.pos.x);
	// printf("pos.y : %d\n", game->map->player.pos.y);
	// printf("nb_collect : %d\n", game->map->collectibles);
	// printf("offset_x : %d\n", offset_x);
	// printf("offset_y : %d\n", offset_y);
    if(i <= 0 || j <= 0 || i >= game->map->size.y - 1 || j >= game->map->size.x - 1)
        return;
    if (game->map->tab[i][j] == '1')
        return;
    if (game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'C')
	{
		// printf("c'est incroyable d'arriver la !\n");
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
	if (game->img_player->direction != -1)
	{
		if (game->img_player->direction == direction)
			game->img_player->nb_pas += 1;
	}
	if (direction == UP)
	{
		game->img_player->code = 1;
		ft_move_player(game, 0, -1);
	}
	if (direction == RIGHT)
	{
		game->img_player->code = 2;
		ft_move_player(game, 1, 0);
	}
	if (direction == DOWN)
	{
		game->img_player->code = 3;
		ft_move_player(game, 0, 1);
	}
	if (direction == LEFT)
	{
		game->img_player->code = 4;
		ft_move_player(game, -1, 0);
	}
	game->map->player.moved = 1;
	game->map->player.moves += 1;
}

int	handle_keypress(int keycode, t_game *game)
{
	static int ctrl_pressed = 0;
	
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
        ctrl_pressed = 1;
    else if (keycode == XK_c && ctrl_pressed)
    {
        free_all(game);
        write(1, "You have just left the game with Ctrl + C!\n", 42);
        exit(EXIT_SUCCESS);
    }
    else
        ctrl_pressed = 0;
    
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