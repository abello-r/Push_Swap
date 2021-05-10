/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:43:28 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/10 15:04:55 by abello-r         ###   ########.fr       */
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
	t_stack *t;
	int umo;
	int pmo;
	int ero;
	int edo;

	t = g->a;
	
	// Verificar si ya esta ordenada para no hacer nada

	draw_pb_rule(g);
	draw_pb_rule(g);
	three_num(g);

	// Umo ultimo, Pmo penultimo, Ero primero.
	umo = g->a->next->next->content;
	pmo = g->a->next->content;
	ero = g->a->content;

	draw_pa_rule(g);
	if (g->a->content > umo)
		draw_ra_rule(g);
	if (g->a->content > pmo && g->a->content < umo)
	{
		draw_rra_rule(g);
		draw_sa_rule(g);
		draw_ra_rule(g);
		draw_ra_rule(g);
	}
	if (g->a->content > ero && g->a->content < pmo)
		draw_sa_rule(g);

/****************************************************************/

	umo = g->a->next->next->next->content;
	pmo = g->a->next->next->content;
	edo = g->a->next->content;
	ero = g->a->content;

	draw_pa_rule(g);
	if (g->a->content > ero && g->a->content < edo)
		draw_sa_rule(g);
	if (g->a->content > umo)
		draw_ra_rule(g);
	if (g->a->content > pmo && g->a->content < umo)
	{
		draw_rra_rule(g);
		draw_sa_rule(g);
		draw_ra_rule(g);
		draw_ra_rule(g);
	}
	if (g->a->content > ero && g->a->content < pmo)
	{
		draw_sa_rule(g);
		draw_pb_rule(g);
		draw_sa_rule(g);
		draw_pa_rule(g);
	}
	ft_draw_lst(g->a);
}
