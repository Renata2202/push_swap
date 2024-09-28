# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 18:25:27 by rnunes-a          #+#    #+#              #
#    Updated: 2024/09/28 18:25:34 by rnunes-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
PRINTF = ./printf/libftprintf.a
PRINTF_DIR = ./printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c swap_functions.c stack_functions.c rotate_functions.c \
       push_functions.c sort_stack_functions.c reverse_rotate_functions.c\
	   data_treatment_functions.c data_node_functions.c move_functions.c\
	   fill_positions_functions.c

OBJS = $(SRCS:.c=.o)
AR = ar rc
RM = rm -rf
CP = cp

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)
	chmod +x $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
