/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:15:39 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/22 18:17:31 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	sa_rule(t_global *g)
{
	t_stack	*aux;

	aux = g->a;
	g->head_a = g->a;
	if (ft_lstsize_stack(g->a) > 1)
	{
		g->a = g->a->next->next;
		g->head_a = g->head_a->next;
		aux->next = NULL;
		g->head_a->next = aux;
		g->head_a->next->next = g->a;
		g->a = g->head_a;
	}
	return (0);
}

int	sb_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->b) < 1)
		return (1);
	aux = g->b;
	g->head_b = g->b;
	if (ft_lstsize_stack(g->b) > 1)
	{
		g->b = g->b->next->next;
		g->head_b = g->head_b->next;
		aux->next = NULL;
		g->head_b->next = aux;
		g->head_b->next->next = g->b;
		g->b = g->head_b;
	}
	return (0);
}

int	ss_rule(t_global *g)
{
	sa_rule(g);
	sb_rule(g);
	return (0);
}

int	pa_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->b) >= 1)
	{
		aux = g->b;
		g->b = g->b->next;
		aux->next = g->a;
		g->a = aux;
	}
	return (0);
}

int	pb_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->a) < 1)
		return (1);
	aux = g->a;
	g->a = g->a->next;
	aux->next = g->b;
	g->b = aux;
	return (0);
}
