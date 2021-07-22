# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/15 16:51:44 by fholwerd      #+#    #+#                  #
#    Updated: 2021/07/22 13:21:06 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker
SRCS = parse.c rules.c struct_loop_utility.c struct_rules_utility.c \
		struct_utility.c
SRCS_BONUS = checker.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADERS = push_swap.h
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
 OBJ_FILES = $(OBJS) $(OBJS_BONUS)
 NAME = checker
else
 OBJ_FILES = $(OBJS)
 NAME = push_swap
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^
	cd libft && $(MAKE)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<
	$(CC) $(NAME) libft/libft.a main.c -o checker

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	cd libft && $(MAKE) clean

cleanlocal:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: cleanlocal
	rm -f $(NAME) $(NAME_CHECKER)
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
