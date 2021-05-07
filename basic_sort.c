/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:43:28 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/07 16:50:33 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	two_num(t_global *g)
{
	if (g->a->content > g->a->next->content)
		printf("sa\n");
}

void	three_num(t_global *g)
{
	t_stack	*aux;

	aux = g->a;

	if (aux->content < aux->next->content && aux->next->content > aux->next->next->content)
	{
		rra_rule(g);
		printf("rra\n");
		if (g->a->content > g->a->next->content)
		{
			sa_rule(g);
			printf("sa\n");
		}
	}
	else if (aux->content < aux->next->content && aux->next->content > aux->next->next->content)
	{
		sa_rule(g);
		ra_rule(g);
		printf("sa\n");
		printf("ra\n");
	}
	else if (aux->content > aux->next->content && aux->content > aux->next->next->content)
	{
		ra_rule(g);
		printf("ra\n");
		if (g->a->content > g->a->next->content)
		{
			printf("sa\n");
			sa_rule(g);
		}
	}
	else if (aux->content > aux->next->content && aux->next->content > aux->next->next->content)
	{
		sa_rule(g);
		rra_rule(g);
		printf("sa\n");
		printf("rra\n");
	}
	else if (aux->content > aux->next->content)
	{
		sa_rule(g);
		printf("sa\n");
	}
}
