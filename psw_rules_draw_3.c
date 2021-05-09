/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_rules_draw_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:26:26 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/09 13:27:31 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	draw_pa_rule(t_global *g)
{
	pa_rule(g);
	printf("pa\n");
}

void	draw_pb_rule(t_global *g)
{
	pb_rule(g);
	printf("pb\n");
}
