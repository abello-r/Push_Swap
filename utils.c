#include "swap.h"

int ft_error(int ret, char *error)
{
    char *yellow = "\033[1;33m";
    char *red = "\033[1;31m";
    char *reset = "\033[0m";

    if (ret == 1)
    {
        write(1, red, ft_strlen(red));
        write(1, "Error: ", 7);
        write(1, error, ft_strlen(error));
        write(1, "\n", 1);
        write(1, reset, ft_strlen(reset));
        return(ret);
    }
    if (ret == 2)
    {
        write(1, yellow, ft_strlen(yellow));
        write(1, "Advertencia: " , 13);
        write(1, error, ft_strlen(error));
        write(1, "\n", 1);
        write(1, reset, ft_strlen(reset));
        return(ret);
    }
    return(0);
}