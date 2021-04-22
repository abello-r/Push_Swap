/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:12:49 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/22 19:32:11 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ra_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->a) > 1)
	{
		copy_stacks(g);
		aux = malloc(sizeof(t_stack *));
		ft_memcpy(aux, g->head_a, sizeof(t_stack));
		aux->next = NULL;
		while (g->a->next)
			g->a = g->a->next;
		g->a->next = aux;
		g->head_a = g->head_a->next;
		g->a = g->head_a;
	}
	return (0);
}

int	rb_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->b) > 1)
	{
		copy_stacks(g);
		aux = malloc(sizeof(t_stack *));
		ft_memcpy(aux, g->head_b, sizeof(t_stack));
		aux->next = NULL;
		while (g->b->next)
			g->b = g->b->next;
		g->b->next = aux;
		g->head_b = g->head_b->next;
		g->b = g->head_b;
	}
	return (0);
}

int	rr_rule(t_global *g)
{
	ra_rule(g);
	rb_rule(g);
	return (0);
}

int	rra_rule(t_global *g)
{
	int	i;

	i = ft_lstsize_stack(g->a);

	if (ft_lstsize_stack(g->a) > 1)
		while (i-- > 1)
			ra_rule(g);
	ft_draw_lst(g->a);
	return (0);
}

int	rrb_rule(t_global *g)
{
	int	i;

	i = ft_lstsize_stack(g->b);
	if (ft_lstsize_stack(g->b) > 1)
		while (i-- > 1)
			ra_rule(g);
	return (0);
}

int	rrr_rule(t_global *g)
{
	rra_rule(g);
	rrb_rule(g);
	return (0);
}
