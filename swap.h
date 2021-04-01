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


#endif