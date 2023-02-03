#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "minilibx_remote/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
// キーボードの定義
#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
// 画像の定義
#define FLOOR "./img/Floor.xpm"
#define CHARA "./img/human_2.xpm"
#define COIN "./img/coin_floor.xpm"
#define WALL "./img/wall_rock.xpm"
#define ROCK "./img/stop_rock.xpm"
#define EXIT "./img/exit.xpm"
int		main(int argc, char **argv);
void	put_error_exit(char *error_str);
#endif