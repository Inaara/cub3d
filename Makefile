NAME  = cub3D

SRCS  =  srcs/main.c srcs/vector.c srcs/math.c \
	srcs/raycasting_computations.c srcs/dda.c \
	srcs/colors.c srcs/parsing.c srcs/error.c \
	srcs/checker_0.c srcs/check_map.c \
	srcs/check_map_2.c srcs/create_map.c \
	srcs/check_textures.c srcs/parse_file.c \
	srcs/init_world.c srcs/init_raycast.c \
	srcs/vector1.c srcs/movements.c srcs/free.c \
	srcs/exit.c srcs/map.c srcs/textures.c \
	srcs/raycast_texture.c srcs/utils.c \
	srcs/check_map_3.c srcs/create_map_1.c

OBJS  = ${SRCS:.c=.o}

HEADERS= includes/cub3d.h

CC= clang

CFLAGS= -Wall -Wextra -Werror -g 

LIBFT= -L libft -lft

VALGRIND = colour-valgrind 

MLX            = mlx/libmlx.a mlx/libmlx_Linux.a 

all: 		lib ${NAME} 

${NAME}: 	${OBJS}
				${CC} ${CFLAGS} -L /usr/lib ${OBJS} ${LIBFT} ${MLX} -lXext -lX11 -lm -lz -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I/usr/include -I${HEADERS} -Imlx -O3 -c $< -o $@

lib:
				make -C libft
				make -C mlx

clean:
				rm -f ${OBJS} 
							make -C libft clean
							make -C mlx clean

fclean:clean
				rm -f ${NAME}
							make -C libft fclean
							make -C mlx clean

re:fclean all

norm:
				norminette -R CheckSourceHeader ${SRCS}

.PHONY :all clean fclean re norm 
