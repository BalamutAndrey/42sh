# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <geliz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 17:11:13 by geliz             #+#    #+#              #
#    Updated: 2020/01/22 17:02:15 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes/
SRC_DIR = ./sources
SRC = $(SRC_DIR)/ft_printf_hub.c $(SRC_DIR)/check_content.c $(SRC_DIR)/readkeys.c \
	  $(SRC_DIR)/type_char.c $(SRC_DIR)/type_string.c $(SRC_DIR)/type_percent.c $(SRC_DIR)/type_ptr.c \
	  $(SRC_DIR)/type_int.c $(SRC_DIR)/type_int_convert_to_str.c $(SRC_DIR)/type_int_width_and_space.c \
	  $(SRC_DIR)/type_int_octotorp_base.c $(SRC_DIR)/type_int_hexadec.c \
	  $(SRC_DIR)/ft_ll_itoa.c $(SRC_DIR)/ft_unsigned_ll_itoa_base.c $(SRC_DIR)/ft_unsigned_ll_itoa_base_hub.c \
	  $(SRC_DIR)/type_float.c $(SRC_DIR)/type_float_mant_count.c $(SRC_DIR)/type_float_neg_powers.c \
	  $(SRC_DIR)/type_float_check_parts.c $(SRC_DIR)/type_float_apply_info.c $(SRC_DIR)/type_float_apply_width.c \
	  $(SRC_DIR)/type_float_apply_prec_zero.c $(SRC_DIR)/type_float_apply_prec_not_zero.c \
	  $(SRC_DIR)/type_float_apply_plus_space.c $(SRC_DIR)/type_float_keys_to_spec.c $(SRC_DIR)/type_float_long.c \
	  $(SRC_DIR)/ft_from_lib_newstrings.c $(SRC_DIR)/ft_from_lib_fill_and_del_str.c $(SRC_DIR)/ft_from_lib_atoi_toupp.c \
	  $(SRC_DIR)/ft_type_binary.c $(SRC_DIR)/ft_strjoin_spec.c $(SRC_DIR)/ft_printf_bonus_hub.c $(SRC_DIR)/bonus_colors.c \
	  $(SRC_DIR)/bonus_color_add_colorcode.c $(SRC_DIR)/bonus_color_add_back_colorcode.c \
	  $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_isalnum.c $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isascii.c \
	  $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_lstadd.c \
	  $(SRC_DIR)/ft_lstdel.c $(SRC_DIR)/ft_lstdelone.c $(SRC_DIR)/ft_lstiter.c $(SRC_DIR)/ft_lstmap.c \
	  $(SRC_DIR)/ft_lstnew.c $(SRC_DIR)/ft_memalloc.c $(SRC_DIR)/ft_memccpy.c $(SRC_DIR)/ft_memchr.c \
	  $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_memdel.c $(SRC_DIR)/ft_memmove.c \
	  $(SRC_DIR)/ft_putchar_fd.c $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putendl.c \
	  $(SRC_DIR)/ft_putnbr_fd.c $(SRC_DIR)/ft_putnbr.c $(SRC_DIR)/ft_putstr_fd.c $(SRC_DIR)/ft_putstr.c \
	  $(SRC_DIR)/ft_strchr.c $(SRC_DIR)/ft_strclr.c $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strcpy.c $(SRC_DIR)/ft_strequ.c \
	  $(SRC_DIR)/ft_striter.c $(SRC_DIR)/ft_striteri.c $(SRC_DIR)/ft_strlcat.c $(SRC_DIR)/ft_strmap.c \
	  $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_strncat.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_strnequ.c \
	  $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strsplit.c $(SRC_DIR)/ft_strstr.c \
	  $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_strjoin_arg.c $(SRC_DIR)/ft_atoi_base.c 
OBJ_DIR = ./obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@echo "\033[0m\033[36m$(NAME)\033[1m\033[34m OK\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		@gcc -c $(FLAGS) -I$(HEADERS) $< -o $@

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)

re: fclean all
