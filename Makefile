NAME = so_long
SRCS = so_long.c \
       put_error_exit.c \
	   check_error_map.c \
	   get_map.c

MAKE = make

LIB_LIB = ./libft/libft.a

LIB_DIR = ./libft

MLX_LIB = ./minilibx_remote/libmlx.a

MLX_DIR = ./minilibx_remote

GNL = ./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c

OPT = -L/usr/X11R6/lib  -Imlx -lX11 -lXext -framework OpenGL -framework AppKit 

HEADER = so_long.h

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(GNL) $(LIB_LIB) $(OPT) -o $(NAME)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C $(MLX_DIR) 
	$(MAKE) clean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)
	rm -f $(LIB_LIB)

re : fclean all

.PHONY : all clean fclean re