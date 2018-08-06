#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylesik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 15:07:11 by ylesik            #+#    #+#              #
#    Updated: 2018/04/27 16:19:12 by nnaumenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf
LIBRARY		=	libft/libft.a
MLX_LIBRARY =	-I minilibx/
MLX_LIBRARY2 =	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

FLAGS		= 	-Wall -Werror -Wextra

CC			=	gcc

C_FDF		=	f_asist.c f_asist2.c main.c draw.c bresen.c main_helper.c input.c ft_atoi_base.c

OBJ_D = obj/
OBJ = $(addprefix $(OBJ_D), $(C_FDF:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	make re -C libft/
	$(CC) -g $(MLX_LIBRARY) $(OBJ) -o $(NAME) $(MLX_LIBRARY2) $(LIBRARY)

$(OBJ): | $(OBJ_D)

$(OBJ_D):
	mkdir $(OBJ_D)

$(OBJ_D)%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ_D)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re