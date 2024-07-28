# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 11:59:30 by renatanaesi       #+#    #+#              #
#    Updated: 2024/07/27 15:42:01 by renatanaesi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
PRINTF = ./printf/ft_printf.o
PRINTF_DIR = ./printf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o) # change the source file to object file - Altera os arquivos .c para .o para serem compilados
AR = ar rc # archive command to create a static library. r - replace, if the library already exists, c - create a new library
RM = rm -rf # remove command. r - recursive, if the directory is not empty, f - force, ignore nonexistent files and arguments -Comando para remover arquivos	e diretórios. -r remove recursivamente e -f força a remoção sem perguntar

CP = cp # copy command.

all: $(NAME) # make all will compile the library and the bonus

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CP) $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	$(AR) $(NAME) $(PRINTF)

%.o: %.c # compile the source file to object file %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean # remove the object files in the library libftprintf.a and the push_swap.a
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all # make fclean and make all

.PHONY: all clean fclean re
.SILENT: # silence the commands that are executed
