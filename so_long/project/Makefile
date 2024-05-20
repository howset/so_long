##------------------------------------------------------------------##
# Variables.

## Name
NAME-SL				= so_long
NAME-LIBFT			= ./lib/libft.a
NAME-MLX			= ./lib/minilibx-linux/libmlx.a

## Sources & headers & others
SRC-SL				= ./src/so_long.c \
#						./src/algo_radixsort.c \
#						./src/algo_simplesort.c \
#						./src/algo_simplesort_sort3.c \
#						./src/operations_push.c \
#						./src/operations_rotaterev.c \
#						./src/operations_rotate.c \
#						./src/operations_swap.c \
#						./src/utils_check.c \
#						./src/utils_free+print.c \
#						./src/utils_index.c \
#						./src/utils_lists.c

HEADER				= ./src/
MLXDIR				= ./lib/minilibx-linux/

## Compiler, flags, & other commands
CC 					= cc
CFLAGS 				= -g -Wall -Werror -Wextra -I
AR					= ar rcs
RM					= rm -f
MLXFLAGS			= -lmlx -lXext -lX11 -lm

## Text colors
RED					=	\033[1;31m
GREEN				=	\033[1;32m
COLOFF				=	\033[0m

##------------------------------------------------------------------##
# Build rules

all:				$(NAME-MLX) $(NAME-LIBFT) $(NAME-SL)

clean:
					@$(RM) $(NAME-SL)
					@echo "$(RED)So Long's gone, baby, gone!$(COLOFF)"

fclean:				clean
					@make fclean -C ./lib
					@echo "$(RED)Libft's gone, baby, gone!$(COLOFF)"
					@make clean -C ./lib/minilibx-linux
					@echo "$(RED)Minilibx's gone, baby, gone!$(COLOFF)"

re:					fclean all

re-bonus:			fclean bonus

##------------------------------------------------------------------##
# Targets

$(NAME-MLX):
		@make -C ${MLXDIR}
		@echo "$(GREEN)Minilibx-linux ready!$(COLOFF)"

$(NAME-LIBFT):
		@make -C./lib
		@echo "$(GREEN)Libft ready!$(COLOFF)"

$(NAME-SL): ./src/so_long.c $(NAME-LIBFT) $(NAME-MLX)
		@$(CC) $(CFLAGS) $(HEADER) $(SRC-SL) $(NAME-LIBFT) $(NAME-MLX) \
		-L${MLXDIR} $(MLXFLAGS) -o $(NAME-SL)
		@echo "$(GREEN)So Long ready!$(COLOFF)"

##------------------------------------------------------------------##
#.PHONY
.PHONY: clean fclean all re
