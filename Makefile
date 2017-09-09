# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/31 13:54:12 by cjacquet          #+#    #+#              #
#    Updated: 2017/09/09 15:39:53 by cjacquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_FLAG	=	-lmlx -framework OpenGL -framework AppKit
CFLAGS		=	-Wextra -Wall -Werror -O3
INCL		=	wolf.h
LIB_FLAG	=	-Ilibft/ libft/libft.a
SRCS		=	main.c \
				error.c \
				str_tools.c \
				tools.c \
				tools2.c \
				mlx.c \
				parse.c \
				init.c \
				free_x.c \
				help.c \
				draaw.c \
				minimap.c \
				raycast.c \
				key_hook.c \
				mouse_hook.c\
				color.c
OBJ			=	$(SRCS:.c=.o)
NAME		=	wolf3d

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(CFLAGS) -c $(SRCS) -include $(INCL)
	gcc $(CFLAGS) $(OBJ) $(MLX_FLAG) $(LIB_FLAG) -o $(NAME)

clean :
	make -C libft/ clean
	make -C minilibx_sierra/ clean
	make -C minilibx/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all

sierra :
	make -C libft/
	make -C minilibx_sierra/
	gcc $(CFLAGS) -c $(SRCS) -include $(INCL)
	gcc $(CFLAGS) $(OBJ) -lm -Iminilibx_sierra/ minilibx_sierra/libmlx.a -framework OpenGL -framework AppKit $(LIB_FLAG) -o $(NAME)

.PHONY: sierra clean all
