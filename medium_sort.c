/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:59:52 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 16:29:53 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_stack	*min_num_locate(t_global *g)
{
	t_stack	*aux;
	t_stack	*locate;
	int		p;

	p = 2147483647;
	aux = g->a;
	while (aux)
	{
		if (aux->content < p)
		{
			p = aux->content;
			locate = aux;
		}
		aux = aux->next;
	}
	return (locate);
}

void	push_min_num_b(t_global *g)
{
	t_stack	*locate;
	t_stack	*aux;
	int		num_moves;

	aux = g->a;
	num_moves = 0;
	locate = min_num_locate(g);
	while (aux)
	{
		if (aux->content != locate->content)
			num_moves++;
		else if (aux->content == locate->content)
			break ;
		aux = aux->next;
	}
	while (num_moves-- > 0)
		draw_ra_rule(g);
	draw_pb_rule(g);
}

int	*fill_array(t_global *g)
{
	t_stack	*aux;
	int		*str_sort;
	int		i;
	int		len;

	len = ft_lstsize_stack(g->a) + 1;
	i = 0;
	aux = g->a;
	str_sort = malloc(sizeof(int) * len);
	while (aux)
	{
		str_sort[i] = aux->content;
		aux = aux->next;
		i++;
	}
	str_sort[i] = '\0';
	return (str_sort);
}

int	*sort_str(t_global *g, int *str)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < ft_lstsize_stack(g->a) - 1)
	{
		j = 1;
		while (j < ft_lstsize_stack(g->a))
		{
			if (str[j] < str[j - 1])
			{
				aux = str[j];
				str[j] = str[j - 1];
				str[j - 1] = aux;
			}
			j++;
		}
		i++;
	}
	return (str);
}

int	*calc_for_one_algo(t_global *g)
{
	int	*sort;

	sort = fill_array(g);
	sort = sort_str(g, sort);
	pack_calc(g);
	return (sort);
}
