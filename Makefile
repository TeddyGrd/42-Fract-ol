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

NAME = fractol.a

CFLAGS = -Wall -Werror -Wextra

DEPS = libft.h\
		ft_printf.h \
		fractol.h

SRC = fractol.c

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)