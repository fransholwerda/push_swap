# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/15 16:51:44 by fholwerd      #+#    #+#                  #
#    Updated: 2021/08/26 12:33:56 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker
SRCS = parse.c\
		rules.c\
		sort.c\
		struct_loop_utility.c\
		struct_rules_utility.c\
		struct_utility.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c
SRCS_PUSH_SWAP = push_swap.c
SRCS_BONUS = checker.c
LIBS = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADERS = push_swap.h get_next_line.h
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
 MAIN = $(OBJS_BONUS)
 NAME = $(NAME_CHECKER)
else
 MAIN = $(OBJS_PUSH_SWAP)
endif

all: $(NAME)

$(NAME): $(OBJS) $(MAIN)
	make -C ./libft bonus
	$(CC) $(OBJS) $(LIBS) $(MAIN) -o $(NAME)
	chmod +x $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	make -C ./libft clean
	rm -f $(OBJS) $(OBJS_PUSH_SWAP) $(OBJS_BONUS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: all clean fclean re
