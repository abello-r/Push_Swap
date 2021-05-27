/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_supp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:33:39 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 16:17:24 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	pack_calc(t_global *g)
{
	g->count.size = ft_lstsize_stack(g->a);
	g->count.pack = g->count.size / 5;
	g->count.rest = g->count.size % 5;
}

void	split_block(t_global *g, int num, int *sort)
{
	t_stack		*aux;
	int			numbs_of_ra;
	int			numbs_of_rra;
	int			x;
	int			inc;

	inc = g->count.pack;
	while (inc)
	{
		x = 0;
		aux = g->a;
		numbs_of_ra = 0;
		numbs_of_rra = 0;
		while (aux)
		{
			if (aux->content <= sort[num])
			{
				if (x >= (ft_lstsize_stack(g->a) / 2))
				{
					numbs_of_rra = (ft_lstsize_stack(g->a) - x);
					while (numbs_of_rra > 0)
					{
						draw_rra_rule(g);
						numbs_of_rra--;
					}
					draw_pb_rule(g);
					break ;
				}
				else if (x < (ft_lstsize_stack(g->a) / 2))
				{
					numbs_of_ra = x;
					while (numbs_of_ra > 0)
					{
						draw_ra_rule(g);
						numbs_of_ra--;
					}
					draw_pb_rule(g);
					break ;
				}
			}
			x++;
			aux = aux->next;
		}
		inc--;
	}
}

void	split_block_final(t_global *g, int num)
{
	t_stack		*aux;
	int			numbs_of_ra;
	int			numbs_of_rra;
	int			x;
	int			inc;

	inc = g->count.rest;
	aux = g->a;
	x = 0;

	while (inc)
	{
		aux = g->a;
		x = 0;
		numbs_of_ra = 0;
		numbs_of_rra = 0;
		while (aux)
		{
			if (aux->content <= num)
			{
				if (x >= (ft_lstsize_stack(g->a) / 2))
				{
					numbs_of_rra = (ft_lstsize_stack(g->a) - x);
					while (numbs_of_rra > 0)
					{
						draw_rra_rule(g);
						numbs_of_rra--;
					}
					draw_pb_rule(g);
					break ;
				}
				else if (x < (ft_lstsize_stack(g->a) / 2))
				{
					numbs_of_ra = x;
					while (numbs_of_ra > 0)
					{
						draw_ra_rule(g);
						numbs_of_ra--;
					}
					draw_pb_rule(g);
					break ;
				}
			}
			x++;
			aux = aux->next;
		}
		inc--;
	}
}
