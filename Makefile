# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerran <tguerran@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 11:30:12 by tguerran          #+#    #+#              #
#    Updated: 2024/02/26 01:18:49 by tguerran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra

SRC = fractol.c \
		fractol_utils.c \
		hook/mouse.c \
		hook/keyboard.c \
		fractal/julia.c \
		fractal/mandelbrot.c \
		color.c \
		error.c \

MLX_PATH = /home/tguerran/Bureau/fract-ol/minilibx-linux
MLX_LIB = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm
MLX_INC = -I$(MLX_PATH)

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	@make -C ft_printf
	@make -C Libft
	cc $(CFLAGS) -o $(NAME) $(OFILES) Libft/libft.a ft_printf/libftprintf.a $(MLX_LIB)
	@make clean
clean:
	rm -f $(OFILES)
	@make clean -C Libft
	@make clean -C ft_printf

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)