UNAME := $(shell uname)

NAME = fdf
SRCS_DIR = srcs/
SRC_FILES = main.c hooks.c draw_grid.c fdf_bresenham.c read_map.c \
			init_map.c fdf_exit_prog.c fdf_utils.c color.c \
			bresenham_init_utils.c modify_image.c hooks_utils.c
SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I./includes
HEADER = includes/*
LINUX_MLX = minilibx-linux
LINUX_MLX_SRC = https://github.com/42Paris/minilibx-linux.git
MAC_MLX = minilibx_mms

ifeq ($(UNAME), Linux)
LIBS = ./libraries/libft/libft.a ./libraries/minilibx-linux/libmlx_Linux.a
USR_LIBS = -L/usr/lib -lXext -lm -lX11
all: linux_mlx $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C libraries/libft
	make -C libraries/minilibx-linux
	$(CC) -o $(NAME) $(OBJS) $(LIBS) $(USR_LIBS) $(INCS)

linux_mlx:
	@if [ ! -d libraries/"$(LINUX_MLX)" ]; then \
		git clone $(LINUX_MLX_SRC) libraries/$(LINUX_MLX); \
	fi; \

clean:
	rm -f $(OBJS)
	make clean -C libraries/libft
	make clean -C libraries/$(LINUX_MLX)

else
LIBS = ./libraries/libft/libft.a ./libraries/minilibx_mms/libmlx.a
USR_LIBS = -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C libraries/libft
	make -C libraries/$(MAC_MLX)
	$(CC) -o $(NAME) $(OBJS) $(LIBS) $(USR_LIBS) $(INCS)

clean:
	rm -f $(OBJS)
	make clean -C libraries/libft
	make clean -C libraries/$(MAC_MLX)

endif

fclean: clean
	rm -f $(NAME)
	make fclean -C libraries/libft

re: fclean all

.PHONY: all clean fclean re linux_mlx
