/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:15:39 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/28 18:37:12 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	sa_rule(t_global *g)
{
	t_stack	*aux;

	copy_stacks(g);
	aux = malloc(sizeof(t_stack *));
	ft_memcpy(aux, g->a, sizeof(t_stack));
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

	copy_stacks(g);
	aux = malloc(sizeof(t_stack *));
	ft_memcpy(aux, g->b, sizeof(t_stack));
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
		ft_draw_lst(g->a);
		ft_draw_lst(g->b);
}

int	pa_rule(t_global *g)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (ft_lstsize_stack(g->b) >= 1)
	{
		aux2 = g->b->next;
		aux = g->b;
		aux->next = g->a;
		g->a = aux;
		g->b = aux2;
	}
	return (0);
}

int	pb_rule(t_global *g)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (ft_lstsize_stack(g->a) >= 1)
	{
		aux2 = g->a->next;
		aux = g->a;
		aux->next = g->b;
		g->b = aux;
		g->a = aux2;
	}
	return (0);
}
