# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 00:59:15 by mravera           #+#    #+#              #
#    Updated: 2022/10/19 20:59:35 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS := -Wall -Werror -Wextra

#pour Linux
#CC := clang
#LIBS := -lXext -lX11 -lmlx -lm -L Libft -lft

#pour Mac
CC := gcc
LIBS := -L mlx -lmlx -framework OpenGL -framework AppKit -lm -L Libft -lft

RM := rm -f
NAME := so_long

SRCS := sl_check_args.c \
		sl_check_path.c \
		sl_checkmoves.c \
		sl_init_game.c \
		sl_key_press.c \
		sl_move.c \
		sl_parsing.c \
		sl_render.c \
		sl_utils.c \
		so_long.c

OBJ := $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C Libft
	$(MAKE) -C mlx
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean :
	$(MAKE) clean -C Libft
	$(MAKE) clean -C mlx
	$(RM) *.o

fclean : clean
	$(MAKE) fclean -C Libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re