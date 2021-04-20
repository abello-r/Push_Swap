#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./srcs/Libft/libft.h"

typedef	struct	s_stack
{
    int     content;
    struct 	s_stack	*next;
}				t_stack;

typedef struct s_global
{
    t_stack *a;
    t_stack *b;
    int len;

}              t_global;

int ft_error(int ret, char *error);
int check_args(char **argv, int i, int aux);
int adn_control(t_global *g, char **argv, int i, int j);
int adn_size(char **adn);
void free_adn(char **adn);
int fill_list(t_global *g, int *numbers);
t_stack	*ft_lstnew_stack(int content);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
#endif