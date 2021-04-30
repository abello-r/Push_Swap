/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:10:14 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/30 13:06:01 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_error(int ret, char *error)
{
	if (ret == 1)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "Error: ", 7);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		write(2, RESET, ft_strlen(RESET));
		exit(EXIT_FAILURE);
	}
	if (ret == 2)
	{
		write(2, YELLOW, ft_strlen(YELLOW));
		write(2, "Advertencia: ", 13);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		write(2, RESET, ft_strlen(RESET));
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_draw_lst(t_stack *lst)
{
	if (!lst)
		ft_error(2, "La lista está vacía");
	while (lst)
	{
		printf(INV "[%d]\n" RESET, lst->content);
		lst = lst->next;
	}
	return (0);
}

void	copy_stacks(t_global *g)
{
	if (g->a)
	{
		g->head_a = malloc(sizeof(t_stack));
		ft_memcpy(g->head_a, g->a, sizeof(t_stack));
	}
	if (g->b)
	{
		g->head_b = malloc(sizeof(t_stack));
		ft_memcpy(g->head_b, g->b, sizeof(t_stack));
	}
}

void	check_neg_sign(int argc, char **argv)
{
	int	i;
	int	aux;

	i = 1;
	aux = 0;
	while (i < argc)
	{
		aux = 0;
		while (argv[i][aux] != '\0')
		{
			if (argv[i][aux] != ' ' && argv[i][aux] != '-'
				&& (ft_isdigit(argv[i][aux]) == 0))
				ft_error(1, "Valor inválido en el argumento");
			if (argv[i][aux] == '-' && argv[i][aux + 1] == '\0')
				ft_error(1, "Valor inválido en el argumento");
			aux++;
		}
		i++;
	}
}

void	init_struct(t_global *g)
{
	g->i = 0;
	g->aux = 0;
}
