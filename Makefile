# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/30 17:20:17 by hhismans          #+#    #+#              #
#    Updated: 2015/01/18 15:17:03 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sortviewer

LIB =	-lft -L./libft\
		-lmlx -lXext -lX11 -L/usr/X11/lib -I includes/ -I libft/

SRC =	main/main.c \
		src/ft_drawline_img_c.c \
		src/ft_drawline_img_c_2.c \
		src/put_pixel_img.c \
		src/rainbow_gen.c \

DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAG) -o $@ $(OBJ) $(LIB)
	@echo "\033[1;33mmake -> $@ created\033[1;37m"

%.o: %.c
	@gcc $(FLAG) -o $@ -c $< $(LIB)
	@echo "\033[36mCompilation of\033[1m $< \033[32m done \033[37m"
clean:
	@make clean -C libft
	@$(DEL) $(OBJ)
	@echo "\033[0;33mclean -> .o deleted"

fclean: clean
	@make fclean -C libft
	@$(DEL) $(NAME)
	@echo "\033[1;31mfclean -> $(NAME) deleted\033[37m"

re: fclean all
	@make fclean -C libft
	@echo "\033[1;30mre -> $(NAME) reloaded\033[1;37m"

.PHONY: all clean fclean re
