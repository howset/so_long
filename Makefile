##------------------------------------------------------------------##
# Variables.

## Preparation, set up MLX
UNAME				= $(shell uname)
MLXGIT				= https://github.com/42Paris/minilibx-linux.git
ifeq ($(UNAME), Darwin)
	MLXTAR		= minilibx_opengl.tgz
	MLXDIR		= ./lib/minilibx_opengl_20191021/ 
#	MLXURL		= "https://cdn.intra.42.fr/document/document/21657/minilibx_opengl.tgz" #wrong
	MLXURL		= "https://cdn.intra.42.fr/document/document/26193/minilibx_opengl.tgz"
	MLXFLAGS 	= -lmlx -framework OpenGL -framework AppKit 
else ifeq ($(UNAME), Linux)
	MLXTAR		= minilibx-linux.tgz
	MLXDIR		= ./lib/minilibx-linux/
#	MLXURL		= "https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz" #wrong
	MLXURL		= "https://cdn.intra.42.fr/document/document/26192/minilibx-linux.tgz"
	MLXFLAGS 	= -lmlx -lXext -lX11 -lm
endif

## Name(s)
NAME-SL				= so_long
NAME-BONUS			= so_long_bonus
NAME-LIBFT			= ./lib/libft.a
NAME-MLX			= $(MLXDIR)libmlx.a

## Sources & headers & others
SRC-SL				= ./src/so_long.c\
						./src/initrun_mlx.c\
						./src/terminate.c\
						./src/render.c\
						./src/map_load.c\
						./src/map_check1.c\
						./src/map_check2.c\
						./src/player.c\
						./src/utilities.c\

SRC-BONUS			= ./bonus/so_long_bonus.c\
						./bonus/initrun_mlx_bonus.c\
						./bonus/terminate_bonus.c\
						./bonus/render_bonus.c\
						./bonus/map_load_bonus.c\
						./bonus/map_check1_bonus.c\
						./bonus/map_check2_bonus.c\
						./bonus/player_bonus.c\
						./bonus/utilities_bonus.c\
						./bonus/animate_bonus.c\
						./bonus/animation_load_bonus.c\

HEADER				= ./src/
HEADERFILES			= ./src/so_long.h
HEADERB				= ./bonus/
HEADERFILESB		= ./bonus/so_long_bonus.h


## Compiler, flags, & other commands
CC 					= cc
CFLAGS 				= -g -Wall -Werror -Wextra -I
#AR					= ar rcs
RM					= rm -f

## Text colors
RED					=	\033[1;31m
GREEN				=	\033[1;32m
YELLOW				=	\033[1;33m
COLOFF				=	\033[0m

##------------------------------------------------------------------##
# Build rules

all:				$(NAME-MLX) $(NAME-LIBFT) $(NAME-SL)

bonus:				$(NAME-MLX) $(NAME-LIBFT) $(NAME-BONUS)

clean:
					@$(RM) $(NAME-SL)
					@$(RM) $(NAME-BONUS)
					@echo "$(RED)So Long's gone, baby, gone!$(COLOFF)"

fclean:				clean
					@make fclean -C ./lib
					@echo "$(RED)Libft's gone, baby, gone!$(COLOFF)"
					@$(RM) ./lib/$(MLXTAR)
					@make clean -C ./lib/minilibx-linux
					@rm -rf $(MLXDIR)
					@echo "$(RED)Minilibx's gone, baby, gone!$(COLOFF)"

re:					fclean all

test:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME-SL)

#re-bonus:			fclean bonus

##------------------------------------------------------------------##
# Targets

$(NAME-MLX):
#		@if [ ! -d "${MLXDIR}" ]; then \
#		echo "$(YELLOW)Cloning minilibx.$(COLOFF)"; \
#		git clone "${MLXGIT}" "${MLXDIR}"; \
#		fi
		@if [ ! -d "${MLXDIR}" ]; then \
		echo "$(YELLOW)Getting minilibx.$(COLOFF)"; \
		curl -0 "${MLXURL}" --output ./lib/"${MLXTAR}"; \
		echo "$(YELLOW)Extracting minilibx.$(COLOFF)"; \
		tar -xzvf ./lib/"${MLXTAR}" -C ./lib/ > /dev/null; \
		fi
		@echo "$(YELLOW)Making minilibx.$(COLOFF)"
		@make -C ${MLXDIR} -s
		@echo "$(GREEN)Minilibx-linux ready!$(COLOFF)"

$(NAME-LIBFT):
		@echo "$(YELLOW)Making libft.$(COLOFF)"
		@make -C./lib
		@echo "$(GREEN)Libft ready!$(COLOFF)"

$(NAME-SL): $(SRC-SL) $(NAME-LIBFT) $(NAME-MLX) $(HEADERFILES)
		@echo "$(YELLOW)Compiling so long.$(COLOFF)"
		@$(CC) $(CFLAGS) $(HEADER) $(SRC-SL) $(NAME-LIBFT) $(NAME-MLX) \
		-L${MLXDIR} $(MLXFLAGS) -o $(NAME-SL)
		@echo "$(GREEN)So Long ready!$(COLOFF)"
		
$(NAME-BONUS): $(SRC-BONUS) $(NAME-LIBFT) $(NAME-MLX) $(HEADERFILESB)
		@echo "$(YELLOW)Compiling so long bonus.$(COLOFF)"
		@$(CC) $(CFLAGS) $(HEADERB) $(SRC-BONUS) $(NAME-LIBFT) $(NAME-MLX) \
		-L${MLXDIR} $(MLXFLAGS) -o $(NAME-BONUS)
		@echo "$(GREEN)So Long ready!$(COLOFF)"

##------------------------------------------------------------------##
#.PHONY
.PHONY: clean fclean all re
