NAME = libasm.a

D_SRC = src
D_OBJ = obj

CODE = ft_read.s

OBJ = $(patsubst %.s, ${D_OBJ}/%.o, ${CODE})

ASM_COMP = -f elf64

all: $(NAME)

$(D_OBJ)/%.o : $(D_SRC)/%.s
			@mkdir -p $(D_OBJ)
			@nasm $(ASM_COMP) $< -o $@

$(NAME):	$(OBJ)
			@ar -rcs $(NAME) $(OBJ)

test:		all
			@gcc -g main.c ./obj/*.o
			@./a.out

clean:
			@/bin/rm -f $(OBJ)
			@/bin/rm -rf $(D_OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all