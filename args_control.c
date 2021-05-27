/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:27:09 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/26 19:31:32 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

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

void	check_args(char **argv)
{
	int	i;
	int	aux;

	i = -1;
	aux = -1;
	while (argv[++i])
	{
		if (!(ft_isdigit(argv[1][0])) && argv[1][0] != '-' && argv[1][0] != ' ')
			ft_error(1, "Valor inválido en el argumento");
		aux = -1;
		if (argv[i][++aux] == '-')
		{
			while (argv[i][++aux] != '\0')
			{
				if (!(ft_isdigit(argv[i][aux])) && argv[i][aux] != ' ')
					ft_error(1, "Valor inválido en el argumento");
				if (argv[i][aux] == ' ' && argv[i][aux + 1] == '-')
					aux += 1;
			}
		}
		aux_check_args(argv, i, aux);
	}
}
