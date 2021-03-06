/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:18:33 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 20:31:47 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	check_order_lst(t_global *g)
{
	t_stack	*lst;

	lst = g->a;
	while (lst->next)
	{
		if (lst->content < lst->next->content)
		{
			lst = lst->next;
			if (lst->next == NULL)
				exit(EXIT_SUCCESS);
		}
		else
			break ;
	}
}

void	identify_quantity(t_global *g)
{
	check_order_lst(g);
	if (ft_lstsize_stack(g->a) == 2)
		two_num(g);
	if (ft_lstsize_stack(g->a) == 3)
		three_num(g);
	if (ft_lstsize_stack(g->a) >= 4 && ft_lstsize_stack(g->a) <= 5)
		five_num(g);
	if (ft_lstsize_stack(g->a) >= 6 && ft_lstsize_stack(g->a) <= 100)
		one_hundred_num(g);
	if (ft_lstsize_stack(g->a) >= 101 && ft_lstsize_stack(g->a) <= 2147483647)
		five_hundred_num(g);
}

int	main(int argc, char **argv)
{
	t_global	g;

	if (argc < 2)
		return (0);
	else
	{
		check_neg_sign(argc, argv);
		check_args(argv);
		adn_control(&g, argv);
		identify_quantity(&g);
	}
	return (0);
}
