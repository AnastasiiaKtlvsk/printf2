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

NAME = libftprintf.a

FLAGS =  -Wall -Wextra -Werror

SOURCES = ft_printf.c   types.c ft_printf.h process_flags.c ft_atoi.c ft_frontstrtrim.c process_precision.c pr_fl2.c pr_fl3.c\
	ft_memalloc.c ft_putstr.c ft_putchar.c ft_strlen.c ft_strchr.c ft_bzero.c  ft_strncpy.c ft_itoa_new.c ft_strdup.c types2.c\
	ft_strcat.c ft_strcmp.c ft_strcpy.c big_c.c big_s.c ft_memcpy.c helpers.c pr1.c p4_null_rets.c p2_p3_format2.c pr2_realloc.c format1.c
OBJ = $(SOURCES:.c=.o)

HEADERS = ft_printf.h ft_libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) $? ft_printf.h 

clean:
	@rm -f *.o
	@rm -f libft/*.o

fclean: clean
	@rm  -f $(NAME)

re: fclean all

