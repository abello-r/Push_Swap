/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volk_on_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:40:42 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 15:41:08 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_stack	*max_num_locate(t_global *g)
{
	int		p;
	t_stack	*aux;
	t_stack	*locate;

	p = -2147483648;
	aux = g->b;
	while (aux)
	{
		if (aux->content > p)
		{
			p = aux->content;
			locate = aux;
		}
		aux = aux->next;
	}
	return (locate);
}

void	volk_b_on_stack_a(t_global *g)
{
	t_stack	*locate;
	t_stack	*aux;
	int		num_moves;

	aux = g->b;
	num_moves = 0;
	locate = max_num_locate(g);
	while (aux)
	{
		if (aux->content != locate->content)
			num_moves++;
		else if (aux->content == locate->content)
			break ;
		aux = aux->next;
	}
	calc_moves_to_a(g, num_moves);
}

void	calc_moves_to_a(t_global *g, int num_moves)
{
	int	numbs_of_rb;
	int	numbs_of_rrb;

	numbs_of_rb = 0;
	numbs_of_rrb = 0;
	if (num_moves >= (ft_lstsize_stack(g->b) / 2))
	{
		numbs_of_rrb = (ft_lstsize_stack(g->b) - num_moves);
		while (numbs_of_rrb > 0)
		{
			draw_rrb_rule(g);
			numbs_of_rrb--;
		}
		draw_pa_rule(g);
	}
	else if (num_moves < (ft_lstsize_stack(g->b) / 2))
	{
		numbs_of_rb = num_moves;
		while (numbs_of_rb > 0)
		{
			draw_rb_rule(g);
			numbs_of_rb--;
		}
		draw_pa_rule(g);
	}
}
