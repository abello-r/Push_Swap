/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_rules_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:16:18 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/09 13:21:24 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	draw_sa_rule(t_global *g)
{
	sa_rule(g);
	printf("sa\n");
}

void	draw_sb_rule(t_global *g)
{
	sb_rule(g);
	printf("sb\n");
}

void	draw_ss_rule(t_global *g)
{
	ss_rule(g);
	printf("ss\n");
}

void	draw_ra_rule(t_global *g)
{
	ra_rule(g);
	printf("ra\n");
}

void	draw_rb_rule(t_global *g)
{
	rb_rule(g);
	printf("rb\n");
}
