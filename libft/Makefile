# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 21:20:45 by mel-idri          #+#    #+#              #
#    Updated: 2020/03/09 15:47:04 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = libft.a

# compilation variables
CFLAGS = -Wall -Wextra -Werror
CC = gcc

# libft																	   #
LIBFT_INC = libft.h
LIBFT = ft_autoalloc.o ft_nbrlen.o ft_nbrlen_base.o ft_atoi.o  \
	ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
	ft_islower.o ft_isprint.o ft_isspace.o ft_isupper.o ft_itoa.o \
	ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o \
	ft_lstnew.o ft_lstsearch.o ft_max.o ft_memalloc.o ft_memccpy.o \
	ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o \
	ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
	ft_putnbr.o ft_putnbr_fd.o ft_putnchar.o ft_putstr.o ft_putstr_fd.o \
	ft_putunbr.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o \
	ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_strichr.o \
	ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
	ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
	ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strrev.o \
	ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o \
	ft_toupper.o ft_putunbr_base.o ft_write_buff.o \
	ft_bigint_add.o ft_bigint_mult.o ft_bigint_power.o ft_bigint_init.o \
	ft_bigint_util.o ft_queue_new.o ft_enqueue.o ft_dequeue.o \
	ft_strglue.o ft_strjoin_free.o ft_strdup_free.o safe_malloc.o
LIBFT_OBJ = $(addprefix $(OBJS_DIR)/, ${LIBFT})

# ft_printf																	   #
PRINTF_INC = libft.h ft_printf/ft_printf.h
PRINTF = conv_di.o conv_u.o conv_o.o \
	conv_c.o conv_s.o conv_f.o \
	conv_f_helper.o conv_percenatge.o conv_x.o \
	conv_p.o ft_printf.o parser.o \
	util.o apply_conv_function.o read_numbers.o \
	get_whole.o get_fraction.o round_float.o
PRINTF_OBJ = $(addprefix ft_printf/$(OBJS_DIR)/, ${PRINTF})

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

$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ar rc $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@echo "$(GREEN)LIB$(RESET) libft/$(NAME): $(GREEN)UPDATED!$(RESET)";

$(LIBFT_OBJ): $(OBJS_DIR)/%.o : %.c $(LIBFT_INC)| $(OBJS_DIR)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ$(RESET) libft/$@: $(YELLOW)UPDATED!$(RESET)";


$(PRINTF_OBJ): ft_printf/$(OBJS_DIR)/%.o : ft_printf/%.c $(PRINTF_INC) | $(OBJS_DIR)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ$(RESET) libft/$@: $(YELLOW)UPDATED!$(RESET)";


$(OBJS_DIR):
	@if [ ! -d $(OBJS_DIR) ]; then \
		echo "$(CYAN)DIR$(RESET) libft/$(OBJS_DIR)/: $(CYAN)CREATED!$(RESET)"; \
		mkdir $(OBJS_DIR); \
	fi;
	@if [ ! -d ft_printf/$(OBJS_DIR) ]; then \
		echo "$(CYAN)DIR$(RESET) libft/ft_printf/$(OBJS_DIR)/: $(CYAN)CREATED!$(RESET)"; \
		mkdir ft_printf/$(OBJS_DIR); \
	fi;

clean:
	@if [ -d $(OBJS_DIR) ]; then \
		echo "$(RED)OBJ$(RESET) Libft objs: $(RED)REMOVED!$(RESET)"; \
		rm -rf $(OBJS_DIR); \
	fi;
	@if [ -d ft_printf/$(OBJS_DIR) ]; then \
		echo "$(RED)OBJ$(RESET) Printf objs: $(RED)REMOVED!$(RESET)"; \
		rm -rf ft_printf/$(OBJS_DIR); \
	fi;

fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "$(RED)LIB$(RESET) $(NAME): $(RED)REMOVED!$(RESET)"; \
		rm -f $(NAME); \
	fi;

re: fclean all

.PHONY: all fclean re clean
