# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akotilie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/03 15:03:53 by akotilie          #+#    #+#              #
#    Updated: 2017/11/03 15:03:54 by akotilie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =   libftprintf.a

CC =   gcc

FLAGS =  -Wall -Werror -Wextra

HEADER =  libft.h

PRINTF_SRC_HEADER = $(PRINTF_SRC_DIR)ft_printf.h

FT_COMPILED =  ft_printf.o  types.o ft_printf.h process_flags.o ft_atoi.o ft_frontstrtrim.o process_precision.o pr_fl2.o pr_fl3.o\
	ft_memalloc.o ft_putstr.o ft_putchar.o ft_strlen.o ft_strchr.o ft_bzero.o  ft_strncpy.o ft_itoa_new.o ft_strdup.o types2.o\
	ft_strcat.o ft_strcmp.o ft_strcpy.o big_c.o big_s.o ft_memcpy.o helpers.o pr1.o p4_null_rets.o p2_p3_format2.o pr2_realloc.o format1.o

COMPILED = $(FT_COMPILED) 

all: $(NAME)

$(NAME): $(COMPILED)
  @ar rc $(NAME) $(COMPILED)
  @ranlib $(NAME)
  @echo "made" $(NAME)

$(FT_COMPILED): %.o: %.c
  @$(CC) -c $(FLAGS)  $< -o $@

clean:
  @rm -f *.o

fclean: clean
  @rm  -f $(NAME)

re: fclean all
