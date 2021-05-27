/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_supp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:33:39 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 20:17:27 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	pack_calc(t_global *g)
{
	g->count.size = ft_lstsize_stack(g->a);
	g->count.pack = g->count.size / 5;
	g->count.rest = g->count.size % 5;
}

void	aux_rra_while(t_global *g)
{
	int	numbs_of_rra;

	numbs_of_rra = (ft_lstsize_stack(g->a) - g->i);
	while (numbs_of_rra > 0)
	{
		draw_rra_rule(g);
		numbs_of_rra--;
	}
	draw_pb_rule(g);
}

void	aux_ra_while(t_global *g)
{
	int	numbs_of_ra;

	numbs_of_ra = g->i;
	while (numbs_of_ra > 0)
	{
		draw_ra_rule(g);
		numbs_of_ra--;
	}
	draw_pb_rule(g);
}

int	top_or_under(t_global *g, t_stack *aux, int *sort, int num)
{
	if (aux->content <= sort[num])
	{
		if (g->i >= (ft_lstsize_stack(g->a) / 2))
		{
			aux_rra_while(g);
			return (1);
		}
		else if (g->i < (ft_lstsize_stack(g->a) / 2))
		{
			aux_ra_while(g);
			return (1);
		}
	}
	return (0);
}

void	split_block(t_global *g, int num, int *sort)
{
	t_stack		*aux;

	init_struct(g);
	while (g->inc)
	{
		g->i = 0;
		aux = g->a;
		while (aux)
		{
			if (top_or_under(g, aux, sort, num) == 1)
				break ;
			g->i++;
			aux = aux->next;
		}
		g->inc--;
	}
}
