# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 00:43:30 by rlecart           #+#    #+#              #
#    Updated: 2017/08/10 20:05:43 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	PUSH_SWAP
NAME1		=	push_swap
NAME2		=	checker
BINDIR		=	bin/
SRCDIR		=	srcs/
SRC1		=	push_swap.c
SRC2		=	checker.c
LIBFT		=	libft/libft.a
OBJ1		=	$(addprefix $(BINDIR),$(SRC1:.c=.o))
OBJ2		=	$(addprefix $(BINDIR),$(SRC2:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -I libft/includes/
OPTI		=	-O3
DEBUG		=	-g

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: lib $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(BINDIR) $(OBJ1)
	@printf "\r$(GREEN)[$(PROJECT)] Bin compilation done.                                                        \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1) $(LIBFT) $(DEBUG)
	@printf "\r$(GREEN)[$(PROJECT)] Compilation done.                          \n$(NO_COLOR)"

$(NAME2): $(LIBFT) $(BINDIR) $(OBJ2)
	@printf "\r$(GREEN)[$(PROJECT)] Bin compilation done.                                                        \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) $(LIBFT) $(DEBUG)
	@printf "\r$(GREEN)[$(PROJECT)] Compilation done.                          \n$(NO_COLOR)"

$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@ -g                                                          \r"
	@$(CC) $(CFLAGS) -o $@ -c $< $(DEBUG)

lib:
	@make -s -C libft 2> /dev/null > /dev/null

$(BINDIR):
	@mkdir bin

clean:
	@make -s -C libft clean
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ1)
	@rm -rf $(OBJ2)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Bin removed.                                                   \n$(NO_COLOR)"

fclean:
	@make -s -C libft fclean
	@printf "$(YELLOW)[$(PROJECT)] Removing bin..."
	@rm -rf $(OBJ1)
	@rm -rf $(OBJ2)
	@rm -rf $(BINDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Bin removed.                                                   \n$(NO_COLOR)"
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME1)
	@rm -rf $(NAME2)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                               \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
