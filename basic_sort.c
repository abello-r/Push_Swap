/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:43:28 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/09 13:57:59 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	two_num(t_global *g)
{
	if (g->a->content > g->a->next->content)
		draw_sa_rule(g);
}

void	three_num_support(t_global *g, t_stack *t)
{
	if (t->content > t->next->content
		&& t->content > t->next->next->content)
	{
		draw_ra_rule(g);
		if (g->a->content > g->a->next->content)
			draw_sa_rule(g);
	}
	else if (t->content > t->next->content
		&& t->next->content > t->next->next->content)
	{
		draw_sa_rule(g);
		draw_rra_rule(g);
	}
	else if (t->content > t->next->content)
		draw_sa_rule(g);
}

void	three_num(t_global *g)
{
	t_stack	*t;

	t = g->a;
	if (t->content < t->next->content
		&& t->next->content > t->next->next->content)
	{
		draw_rra_rule(g);
		if (g->a->content > g->a->next->content)
			draw_sa_rule(g);
	}
	else if (t->content < t->next->content
		&& t->next->content > t->next->next->content)
	{
		draw_sa_rule(g);
		draw_ra_rule(g);
	}
	three_num_support(g, t);
}
