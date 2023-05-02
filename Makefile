# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 15:01:28 by zmakhkha          #+#    #+#              #
#    Updated: 2023/05/02 13:58:51 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FT_PATH = libft/libft.a
SRC = minishell.c \
ft_main_paring.c \
Parsing/tokenizer/ft_oprt_wrd.c \
Parsing/tokenizer/ft_red_quote.c \
Parsing/tokenizer/ft_str_tok.c \
utils/ft_history.c \
utils/ft_prmpt.c \
utils/ft_redirect.c \
utils/ft_token.c \
ft_main_paring.c \

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