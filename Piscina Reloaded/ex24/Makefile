# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegome2 <alegome2@alumno.42malaga.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/15 16:42:54 by alegome2          #+#    #+#              #
#    Updated: 2026/09/15 17:57:52 by alegome2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs/
SRCFILES = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRC = $(addprefix $(SRCDIR), $(SRCFILES))

OBJ = $(SRC:$(SRCDIR)%.c=$(SRCDIR)%.o)

INCLUDE = ./includes/

AR = ar rcs
RM = rm -f
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(SRCDIR)%.o:$(SRCDIR)%.c 
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

