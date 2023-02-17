#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include "minilibx_remote/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
// キーボードの定義

// #define CLUSTER

#ifdef CLUSTER
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# else
#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
# endif
#define IMG_SIZE 32
// 画像の定義
// #define FLOOR "./img/Floor.xpm"
// #define CHARA "./img/human_2.xpm"
// #define COIN "./img/coin_floor.xpm"
// #define WALL "./img/wall_rock.xpm"
// #define ROCK "./img/stop_rock.xpm"
// #define EXIT "./img/exit.xpm"

typedef struct s_map
{
	char 			*line;
	struct	s_map	*next;
	struct	s_map	*pre;
}	t_map;

typedef struct s_info
{
	struct s_map *map;
	int	height;
	int	width;
	int	zero_num;
	int	one_num;
	int	c_num;
	int	e_num;
	int	p_num;
	int	start_x;
	int	start_y;
	void *win;
	void *mlx;
	void *coin;
	void *exit;
	void *floor;
	void *human;
	void *block;
}	t_info;

int			main(int argc, char **argv);
void		put_error_exit(char *error_str);
void		check_error_map(char *map_name, t_map **map,t_info *info);
void		get_map(char *map_name,t_map **map, t_info *info);
int			key_press(int keycode, t_info *info);

#endif
