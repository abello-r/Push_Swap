/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:43:28 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/11 17:51:05 by abello-r         ###   ########.fr       */
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

void	five_num(t_global *g)
{
	t_stack	*t;
	int		umo;
	int		pmo;
	int		ero;
	int		edo;

	t = g->a;
	edo = 0;
/**************************************************/

	if (ft_lstsize_stack(g->a) == 5)
	{
		draw_pb_rule(g);
		draw_pb_rule(g);
		if (g->b->content < g->b->next->content)
			draw_sb_rule(g);
	}
	else if (ft_lstsize_stack(g->a) == 4)
		draw_pb_rule(g);
	three_num(g);

/**************************************************/

	umo = g->a->next->next->content;
	pmo = g->a->next->content;
	ero = g->a->content;

	if (g->b->content > umo)
	{
		if (g->b->next->content > umo && g->b->next->content < g->b->content)
		{
			draw_pa_rule(g);
			draw_pa_rule(g);
			draw_ra_rule(g);
			draw_ra_rule(g);
		}
		else
		{
			draw_pa_rule(g);
			draw_ra_rule(g);
		}
		umo = g->a->next->next->next->content;
		pmo = g->a->next->next->content;
		edo = g->a->next->content;
		ero = g->a->content;
	}
	else if (g->b->content < umo && g->b->content > pmo)
	{
		draw_rra_rule(g);
		draw_pa_rule(g);
		if (g->b->content > pmo && g->b->content < g->a->content)
		{
			draw_pa_rule(g);
			draw_ra_rule(g);
		}
		else if (g->b->content < umo && g->b->content > pmo)
		{
			draw_pa_rule(g);
			draw_ra_rule(g);
		}
		draw_ra_rule(g);
		draw_ra_rule(g);
	}
	else if (g->b->content > ero && g->b->content < pmo)
	{
		draw_pa_rule(g);
		draw_sa_rule(g);
		if (g->b->content > g->a->content && g->b->content < g->a->next->content)
		{
			draw_pa_rule(g);
			draw_sa_rule(g);
		}
	}
	if (g->b)
		draw_pa_rule(g);
	if (g->b)
		draw_pa_rule(g);
	two_num(g);
	//ft_draw_lst(g->a);
}
