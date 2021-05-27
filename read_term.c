/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:50:47 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/27 15:50:14 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	read_term(t_global *g)
{
	char	*buff;

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
		free(buff);
	}
	ok_and_ko(g);
}

void	ok_and_ko(t_global *g)
{
	t_stack	*find;
	t_stack	*aux;

	aux = g->a;
	if (g->b)
	{
		printf("KO\n");
		exit(EXIT_FAILURE);
	}
	while (aux)
	{
		find = aux->next;
		while (find)
		{
			if (aux->content > find->content)
			{
				printf("KO\n");
				exit(EXIT_FAILURE);
			}
			find = find->next;
		}
		aux = aux->next;
	}
	printf("OK\n");
}
