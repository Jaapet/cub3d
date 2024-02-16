# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 17:43:32 by ggualerz          #+#    #+#              #
#    Updated: 2024/02/16 15:31:45 by ggualerz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  = 	main.c \
			parser/parser.c parser/parser_args.c parser/parser_attributes.c parser/parser_colors.c parser/parser_utils.c parser/parser_utils_lst.c parser/parser_map.c\
			raycasting/init.c raycasting/raycasting.c
NAME     = cub3d
OBJECTS  = ${SOURCES:.c=.o}

LIBFT_PATH = ./libft
LIBFT      = $(LIBFT_PATH)/libft.a

MLX_PATH = ./mlx
MLX      = $(MLX_PATH)/libmlx.a

CFLAGS     = -Wall -Wextra -Werror -g -fdiagnostics-color=always 
LDFLAGS    = -L${LIBFT_PATH} -L${MLX_PATH} -lft  -lmlx -lm -lbsd -lX11 -lXext


.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(LIBFT) ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) -o $(NAME) ./libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

re: fclean all