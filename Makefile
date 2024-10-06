# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 15:15:51 by moleksan          #+#    #+#              #
#    Updated: 2024/09/18 16:25:30 by moleksan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
INC_DIR = includes

FILES = check complex_sort error_handling input_validation reverse_rotations \
        rotations simple_sort stack_operations stack_utils swap_push main 

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FILES)))
# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

HEADERS = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

