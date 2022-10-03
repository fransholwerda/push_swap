# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/28 15:50:46 by fholwerd      #+#    #+#                  #
#    Updated: 2022/10/03 17:28:18 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= push_swap
SRC		= $(wildcard $(ROOT)src/*.c) #this is bad
OBJ		= $(SRC:.c=.o)
INCLUDE	= -I$(ROOT)include \
			-I$(ROOT)libft
LIB		= $(ROOT)libft/libft.a
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	make libs
	$(CC) $(OBJ) $(LIB) $(INCLUDE) -o $(NAME)

libs:
	make -C $(ROOT)libft

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re