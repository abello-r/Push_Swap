/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:51:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/23 17:05:28 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include "./srcs/Libft/libft.h"

void	aux_check_args(char **argv, int i, int aux)
{
	if (ft_isdigit(argv[i][0]))
	{
		while (argv[i][++aux] != '\0')
		{
			if (!(ft_isdigit(argv[i][aux])) && argv[i][aux] != ' ')
				ft_error(1, "Valor inválido en el argumento");
			if (argv[i][aux] == ' ' && argv[i][aux + 1] == '-')
				aux += 1;
		}
	}
}

void	check_args(char **argv, int i, int aux)
{
	if (!(ft_isdigit(argv[1][0])) && argv[1][0] != '-' && argv[1][0] != ' ')
		ft_error(1, "Valor inválido en el argumento");
	aux = -1;
	if (argv[i][++aux] == '-')
		while (argv[i][++aux] != '\0')
		{
			if (!(ft_isdigit(argv[i][aux])) && argv[i][aux] != ' ')
				ft_error(1, "Valor inválido en el argumento");
			if (argv[i][aux] == ' ' && argv[i][aux + 1] == '-')
				aux += 1;
		}
	aux_check_args(argv, i, aux);
}

int	main(int argc, char **argv)
{
	t_global	g;
	int			i;
	int			aux;

	i = -1;
	aux = -1;
	check_neg_sign(argc, argv);
	if (argc < 2)
		ft_error(2, "Inserta números como argumentos");
	else
		while (argv[++i])
			check_args(argv, i, aux);
	aux = 0;
	i = 0;
	if (adn_control(&g, argv, i, aux) == 1)
		return (1);
	rra_rule(&g);
	return (0);
}
