/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:59:52 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/24 18:33:17 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_stack	*min_num_locate(t_global *g) // Ubica el numero más pequeño de la lst
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

void	push_min_num_b(t_global *g) // Empuja el numero mas pequeño a B
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

int	*fill_array(t_global *g) // Relleno un array con la lst
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
	return(str_sort);
}

int	*sort_str(t_global *g, int *str) // Ordeno el array de menor a mayor
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
	return(str);
}

void	one_hundred_num(t_global *g) // Pues ni puta idea por ahora
{
	int	*sort;

	sort = fill_array(g);
	sort = sort_str(g, sort);

	pack_calc(g);

	//free(str); # RECUERDA HACER EL FREE HIJO DE TU MADRE

/********************************************** PRINTF ARRAY ORDENADA */

	int i = -1;
	printf("\n");
	while (sort[++i] != 0)
		printf(RED "%d " RESET, sort[i]);
	printf("\n\n");

/***********************************************/

	int x;
	int	num;
	int inc;
	int five;
	t_stack *aux;

	five = 5;
	inc = 0;
	x = 0;
	aux = g->a;
	inc = g->count.size / 5;
	num = inc - 1; 				// Start
 
	while (five > 0)
	{
		split_block(g, num, sort);
		x++;
		num += inc;
		five--;
		printf("\n");
	}
	if (g->count.rest > 0)
	{
		x = 0;
		while (sort[x])
		{
			num = x;
			x++;
		}
		split_block(g, num, sort);
		//printf("\n");
	}
	printf("\nLISTA A\n");
	//ft_draw_lst(g->a);
	printf("LISTA B\n");
	ft_draw_lst(g->b);
}
