NAME = libasm.a

SRC = ft_read.s ft_strlen.s ft_strcmp.s ft_strcpy.s
OBJ = $(SRC:.s=.o)

A_FLAG = -f elf64

all: $(NAME)

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