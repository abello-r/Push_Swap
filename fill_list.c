/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:53:03 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/24 14:13:34 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	find_repeat_num(t_global *g)
{
	t_stack	*lst;

	while (g->a)
	{
		lst = g->a->next;
		while (lst)
		{
			if (g->a->content == lst->content)
				ft_error(1, "Hay números repetidos");
			lst = lst->next;
		}
		g->a = g->a->next;
	}
	return (0);
}

int	fill_stack_a(t_global *global, int *numbers)
{
	int		i;
	t_stack	*lst;

	i = 0;
	global->a = ft_lstnew_stack(numbers[i]);
	global->head_a = global->a;
	while (++i <= global->len)
	{
		lst = ft_lstnew_stack(numbers[i]);
		ft_lstadd_back_stack(&global->a, lst);
	}
	lst = global->a;
	find_repeat_num(global);
	global->a = lst;
	return (0);
}
