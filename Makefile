# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agondard <agondard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 10:27:28 by agondard          #+#    #+#              #
#    Updated: 2022/01/24 13:22:51 by agondard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCS = srcs/pipex.c \
		srcs/pipex_utils.c \
			fonctions/ft_split.c \
			fonctions/ft_strnstr.c \
			fonctions/ft_strjoin.c \
			fonctions/ft_putstr_fd.c \
			fonctions/ft_strlen.c \

OBJS = 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRCS) -o $@

clean:
	rm -fr $(OBJS)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all

.PHONY : re clean fclean
