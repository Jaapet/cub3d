# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 17:43:32 by ggualerz          #+#    #+#              #
#    Updated: 2024/02/13 18:45:11 by ndesprez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  = 	main.c

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
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) -o $(NAME) 

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