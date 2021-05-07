/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:53:14 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/07 16:37:47 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	adn_size(char **adn)
{
	int	i;

	i = 0;
	while (adn[i])
		i++;
	return (i);
}

void	free_adn(char **adn)
{
	int	i;

	i = -1;
	while (adn[++i])
		free(adn[i]);
	free(adn);
}

void	adn_control(t_global *g, char **argv)
{
	int		*numbers;
	char	**adn;

	init_struct(g);
	while (argv[++g->i])
	{
		adn = ft_split(argv[g->i], ' ');
		g->aux += adn_size(adn);
		free_adn(adn);
	}
	numbers = (int *)malloc(sizeof(int) * g->aux);
	if (!numbers)
		ft_error(1, "No hay espacio en el disco");
	g->i = 0;
	g->len = -1;
	while (argv[++g->i])
	{
		g->aux = -1;
		adn = ft_split(argv[g->i], ' ');
		while (adn[++g->aux])
			numbers[++g->len] = ft_atoi(adn[g->aux]);
		free_adn(adn);
	}
	fill_stack_a(g, numbers);
	free(numbers);
}
