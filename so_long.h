/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noshiro <noshiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:31:56 by noshiro           #+#    #+#             */
/*   Updated: 2023/03/01 21:36:44 by noshiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define CLUSTER

# ifndef CLUSTER
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
# endif
# define IMG_SIZE 32

typedef struct s_map
{
	char				*line;
	struct s_map		*next;
	struct s_map		*pre;
}	t_map;

typedef struct s_info
{
	struct s_map	*map;
	int				count;
	int				get_c;
	int				height;
	int				width;
	int				zero_num;
	int				one_num;
	int				c_num;
	int				e_num;
	int				p_num;
	int				start_x;
	int				start_y;
	void			*win;
	void			*mlx;
	void			*coin;
	void			*exit;
	void			*floor;
	void			*human;
	void			*block;
}	t_info;

int			main(int argc, char **argv);
void		put_error_exit(char *error_str);
void		check_error_map(char *map_name, t_map **map, t_info *info);
void		get_map(char *map_name, t_map **map, t_info *info);
int			key_press(int keycode, t_info *info);
int			destroy_win(t_info *info);
void		dfs(char *map_dfs, int x, int y, t_info *info);
void		check_component(t_map *map, t_info *info);
int			first_print_image(t_info *info);
void		get_map_info(t_info *info);
void		put_initial(t_info *info);
void		check_width(t_map *map, t_info *info);
void		check_extention(char *map_name);
#endif
