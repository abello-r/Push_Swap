/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:51:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/05 14:31:15 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "./srcs/Libft/libft.h"

int check_args(char **argv, int i, int aux)
{
    if (!(ft_isdigit(argv[1][0])) && argv[1][0] != '-' && argv[1][0] != ' ')
    {
        ft_error(1, "Valor inválido en el argumento");
        return(1);
    }
    aux = -1;
    if (argv[i][++aux] == '-')
    {
        while(argv[i][++aux] != '\0')
        {
            if (!(ft_isdigit(argv[i][aux])) && argv[i][aux] !=  ' ')
            {
                ft_error(1, "Valor inválido en el argumento");
                return(1);
            }
            if (argv[i][aux] == ' ' && argv[i][aux + 1] == '-')
                aux += 1;
            }
    }
    if (ft_isdigit(argv[i][0]))
    {
        while(argv[i][++aux] != '\0')
        {
            if (!(ft_isdigit(argv[i][aux])) && argv[i][aux] != ' ')
            {
                ft_error(1, "Valor inválido en el argumento");
                    return(1);
            }
            if (argv[i][aux] == ' ' && argv[i][aux + 1] == '-')
                aux += 1;
        }
    }
    return(0);
}

int split_args(char **argv, int i, int aux)
{
    char **adn;
    int x = -1;
    aux = 0;

    if (!(adn = malloc(sizeof(char *) * i * aux)))
        return(1);
    while (argv[++i])
        adn = ft_split(argv[i], ' ');
    while (adn[++x])
        printf("%s\n", adn[x]); // Aquí debo hacer el atoi
    return(0);
}

int main(int argc, char **argv)
{
    int i;
    int aux;
    //t_stack *a;
    //t_stack *b;

    i = -1;
    aux = -1;

    if (argc < 2)
        ft_error(2, "Inserta números como argumentos");
    else
        while (argv[++i])
            if (check_args(argv, i, aux) == 1)
                return(1);
    aux = -1;
    i = -1;
    if (split_args(argv, i, aux) == 1)
        return(1);
    return(0);
}
