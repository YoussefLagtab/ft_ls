# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 10:58:34 by ylagtab           #+#    #+#              #
#    Updated: 2020/02/19 22:59:45 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = ft_ls
LIBFT = libft/libft.a

# compilation variables
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc

INC = ft_ls.h includes/typedefs_macros.h
OBJ =	main.o \
		parser.o \
		handle_link.o \
		new_inode.o \
		new_error.o \
		print_errors.o \
		print_files.o \
		print_files_longlist/fill_acl_ext.o \
		print_files_longlist/fill_nlink.o \
		print_files_longlist/fill_time.o \
		print_files_longlist/print_files_longlist.o \
		print_files_longlist/fill_file_details.o \
		print_files_longlist/fill_perm.o \
		print_files_longlist/fill_user_group.o \
		print_files_longlist/fill_name.o \
		print_files_longlist/fill_size.o \
		print_files_longlist/print_file_details.o

LS_OBJ = $(addprefix $(OBJS_DIR)/, ${OBJ})

# objects directory
OBJS_DIR = objs

# colors
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

$(NAME): libft $(LS_OBJ)
	@$(CC) $(CFLAGS) $(LS_OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)PROGRAM$(RESET) $(NAME): $(GREEN)UPDATED!$(RESET)";

$(OBJS_DIR)/%.o : %.c $(INC) | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ$(RESET) $@: $(YELLOW)UPDATED!$(RESET)";

$(OBJS_DIR):
	@if [ ! -d $(OBJS_DIR) ]; then \
		echo "$(CYAN)DIR$(RESET) $(OBJS_DIR)/: $(CYAN)CREATED!$(RESET)"; \
		mkdir $(OBJS_DIR); \
	fi;

libft:
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

.PHONY: all fclean re clean libft