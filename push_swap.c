/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:18:33 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/07 16:25:28 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	identify_quantity(t_global *g)
{
	if (ft_lstsize_stack(g->a) == 2)
		two_num(g);
	if (ft_lstsize_stack(g->a) == 3)
		three_num(g);
}

int	main(int argc, char **argv)
{
	t_global	g;

	if (argc < 2)
		ft_error(2, "Inserta números como argumentos");
	else
	{
		check_neg_sign(argc, argv);
		check_args(argv);
		adn_control(&g, argv);
		identify_quantity(&g);
	}
	return (0);
}
