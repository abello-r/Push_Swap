NAME= swap.a
GNL= srcs/gnl/get_next_line_bonus.c
SRCS= $(GNL) utils.c checker.c split_control.c fill_list.c rules.c functions_lst.c rules_2.c rules_3.c read_term.c
OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@make -sC ./srcs/Libft
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@echo "\033[32m"Compila correctamente ✅"\033[0m"

all: $(NAME)


re: fclean all

run:
	gcc -Wall -Werror -Wextra $(SRCS) swap.a libft.a -o checker
	clear
	@echo "\033[34m"Hecho, ahora ejecuta el checker"\033[0m"

todo:
	@echo "Leaks al hacer pb de toda la lista y luego rb o rrb rrr"
	@echo "Push_swap"
	@echo "Norminette en read_term.c y GNL"

dep:
	@clear
	@for i in `seq 1 15`; do echo "\033[36m"--Depurando Terminal--"\033[0m "; sleep 0.15; done
	@clear

n:
	@clear
	@echo "\033[32m"
	@norminette *.c *.h

clean:
	@rm -rf $(NAME) $(OBJ) checker
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

fclean: clean
	@rm -rf libft.a checker

.PHONY: all clean re fclean n dep run