/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_basic_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:38:28 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/26 10:48:06 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	condition_five_num(t_global *g, int umo, int pmo)
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

void	condition_five_num_2(t_global *g)
{
	draw_pa_rule(g);
	draw_sa_rule(g);
	if (g->b->content > g->a->content && g->b->content < g->a->next->content)
	{
		draw_pa_rule(g);
		draw_sa_rule(g);
	}
}

void	ladder_five_num(t_global *g, int umo)
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
}

void	five_num_support(t_global *g, int umo, int pmo, int ero)
{
	int	edo;

	if (g->b->content > umo)
	{
		ladder_five_num(g, umo);
		umo = g->a->next->next->next->content;
		pmo = g->a->next->next->content;
		edo = g->a->next->content;
		ero = g->a->content;
	}
	else if (g->b->content < umo && g->b->content > pmo)
		condition_five_num(g, umo, pmo);
	else if (g->b->content > ero && g->b->content < pmo)
		condition_five_num_2(g);
	if (ft_lstsize_stack(g->a) < 5)
	{
		if (g->b)
			draw_pa_rule(g);
		if (g->b)
			draw_pa_rule(g);
	}
	two_num(g);
}
