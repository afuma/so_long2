/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:47:58 by blax              #+#    #+#             */
/*   Updated: 2023/06/15 15:10:17 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HEADER_H
# define MLX_HEADER_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx_linux/mlx.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

#define PLAYER_BACKFACING_IDLE "graphics/all_xpm/character/backfacing_hero/idle.xpm"
#define PLAYER_BACKFACING_WALK_1 "graphics/all_xpm/character/backfacing_hero/walk_1.xpm"
#define PLAYER_BACKFACING_WALK_2 "graphics/all_xpm/character/backfacing_hero/walk_2.xpm"
#define PLAYER_FRONTFACING_IDLE "graphics/all_xpm/character/frontfacing_hero/idle.xpm"
#define PLAYER_FRONTFACING_WALK_1 "graphics/all_xpm/character/frontfacing_hero/walk_1.xpm"
#define PLAYER_FRONTFACING_WALK_2 "graphics/all_xpm/character/frontfacing_hero/walk_2.xpm"
#define PLAYER_LEFTFACING_IDLE "graphics/all_xpm/character/leftfacing_hero/idle.xpm"
#define PLAYER_LEFTFACING_WALK_1 "graphics/all_xpm/character/leftfacing_hero/walk_1.xpm"
#define PLAYER_LEFTFACING_WALK_2 "graphics/all_xpm/character/leftfacing_hero/walk_2.xpm"
#define PLAYER_RIGHTFACING_IDLE "graphics/all_xpm/character/rightfacing_hero/idle.xpm"
#define PLAYER_RIGHTFACING_WALK_1 "graphics/all_xpm/character/rightfacing_hero/walk_1.xpm"
#define PLAYER_RIGHTFACING_WALK_2 "graphics/all_xpm/character/rightfacing_hero/walk_2.xpm"

#define COLLECT_1 "graphics/all_xpm/collectibles/bottle_1.xpm"
#define COLLECT_2 "graphics/all_xpm/collectibles/bottle_2.xpm"
#define COLLECT_3 "graphics/all_xpm/collectibles/bottle_3.xpm"

#define EXIT_1 "graphics/all_xpm/door/cauldron_closed.xpm"
#define EXIT_2 "graphics/all_xpm/door/cauldron_open_basic.xpm"
#define EXIT_3 "graphics/all_xpm/door/cauldron_open_stars_and_arrows.xpm"
#define EXIT_4 "graphics/all_xpm/door/cauldron_open_stars.xpm"

#define ENNEMI_1 "graphics/all_xpm/enemy/aggro_xpm_assets/sand_ghost_leftfacing_aggro_01.xpm"
#define ENNEMI_2 "graphics/all_xpm/enemy/aggro_xpm_assets/sand_ghost_leftfacing_aggro_02.xpm"
#define ENNEMI_3 "graphics/all_xpm/enemy/aggro_xpm_assets/sand_ghost_rightfacing_aggro_01.xpm"
#define ENNEMI_4 "graphics/all_xpm/enemy/aggro_xpm_assets/sand_ghost_rightfacing_aggro_02.xpm"

#define WALL_1 "graphics/all_xpm/wall/obstacles/sand_big_trap.xpm"
#define WALL_2 "graphics/all_xpm/wall/obstacles/sand_obstacle_tree.xpm"
#define WALL_3 "graphics/all_xpm/wall/obstacles/sand_small_trap.xpm"

#define GROUND "graphics/all_xpm/ground/sand_tile.xpm"

// #define True 1
// #define False 0

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_point{
	int x;
	int y;
} t_point;

typedef struct s_node
{
    int x;
    int y;
    struct s_node *prev;
} t_node;

typedef struct s_priority_node
{
    int priority;
    t_node* point;
    struct s_priority_node* next;
} t_priority_node;

typedef struct s_priority_queue
{
    t_priority_node* front;
	int dx[4];
	int dy[4];
} t_priority_queue;

typedef struct s_player
{
	int moved;
	int moves;
	int speed;
	int on_exit;
	t_point pos;
} t_player;

typedef struct s_enemy
{
	int moved;
	int moves;
	int speed;
	int on_exit;
	int on_collectible;
	t_node start;
	t_node end;
	t_point pos[2];
} t_enemy;

typedef struct s_data
{
	char **tab;
	int **visited;
	t_priority_queue *queue;
	int max_collectibles;
	int collectibles;
	int nb_enemy;
	int max_enemy;
	int find;
	t_point size;
	t_player player;
	t_enemy enemy[3];
} t_data;

typedef struct s_img
{
	void	*mlx_img;
	t_point offset;
}	t_img;

typedef struct s_img_collect
{
	int code;
	t_img collect_1;
	t_img collect_2;
	t_img collect_3;
	
}	t_img_collect;


typedef struct s_img_ennemi
{
	int code;
	t_img ennemi_1;
	t_img ennemi_2;
	t_img ennemi_3;
	t_img ennemi_4;
	
}	t_img_ennemi;

typedef struct s_img_exit
{
	int code;
	t_img exit_1;
	t_img exit_2;
	t_img exit_3;
	t_img exit_4;
	
}	t_img_exit;

typedef struct s_img_player
{
	int code;
	int nb_pas;
	int direction;
	t_img backfacing[3];
	t_img frontfacing[3];
	t_img rightfacing[3];
	t_img leftfacing[3];
	
}	t_img_player;

typedef struct s_img_wall
{
	int code;
	t_img wall_1;
	t_img wall_2;
	t_img wall_3;
	
}	t_img_wall;

typedef struct s_game{
    void *mlx_ptr;
    void *win_ptr;
	char *filename;
	int width;
    int height;
	int ctrl_pressed;
	// struct timespec wait;
	struct timeval now;
	struct timeval last_sprite_change;
	int current_sprite;
	t_point img_ppixel;
	t_data *map;
    t_img_collect img_collect;
	t_img_ennemi img_ennemi;
	t_img_exit img_exit;
	t_img_player img_player;
    t_img_wall img_wall;
	t_img img_ground;
    
} t_game;

#endif
