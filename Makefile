# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 00:59:15 by mravera           #+#    #+#              #
#    Updated: 2022/10/19 20:44:21 by mravera          ###   ########.fr        #
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

SRCS := $(wildcard *.c)
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