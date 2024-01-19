# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 11:30:12 by tguerran          #+#    #+#              #
#    Updated: 2023/12/12 12:12:00 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRC = fractol.c \

MLX_PATH = /home/tguerran/Bureau/fract-ol/minilibx-linux
MLX_LIB = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
MLX_INC = -I$(MLX_PATH)

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	cc $(CFLAGS) -o $(NAME) $(OFILES) $(MLX_LIB)

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)