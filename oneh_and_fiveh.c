/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oneh_and_fiveh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:27:00 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 17:03:14 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	one_hundred_num(t_global *g)
{
	int		*sort;
	int		num;
	int		inc;
	int		five;

	sort = calc_for_one_algo(g);
	five = 5;
	inc = g->count.size / 5;
	num = inc - 1;
	while (five > 0)
	{
		split_block(g, num, sort);
		num += inc;
		five--;
	}
	if (g->count.rest > 0)
	{
		inc = 0;
		while (inc < g->count.size)
			num = sort[inc++];
		split_block_final(g, num);
	}
	while (g->b)
		volk_b_on_stack_a(g);
	free(sort);
}

void	pack_calc_5(t_global *g)
{
	g->count.size = ft_lstsize_stack(g->a);
	g->count.pack = g->count.size / 11;
	g->count.rest = g->count.size % 11;
}

int	*calc_for_five_hundred_algo(t_global *g)
{
	int	*sort;

	sort = fill_array(g);
	sort = sort_str(g, sort);
	pack_calc_5(g);
	return (sort);
}

void	five_hundred_num(t_global *g)
{
	int		*sort;
	int		num;
	int		inc;
	int		five;

	sort = calc_for_five_hundred_algo(g);
	five = 11;
	inc = g->count.size / 11;
	num = inc - 1;
	while (five > 0)
	{
		split_block(g, num, sort);
		num += inc;
		five--;
	}
	if (g->count.rest > 0)
	{
		inc = 0;
		while (inc < g->count.size)
			num = sort[inc++];
		split_block_final(g, num);
	}
	while (g->b)
		volk_b_on_stack_a(g);
	free(sort);
}
