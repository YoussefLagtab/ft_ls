# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 10:58:34 by ylagtab           #+#    #+#              #
#    Updated: 2019/12/21 12:54:36 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = ft_ls
LIBFT = libft/libft.a

# compilation variables
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC = ft_ls.h includes/typedefs_macros.h
OBJ =	main.o
LS_OBJ = $(addprefix $(OBJS_DIR)/, ${OBJ})

# objects directory
OBJS_DIR = objs

# Colors
BLACK	= \033[30m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[93m
BLUE	= \033[34m
MAGENTA	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m
RESET	= \033[0m

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #
all: $(NAME)

$(NAME): $(LIBFT) $(LS_OBJ)
	@$(CC) $(CFLAGS) $(LS_OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)PROGRAM$(RESET) $(NAME): $(GREEN)UPDATED!$(RESET)";

$(LS_OBJ): $(OBJS_DIR)/%.o : %.c $(INC) | $(OBJS_DIR)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ$(RESET) $@: $(YELLOW)UPDATED!$(RESET)";

$(OBJS_DIR):
	@if [ ! -d $(OBJS_DIR) ]; then \
		echo "$(CYAN)DIR$(RESET) $(OBJS_DIR)/: $(CYAN)CREATED!$(RESET)"; \
		mkdir $(OBJS_DIR); \
	fi;

$(LIBFT):
	@make -C libft/

clean:
	@make clean -C libft/
	@if [ -d $(OBJS_DIR) ]; then \
		echo "$(RED)OBJ$(RESET) ft_ls objs: $(RED)REMOVED!$(RESET)"; \
		rm -rf $(OBJS_DIR); \
	fi;

fclean: clean
	@make fclean -C libft/
	@if [ -a $(NAME) ]; then \
		echo "$(RED)PROGRAM$(RESET) $(NAME): $(RED)REMOVED!$(RESET)"; \
		rm -f $(NAME); \
	fi;

re: fclean all

.PHONY: all fclean re clean