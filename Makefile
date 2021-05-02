# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 09:05:02 by ocarlos-          #+#    #+#              #
#    Updated: 2021/01/01 16:26:04 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRC = ft_read.s ft_strlen.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_write.s
OBJ = $(SRC:.s=.o)
A_FLAG = -f elf64

all: 		$(NAME)

$(NAME):	$(OBJ)
			@ar -rc $(NAME) $(OBJ)

%.o: 		%.s
			@nasm $(A_FLAG) $<

test:		all
			@gcc -g main.c *.o
			@./a.out

clean:
			@/bin/rm -f $(OBJ)
			@/bin/rm -f a.out

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all