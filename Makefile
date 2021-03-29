NAME= swap.a
SRCS= 
OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@make -sC ./srcs/Libft
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@echo "\033[32m"Compila correctamente ✅"\033[0m"

all: $(NAME)

run:
	gcc -Wall -Werror -Wextra checker.c utils.c swap.a libft.a
	clear
	@echo "\033[34m"Hecho, ahora ejecuta el a.out ✅"\033[0m"

clean:
	@rm -rf $(NAME) $(OBJ) a.out
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\033[32m"Todo depurado correctamente ✅"\033[0m"

fclean: clean
	@rm -rf libft.a a.out

.PHONY: all clean re