# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXDIR = ./minilibx-linux/
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lbsd
NAME = layertest
SRC = layertest.c

# Targets
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(MLXDIR)libmlx.a $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

.PHONY: all clean