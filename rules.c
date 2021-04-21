/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:15:39 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/21 20:08:11 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	sa_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->a) > 1)
	{
		aux = g->a;
		g->a = g->a->next;
		g->a->next = aux;
	}
	return (0);
}

int	sb_rule(t_global *g)
{
	t_stack	*aux;

	if (ft_lstsize_stack(g->b) > 1)
	{
		aux = g->b;
		g->b = g->b->next;
		g->b->next = aux;
	}
	return (0);
}

int	ss_rule(t_global *g)
{
	sa_rule(g);
	sb_rule(g);
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
