# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/28 15:50:46 by fholwerd      #+#    #+#                  #
#    Updated: 2022/09/28 16:40:59 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= push_swap
SRC		= $(wildcard $(ROOT)src/*.c) #this is bad
OBJ		= $(SRC:.c=.o)
INCLUDE	= -I$(ROOT)include
LIB		= 
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) $(INCLUDE) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re