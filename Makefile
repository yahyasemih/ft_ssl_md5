# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:23:54 by yez-zain          #+#    #+#              #
#    Updated: 2022/05/06 20:40:59 by yez-zain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_ssl.c ft_ssl_utils.c libc_utils.c main.c md5_utils.c md5.c\
	sha32bits_functions.c sha32bits.c sha224.c sha256.c\
	sha64bits_functions.c sha64bits.c sha512.c sha384.c sha512_224.c\
	sha512_256.c swap_bytes.c hash_functions_utils.c ft_read_block.c
DEPS = md5.h libc_utils.h ft_ssl.h sha224.h sha256.h sha32bits_functions.h\
	sha32bits.h sha64bits.h sha64bits_functions.h sha512.h sha384.h\
	sha512_224.h sha512_256.h swap_bytes.h hash_functions_utils.h ft_read_block.h
OBJECTS = $(SRCS:.c=.o)
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(RED)Compiling $(NAME)...$(NC)"
	@echo "$(RED)Linking...$(NC)"
	@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Finished linking && compiling...$(NC)"

%.o: %.c $(DEPS)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(RED)Compiling $< ...$(NC)"

clean:
	@echo "$(RED)Cleaning objects...$(NC)"
	@rm -rf $(OBJECTS)
	@echo "$(GREEN)Cleaned objects...$(NC)"

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -rf $(NAME)
	@echo "$(GREEN)Cleaned $(NAME)...$(NC)"

re: fclean all
