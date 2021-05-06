/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:18:33 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/06 19:01:30 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	three_num(t_global *g)
{
	t_stack	*aux;

	g->len = 0;
	aux = g->a;

	while (aux->next)
	{
		if (aux->content < aux->next->content && aux->next->content > aux->next->next->content) // Case 1
			printf("rra 1\n");
		else if (aux->content < aux->next->content && aux->next->content > aux->next->next->content) // Case 2
		{
			printf("sa 2 \n");
			printf("ra 2\n");
		}
		else if (aux->content > aux->next->content && aux->content > aux->next->next->content) // Case 3
			printf("ra 3\n");
		else if (aux->content > aux->next->content && aux->next->content > aux->next->next->content) // Case 4
		{
			printf("sa 4\n");
			printf("rra 4\n");
		}
		else if (aux->content > aux->next->content) // Case 5
			printf("sa 5\n");
		aux = aux->next;
	}
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
	}

	//read_term(&g); Esto lo que hace es leer y ejecutar las RULES.

	if (ft_lstsize_stack(g.a) <= 3)
		three_num(&g);
	return (0);
}
