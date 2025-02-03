# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvasiuko <vvasiuko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 16:43:15 by vvasiuko          #+#    #+#              #
#    Updated: 2024/12/11 14:59:22 by vvasiuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
HEADERS = -I ./include -I $(LIBMLX)/include
SRCS = main.c images.c move.c move_wasd.c \
./utils/map_reader.c ./utils/map_checker.c \
./utils/utils.c ./utils/free.c ./utils/flood_fill.c
OBJS = ${SRCS:.c=.o}
RM = rm -rf

LIBMLX = ./lib/MLX42
LIBFT_PATH = ./lib/libft
LIBS = $(LIBFT_PATH)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: gitclone libmlx libft $(NAME)

gitclone:
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "Cloning MLX42..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a: $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# libft already contains bonus & printf
libft:
	make -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "Done with $(NAME)"

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re libft libmlx gitclone
