/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:50:47 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/28 18:38:22 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	read_term(t_global *g)
{
	char	*buff;

	g->len = 0;
	while (get_next_line (0, &buff) > 0)
	{
		if (!ft_strcmp(buff, "sa"))
			sa_rule(g);
		else if (!ft_strcmp(buff, "sb"))
			sb_rule(g);
		else if (!ft_strcmp(buff, "ss"))
			ss_rule(g);
		else if (!ft_strcmp(buff, "pa"))
			pa_rule(g);
		else if (!ft_strcmp(buff, "pb"))
			pb_rule(g);
		else if (!ft_strcmp(buff, "ra"))
			ra_rule(g);
		else if (!ft_strcmp(buff, "rb"))
			rb_rule(g);
		else if (!ft_strcmp(buff, "rr"))
			rr_rule(g);
		else if (!ft_strcmp(buff, "rra"))
			rra_rule(g);
		else if (!ft_strcmp(buff, "rrb"))
			rrb_rule(g);
		else if (!ft_strcmp(buff, "rrr"))
			rrr_rule(g);
		else
			ft_error(1, "Regla inválida");
	}
	ft_draw_lst(g->a);
}
