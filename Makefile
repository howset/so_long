##------------------------------------------------------------------##
# Variables.

## Preparation, set up MLX
UNAME				= $(shell uname)
#MLXGIT				= https://github.com/42Paris/minilibx-linux.git
ifeq ($(UNAME), Darwin)
	MLXTAR		= minilibx_opengl.tgz
	MLXDIR		= ./lib/minilibx_opengl_20191021/ 
	MLXURL		= "https://cdn.intra.42.fr/document/document/21657/minilibx_opengl.tgz"
	MLXFLAGS 	= -lmlx -framework OpenGL -framework AppKit 
else ifeq ($(UNAME), Linux)
	MLXTAR		= minilibx-linux.tgz
	MLXDIR		= ./lib/minilibx-linux/
	MLXURL		= "https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz"
	MLXFLAGS 	= -lmlx -lXext -lX11 -lm
endif

## Name(s)
NAME-SL				= so_long
NAME-LIBFT			= ./lib/libft.a
NAME-MLX			= $(MLXDIR)libmlx.a

## Sources & headers & others
SRC-SL				= ./src/so_long.c \
						./src/utils.c \
						./src/keys.c \
						./src/rendering.c \

HEADER				= ./src/

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

#bonus				$(NAME-BONUS) $(NAME-MLX) $(NAME-LIBFT) $(NAME-SL)

clean:
					@$(RM) $(NAME-SL)
					@echo "$(RED)So Long's gone, baby, gone!$(COLOFF)"

fclean:				clean
					@make fclean -C ./lib
					@echo "$(RED)Libft's gone, baby, gone!$(COLOFF)"
					@make clean -C ./lib/minilibx-linux
					@$(RM) ./lib/$(MLXTAR)
					@rm -rf $(MLXDIR)
					@echo "$(RED)Minilibx's gone, baby, gone!$(COLOFF)"

re:					fclean all

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
		tar -xvf ./lib/"${MLXTAR}" -C ./lib/ > /dev/null; \
		fi
		@echo "$(YELLOW)Making minilibx.$(COLOFF)"
		@make -C ${MLXDIR} -s
		@echo "$(GREEN)Minilibx-linux ready!$(COLOFF)"

$(NAME-LIBFT):
		@echo "$(YELLOW)Making libft.$(COLOFF)"
		@make -C./lib
		@echo "$(GREEN)Libft ready!$(COLOFF)"

$(NAME-SL): $(SRC-SL) $(NAME-LIBFT) $(NAME-MLX)
		@echo "$(YELLOW)Compiling so long.$(COLOFF)"
		@$(CC) $(CFLAGS)$(HEADER) $(SRC-SL) $(NAME-LIBFT) $(NAME-MLX) \
		-L${MLXDIR} $(MLXFLAGS) -o $(NAME-SL)
		@echo "$(GREEN)So Long ready!$(COLOFF)"

##------------------------------------------------------------------##
#.PHONY
.PHONY: clean fclean all re
