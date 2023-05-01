# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 15:01:28 by zmakhkha          #+#    #+#              #
#    Updated: 2023/05/01 15:02:14 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FT_PATH = libft/libft.a
SRC =	common_files/lexer/ft_check_hdoc.c \

			main.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra  -fsanitize=address -g

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(SRC) $(FT_PATH) -o $(NAME) -lreadline
%.o:%.c header.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re	: fclean	all

wq	: re	clean 
.PHONY: all clean fclean re 