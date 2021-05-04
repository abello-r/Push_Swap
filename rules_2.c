/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:12:49 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/04 15:03:59 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ra_rule(t_global *g)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (ft_lstsize_stack(g->a) < 1)
		return (1);
		tmp = g->a;
		aux = g->a->next;
		while (g->a->next)
			g->a = g->a->next;
		g->a->next = tmp;
		tmp->next = NULL;
		g->a = aux;
	return (0);
}

int	rb_rule(t_global *g)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (ft_lstsize_stack(g->b) < 1)
		return (1);
	tmp = g->b;
	aux = g->b->next;
	while (g->b->next)
		g->b = g->b->next;
	g->b->next = tmp;
	tmp->next = NULL;
	g->b = aux;
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
	t_stack	*aux;

	g->head_a = g->a;
	aux = g->a;
	if (ft_lstsize_stack(g->a) < 1)
		return (1);
	while (aux->next)
		aux = aux->next;
	ft_lstadd_front_stack(&g->head_a, aux);
	g->head_a = aux;
	while (g->a->next)
	{
		if (g->a->next->content == g->head_a->content)
			break ;
		g->a = g->a->next;
	}
	g->a->next = NULL;
	g->a = g->head_a;
	return (0);
}

int	rrb_rule(t_global *g)
{
	t_stack	*aux;

	g->head_b = g->b;
	aux = g->b;
	if (ft_lstsize_stack(g->b) < 1)
		return (1);
	while (aux->next)
		aux = aux->next;
	ft_lstadd_front_stack(&g->head_b, aux);
	g->head_b = aux;
	while (g->b->next)
	{
		if (g->b->next->content == g->head_b->content)
			break ;
		g->b = g->b->next;
	}
	g->b->next = NULL;
	g->b = g->head_b;
	return (0);
}
