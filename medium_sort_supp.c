/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_supp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:33:39 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/24 18:38:38 by abello-r         ###   ########.fr       */
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
	t_stack	*aux;
	int		numbs_of_ra;
	int		numbs_of_rra;
	int		x;
	int		b;
	int		inc;

	printf(RED "\nPosicion [%d]\n", num);
	inc = g->count.pack;
	aux = g->a;
	numbs_of_ra = 0;
	numbs_of_rra = 0;
	x = 0;
	b = 0;

	while (inc)
	{
		x = 0;
		aux = g->a;
		numbs_of_rra = 0;
		numbs_of_ra = 0;

// Seguir aqui.
 
		printf(AZUL "sort[%d]\n" RESET, sort[num]);
		while (aux)
		{
			if (x == 0 && numbs_of_ra == 0 && numbs_of_rra == 0 && aux->content <= sort[num])
			{
				draw_pb_rule(g);
				break ;
			}
			else if (aux->content <= sort[num])
			{
				if (x < (ft_lstsize_stack(g->a) / 2))
					numbs_of_ra = x;
				else
					numbs_of_rra = (ft_lstsize_stack(g->a) - x);
			}
			x++;
			aux = aux->next;
		}
		inc--;
	}
}
