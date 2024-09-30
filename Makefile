# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 18:25:27 by rnunes-a          #+#    #+#              #
#    Updated: 2024/09/30 18:08:29 by rnunes-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c swap_functions.c stack_functions.c rotate_functions.c \
       push_functions.c sort_stack_functions.c reverse_rotate_functions.c\
	   data_treatment_functions.c move_functions.c find_target_functions.c\
	   fill_positions_functions.c

OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	chmod +x $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
