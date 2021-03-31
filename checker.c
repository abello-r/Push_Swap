#include "swap.h"
#include "./srcs/Libft/libft.h"

int main(int argc, char **argv)
{
    int i;

    //t_stack *a;
    //t_stack *b;

    i = 0;
    if (argc == 1)
        ft_error(1, "Inserta números como argumentos");
    else
        while (++i < argc)
        {
            ft_error(2, "Hay un argumento que no es un número");
            printf("%s\n", argv[i]);
        }
    return(0);
}