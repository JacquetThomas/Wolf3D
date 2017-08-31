# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:42:22 by cjacquet          #+#    #+#              #
#    Updated: 2017/03/08 18:53:06 by cjacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -g -c -Wall -Werror -Wextra

SRCO = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
	   ft_isprint.o ft_memcpy.o ft_memccpy.o ft_memset.o ft_strcat.o \
	   ft_strchr.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlcat.o \
	   ft_strlen.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnstr.o \
	   ft_strrchr.o ft_strstr.o ft_tolower.o ft_toupper.o ft_memmove.o \
	   ft_memcmp.o ft_memchr.o ft_putchar_fd.o ft_putstr_fd.o \
	   ft_putendl_fd.o ft_putendl.o ft_putstr.o ft_putchar.o ft_putnbr.o \
	   ft_putnbr_fd.o ft_strnew.o ft_strdel.o ft_strclr.o ft_memalloc.o \
	   ft_memdel.o ft_striter.o ft_striteri.o ft_strequ.o ft_strnequ.o \
	   ft_strsub.o ft_strjoin.o ft_strmap.o ft_strmapi.o ft_strtrim.o \
	   ft_strsplit.o ft_itoa.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o \
	   ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strlenchar.o

NAME = libft.a

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $@ $(SRCO)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $^ -o $@

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
