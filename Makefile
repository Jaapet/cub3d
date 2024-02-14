# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 17:43:32 by ggualerz          #+#    #+#              #
#    Updated: 2024/02/14 18:27:57 by ggualerz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES  = 	main.c \
			parser/parser.c parser/parser_args.c parser/parser_attributes.c parser/parser_colors.c parser/parser_utils.c parser/parser_map.c

NAME     = cub3d
OBJECTS  = ${SOURCES:.c=.o}

LIBFT_PATH = ./libft
LIBFT      = $(LIBFT_PATH)/libft.a

CFLAGS     = -Wall -Wextra -Werror -g -fdiagnostics-color=always 
LDFLAGS    = -L${LIBFT_PATH} -lft

# READLINE_INSTALLED := $(shell brew list --formula | grep -q '^readline$$' && echo 1)

# ifeq ($(READLINE_INSTALLED),1)
#     # Readline is installed
#     # Add necessary flags or commands here
# else
#     # Readline is not installed
#     $(error "Readline is not installed. Please install it using Homebrew.")
# endif

.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(LIBFT) ${OBJECTS}
	clang $(CFLAGS) $(LDFLAGS) -o $(NAME) ${OBJECTS} ./libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

re: fclean all