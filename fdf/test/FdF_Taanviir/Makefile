# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanas <tanas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 22:21:39 by tanas             #+#    #+#              #
#    Updated: 2023/02/28 19:35:24 by tanas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colours
GREEN = "\e[1;32m"
RED = "\e[1;3;31m"
BLUE = "\e[3;34m"
YELLOW = "\e[0;33m"
RESET = "\e[0m"

NAME = fdf

C_FLAGS = -Wall -Wextra -Werror
UNAME = $(shell uname)
LIBRARY_FLAGS = -Llibft/ -lft -lm -lz -lmlx -Llibft/
INCLUDES = -Iincludes/ -Ilibft/includes

ifeq ($(UNAME), Linux)
	LIBRARY_FLAGS += -Lmlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11
	INCLUDES += -Imlx_linux/ -I/usr/include -D__LINUX__
	MLX_DIR = mlx_linux/
else ifeq ($(UNAME), Darwin)
	LIBRARY_FLAGS += -Lmlx_macos/ -framework OpenGL -framework AppKit
	INCLUDES += -Imlx_macos/
	MLX_DIR = mlx_macos/
endif

SRCS_DIR = sources
SRCS = main.c events.c line.c image.c map.c draw.c error.c colours.c \
	projection.c menu.c

OBJS_DIR = objects
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

LIBFT = libft/libft.a
MINILIBX = $(MLX_DIR)libmlx.a

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS)
	@cc $(C_FLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBRARY_FLAGS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@cc $(C_FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BLUE)"Compiling $<."$(RESET)

$(LIBFT) :
	@echo $(YELLOW)"Creating $(LIBFT)"$(RESET)
	@make -sC libft
	@echo $(GREEN)"\nLibft is ready. ✅\n"$(RESET)

$(MINILIBX) :
	@echo $(YELLOW)"Creating $(MINILIBX)"$(RESET)
	@make -sC $(MLX_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		cp $(MLX_DIR)libmlx.dylib ./ ; \
	fi
	@echo $(GREEN)"MLX Library is ready. ✅\n"$(RESET)

valgrind : C_FLAGS += -g3 -DDEBUG
valgrind : re
	@echo $(YELLOW)"\nRunning valgrind"$(RESET)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) test_maps/42.fdf

debug : C_FLAGS += -g3 -DDEBUG
debug : re
	@echo $(YELLOW)"\n$(NAME) is now in debug mode"$(RESET)

sanitize : C_FLAGS += -g3 -fsanitize=address
sanitize : re
	@echo $(YELLOW)"\n$(NAME) is now in sanitize mode"$(RESET)

clean :
	@make clean -sC libft
	@make clean -sC $(MLX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo $(RED)"\nRemoving object directory and files"$(RESET)

fclean : clean
	@rm -f $(NAME)
	@if [ $(UNAME) = Darwin ]; then \
		rm -f libmlx.dylib; \
	fi
	@make fclean -sC libft
	@echo $(RED)"Removing $(NAME), libft.a and libmlx.a\n"$(RESET)

re : fclean all

.PHONY = all clean fclean re