# ---------------------------------- COLORS ---------------------------------- #
DEF		:= \033[0m
BOLD	:= \033[1m
CUR		:= \033[3m
UL		:= \033[4m
UP		:= \033[A

ORANGE	:= \033[38;5;216m
LBLUE	:= \033[38;5;153m
LYELLOW	:= \033[38;5;222m
BEIGE	:= \033[38;5;223m
LGREEN	:= \033[38;5;155m

PROMPT	:= ${BOLD}${ORANGE}[$(shell date +'%H:%M:%S')]${DEF}:${BOLD}${CUR}${BEIGE}

# --------------------------------- SOURCES ---------------------------------- #
HEADER_DIR	:= ./inc
DEPS		:= ${addprefix ${HEADER_DIR}/,	game.h \
											hooks.h \
											parsing.h \
											render.h \
											textures.h}

SRC_DIR	:= ./src
SRC		:=	${addprefix ${SRC_DIR}/,	main.c} \
			${addprefix ${SRC_DIR}/animation/,	update.c \
												move_enemy.c \
												move_player.c \
												animation.c} \
			${addprefix ${SRC_DIR}/game/,	game_init.c \
											hooks.c \
											game_check.c} \
			${addprefix ${SRC_DIR}/parsing/,	check_map.c \
												flood_fill.c \
												map_init.c \
												mob_init.c} \
			${addprefix ${SRC_DIR}/texture/,	assign_textures.c \
												clear_textures.c \
												utils_textures.c} \
			${addprefix ${SRC_DIR}/render/,	render.c \
											image_buffer.c \
											render_map.c}

# --------------------------------- OBJECTS ---------------------------------- #
OBJS	:= ${SRC:.c=.o}

# --------------------------------- COMPILER --------------------------------- #
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
UTILS	:= -lm -Llib -lft

LIBFT_DIR		:= ./lib/libft
LIBFT_INC_DIR	:= ${LIBFT_DIR}/inc
ifeq (${shell uname}, Linux)
	MLX_FLAGS	:= -lmlx -lXext -lX11
	LIBMLX_PATH	:= ./lib/libmlx/linux
else
	MLX_FLAGS	:= -lmlx -framework OpenGL -framework AppKit
	LIBMLX_PATH	:= ./lib/libmlx/macos
endif

SRC_COUNT	= 0
SRC_TOT		:= ${shell find ./src/ -type f -name '*.c' | wc -l}
SRC_PRCT	= ${shell expr 100 \* ${SRC_COUNT} / ${SRC_TOT}}
BAR			= ${shell expr 23 \* ${SRC_COUNT} / ${SRC_TOT}}

${SRC_DIR}/%.o:	${SRC_DIR}/%.c ${DEPS}
	@${eval SRC_COUNT = ${shell expr ${SRC_COUNT} + 1}}
	@${CC} ${CFLAGS} -I${HEADER_DIR}/ -I${LIBMLX_PATH}/ -I${LIBFT_INC_DIR}/ -c $< -o $@
	@printf "${PROMPT} Compiling${DEF}\n"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [${SRC_COUNT}/${SRC_TOT} (${SRC_PRCT}%%)]${DEF}" "***********************"
	@printf "${UP}${UP}\n"

# ---------------------------------- RULES ----------------------------------- #
NAME	:= so_long
RM		:= rm -f

all:	libft mlx ${NAME}

${NAME}: ${OBJS}
	@printf "${PROMPT} Linking ${NAME}${DEF}\n"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [${SRC_COUNT}/${SRC_TOT} (${SRC_PRCT}%%)]${DEF}\n" "***********************"
	@${CC} ${FLAGS} ${OBJS} ${UTILS} -L${LIBMLX_PATH} ${MLX_FLAGS} -o $@

libft:
	@${MAKE} -C ${LIBFT_DIR}

mlx:
	@${MAKE} -C ${LIBMLX_PATH}

clean:
	@${MAKE} -C ${LIBFT_DIR} clean
	@${MAKE} -C ${LIBMLX_PATH} clean
	@${RM} ${OBJS}
	@printf "${PROMPT} ${LBLUE} - Deleted object files${DEF}\n"

fclean:
	@${MAKE} -C ${LIBFT_DIR} fclean
	@${MAKE} -C ${LIBMLX_PATH} fclean
	@${RM} ${NAME} ${OBJS}
	@printf "${PROMPT} ${LBLUE} - Deleted ${NAME}${DEF}\n"

re:	fclean all

.PHONY:	all clean fclean re
