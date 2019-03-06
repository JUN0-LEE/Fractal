# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julee <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 18:26:43 by julee             #+#    #+#              #
#    Updated: 2018/11/27 16:33:52 by julee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = @gcc -Wall -Werror -Wextra

SRC = main.c draw.c hook.c julia.c mandelbrot.c clover.c

OBJ = $(SRC:.c=.o)

LIB = ./libft/libft.a

MINLIBX = ./minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(MINLIBX) -framework OpenGL -framework Appkit

$(LIB):
	@cd libft && make

clean:
	@rm -f $(OBJ)
	@cd libft && make fclean

fclean : clean
	@rm -rf $(NAME)
	@cd libft && make fclean

re: fclean all
