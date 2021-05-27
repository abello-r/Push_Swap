/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_block_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:13:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 20:23:50 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	supp_block_final(t_global *g, int x)
{
	int			numbs_of_ra;
	int			numbs_of_rra;

	if (x >= (ft_lstsize_stack(g->a) / 2))
	{
		numbs_of_rra = (ft_lstsize_stack(g->a) - x);
		while (numbs_of_rra-- > 0)
			draw_rra_rule(g);
		draw_pb_rule(g);
		return (1);
	}
	else if (x < (ft_lstsize_stack(g->a) / 2))
	{
		numbs_of_ra = x;
		while (numbs_of_ra-- > 0)
			draw_ra_rule(g);
		draw_pb_rule(g);
		return (1);
	}
	return (0);
}

void	split_block_final(t_global *g, int num)
{
	t_stack		*aux;
	int			numbs_of_ra;
	int			numbs_of_rra;
	int			x;
	int			inc;

	inc = g->count.rest;
	while (inc)
	{
		aux = g->a;
		x = 0;
		numbs_of_ra = 0;
		numbs_of_rra = 0;
		while (aux)
		{
			if (aux->content <= num)
				if (supp_block_final(g, x) == 1)
					break ;
			x++;
			aux = aux->next;
		}
		inc--;
	}
}
