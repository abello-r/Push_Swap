/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:59:52 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/14 18:38:26 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_stack *min_num_address(t_global *g)
{
	t_stack *aux;
	t_stack *locate;
	int p;

	p = 0;
	aux = g->a;
	while (aux)
	{
		if (aux->content < p)
		{
			p = aux->content;
			locate = aux;
		}
		aux = aux->next;
	}
	return (locate);
}

void	one_hundred_num(t_global *g)
{
	t_stack *locate;
//	int num_moves;

	locate = min_num_address(g);
	printf("LOCATE CONTENT [%d]\n", locate->content);
	printf("LOCATE ADDRESS [%p]\n", locate);

	while (g->a)
	{
		if (g->a->content != locate->content)
		{
			draw_ra_rule(g);
		}
		else if (g->a->content == locate->content)
		{
			draw_pb_rule(g);
			break ;
		}
		g->a = g->a->next;
	}

}