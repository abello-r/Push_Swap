NAME= swap.a
GNL= srcs/gnl/get_next_line_bonus.c srcs/gnl/get_next_line_update_utils.c

SRCS= $(GNL) medium_sort_supp.c medium_sort.c supp_basic_sort.c psw_rules_draw_3.c psw_rules_draw_2.c psw_rules_draw.c basic_sort.c args_control.c utils.c split_control.c fill_list.c rules.c functions_lst.c rules_2.c rules_3.c read_term.c
SRCS_P= push_swap.c
SRCS_C= checker.c

OBJ= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[36m"--Compilando--"\033[0m ";
	@make -sC ./srcs/Libft
	@cp ./srcs/Libft/libft.a .
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@clear
	@gcc -Wall -Werror -Wextra $(SRCS) $(SRCS_P) libft.a -o push_swap
	@gcc -Wall -Werror -Wextra $(SRCS) $(SRCS_C) libft.a -o checker
	@clear

all: $(NAME)

re: fclean all

run:
	@echo "\033[36m"Compilando..."\033[0m"
	@gcc -Wall -Werror -Wextra $(SRCS) $(SRCS_P) libft.a -o push_swap
	@gcc -Wall -Werror -Wextra $(SRCS) $(SRCS_C) libft.a -o checker
	clear

todo:
	@echo "falta controlar 100 num"
	@echo "Hacer 100 500"
	@echo "Norminette en read_term.c y gnl"

dep:
	@clear
	@for i in `seq 1 15`; do echo "\033[36m"--Depurando Terminal--"\033[0m "; sleep 0.15; done
	@clear

n:
	@clear
	@echo "\033[32m"
	@norminette *.c *.h

clean:
	@rm -rf $(NAME) $(OBJ) checker push_swap
	@make -sC ./srcs/Libft/ fclean
	@clear
	@echo "\033[34m"🗑️\  Todo depurado correctamente  \🗑️"\033[0m"

fclean: clean
	@rm -rf libft.a checker

.PHONY: all clean re fclean n dep todo