/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:13:49 by edesaint          #+#    #+#             */
/*   Updated: 2023/05/23 22:33:19 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_init_game(t_game *game)
{
    game->map = (t_data *) malloc(sizeof(t_data));
    if (!game->map)
        ft_small_error("Memory allocation of the map failed !\n");
    ft_init_map(game);
    game->width = 800;
    game->height = 600;
    init_size(game);
    init_player(game);
    game->mlx_ptr = NULL;
    game->win_ptr = NULL;
    game->map->find = 0;
    game->map->collectibles = 0;
    game->map->max_collectibles = compt_collectibles(game);
    game->map->player.moved = 0;
    printf("INITIALISATION:\n");
    printf("    size.x : %d\n", game->map->size.x);
	printf("    size.y : %d\n", game->map->size.y);
    printf("    player.pos.x : %d\n", game->map->player.pos.x);
    printf("    player.pos.y : %d\n", game->map->player.pos.y);
    printf("    nb_max_collect : %d\n", game->map->max_collectibles);
}

void ft_init_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        free(game->map);
        ft_small_error("Mlx Error init !\n");
    }
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, game->height, "So Long Project");
    if (!game->win_ptr)
    {
        free(game->map);
        ft_small_error("Mlx Error window !\n");
    }
}

void ft_init_map(t_game *game)
{
    char *line;
    char *tmp;
    int fd;

    tmp = NULL;
    fd = open(game->filename, O_RDONLY);
    if (fd < 0 || !ft_check_map_extension(game->filename, ".ber"))
    {
        free(game->map);
        ft_small_error("Can't find the map / verify map '.ber' extension file !\n");
    }
    line = get_next_line(fd);
    while (line)
    {
        tmp = ft_strjoin(tmp, line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    game->map->tab = ft_split(tmp, '\n');
	free(tmp);
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