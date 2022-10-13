# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 00:59:15 by mravera           #+#    #+#              #
#    Updated: 2022/10/13 17:40:32 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := clang
CFLAGS := -Wall -Werror -Wextra
LIBS := -lXext -lX11 -lmlx -lm -L Libft -lft
RM := rm -f
NAME := so_long

SRCS := $(wildcard *.c)
OBJ := $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re