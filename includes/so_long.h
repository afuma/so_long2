/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:13:47 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 16:41:32 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/time.h>

# include "mlx_header.h"
# include "../libft/libft.h"
# include "get_next_line.h"

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

// void print_map(t_data *map);

// check_path_1.c
void check_path_image(t_game *game, char *path);
void check_path_images(t_game *game);

// check_path_2.c
void check_path_image_collectibles(t_game *game);
void check_path_image_ennemi(t_game *game);
void check_path_image_exit(t_game *game);
void check_path_image_player(t_game *game);
void check_path_image_wall(t_game *game);

// charge_images_1.c
void charge_image(t_game *game, t_img *img, char *path);
void charge_images(t_game *game);

// charge_images_2.c
void charge_image_collectibles(t_game *game);
void charge_image_ennemi(t_game *game);
void charge_image_exit(t_game *game);
void charge_image_player(t_game *game);
void charge_image_wall(t_game *game);

// put_image_1.c
void update_sprite(t_game *game, int j, int i, t_img img[3]);
void put_image_player_1(t_game *game, int j, int i);
void put_image_player_2(t_game *game, int i, int j);

// destroy_images_1.c
void destroy_image(t_game *game, t_img *img);
void destroy_images(t_game *game);

// destroy_images_2.c
void destroy_image_collectibles(t_game *game);
void destroy_image_ennemi(t_game *game);
void destroy_image_exit(t_game *game);
void destroy_image_player(t_game *game);
void destroy_image_wall(t_game *game);

//patrol_ennemy
void visited_and_push(t_game *game, t_node *current, int k);
void a_star(t_game *game, int k);
void init_enemy(t_game *game);
void update_enemy(t_game *game);

//patrol_ennemy_utils2.c
int is_valid(t_data *map, int x, int y);
int heuristic(t_node *a, t_node *b);
void init_visited(t_data *map);
void free_visited(t_data *map);

//patrol_ennemy_utils.c
// void print_path(t_node* current);
// void print_queue(t_priority_queue* queue, t_node* end);
void priority_queue_create(t_game *game);
int priority_queue_empty(t_priority_queue *queue);
t_node* priority_queue_pop(t_priority_queue* queue);
t_node* node_create(int x, int y);
void priority_queue_push(t_priority_queue* queue, t_node* point, int priority);

// move_enemy.c
void next_move_enemy(t_game *game, t_node *current, int k);
void enemy_on_player(t_game *game, t_node *current);
void enemy_pass_on_object(t_game *game, int init_i, int init_j, int k);
void enemy_path(t_game *game, t_node *current, int k);

// render.c
void put_image(t_game *game, t_img *img, int j, int i);
int	put_string_moves(t_game *game);
int draw_map(t_game *game);
void draw_image(t_game *game, int i, int j, char letter);

// free.c
int ft_small_error(char *msg);
int ft_error_map(t_game *game, char *msg);
int ft_error(t_game *game, char *msg);
void free_map(t_data **map);
void free_images(t_game *game);
void free_all(t_game *game);

// move.c
void ft_move_player(t_game *game, int direction, int offset_x, int offset_y);
void ft_move(t_game *game, int direction);
void update_player_code(t_game *game, int direction);
int	handle_keypress(int keycode, t_game *game);

// init_1.c
void ft_init_game(t_game *game);
void ft_init_mlx(t_game *game);
void ft_init_map(t_game *game);
int	ft_check_map_extension(char *str, char *ext);

// init_2.c
void init_offset_img_player(t_game *game);
void ft_init_var_map(t_game *game);

// (PARSING) FONCTIONS DE VALIDATION DE LA MAP
// ft_valid_map.c
int is_valid_elems(t_data *map);
int is_exist_elem(t_data *map, char letter);
int is_map_rectangle(t_data *map);
int is_map_duplicates(t_data *map, char letter);
int is_map_close(t_data *map, char letter);

// ft_utils.c
void init_size(t_game *game);
int compt_elems(t_game *game, char letter);
void init_player(t_game *game);
void init_enemies(t_game *game);
void print_enemies(t_game *game);

// valid_path.c
void cpy_map(t_data *map, t_data *tmp_map);
int is_exitable(t_game *game);
void f_efill(t_data *map, int row, int col);
int is_collectables(t_game *game);
void f_cfill(t_data *map, int row, int col);
int is_mechable(t_game *game);
void f_mfill(t_data *map, int row, int col);

// utils_2.c
char **make_area(char **zone, int _x, int _y);
void verif_map(t_game *game);

#endif
