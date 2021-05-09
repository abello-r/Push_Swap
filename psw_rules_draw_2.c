/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_rules_draw_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:23:02 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/09 13:25:02 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	draw_rr_rule(t_global *g)
{
	rr_rule(g);
	printf("rr\n");
}

void	draw_rra_rule(t_global *g)
{
	rra_rule(g);
	printf("rra\n");
}

void	draw_rrb_rule(t_global *g)
{
	rrb_rule(g);
	printf("rrb\n");
}

void	draw_rrr_rule(t_global *g)
{
	rrr_rule(g);
	printf("rrr\n");
}
