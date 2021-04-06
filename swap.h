#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./srcs/Libft/libft.h"

typedef	struct	s_stack
{
    void	*content;
    struct 	s_stack	*next;
}				t_stack;

int ft_error(int ret, char *error);
int check_args(char **argv, int i, int aux);
int adn_control(char **argv, int i, int j);
int adn_size(char **adn);
void free_adn(char **adn);


#endif