# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/28 15:50:46 by fholwerd      #+#    #+#                  #
#    Updated: 2022/10/14 14:40:18 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME_PW	= push_swap
NAME_CH = checker
SRC		= $(ROOT)src/five_sort.c \
			$(ROOT)src/parse.c \
			$(ROOT)src/radix_sort.c \
			$(ROOT)src/rule_actions.c \
			$(ROOT)src/rules_utility.c \
			$(ROOT)src/rules.c \
			$(ROOT)src/struct_utility.c \
			$(ROOT)src/three_sort.c
SRC_PW	= $(ROOT)src/push_swap.c
SRC_CH	= $(ROOT)src_bonus/checker_bonus.c \
			$(ROOT)src_bonus/get_next_line_bonus.c \
			$(ROOT)src_bonus/get_next_line_utils_bonus.c
OBJ_PW	= $(SRC_PW:.c=.o)
OBJ_CH	= $(SRC_CH:.c=.o)
OBJ		= $(SRC:.c=.o)
INCLUDE	= -I$(ROOT)include \
			-I$(ROOT)libft
INC_CH	= -I$(ROOT)include_bonus
LIB		= $(ROOT)libft/libft.a
CFLAGS	= -Wall -Wextra -Werror

ifdef WITH_BONUS
	NAME = $(NAME_CH)
	OBJ_COMPILE = $(OBJ) $(OBJ_CH)
	INCLUDE := $(INCLUDE) $(INC_CH)
else
	NAME = $(NAME_PW)
	OBJ_COMPILE = $(OBJ) $(OBJ_PW)
endif

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ_COMPILE)
	@make libs
	@echo "Compiling to executable."
	@$(CC) $(OBJ_COMPILE) $(LIB) $(INCLUDE) -o $(NAME)

libs:
	@echo "Compiling libraries."
	@make -C $(ROOT)libft

bonus:
	@$(MAKE) WITH_BONUS=1 all

clean:
	@echo "Cleaning object files."
	@rm -f $(OBJ) $(OBJ_PW) $(OBJ_CH)
	@make clean -C libft

fclean: clean
	@echo "Cleaning executables and generated libraries."
	@rm -f $(NAME_CH)
	@rm -f $(NAME_PW)
	@rm -f libft/libft.a

re: fclean all

.PHONY: all libs bonus clean fclean re