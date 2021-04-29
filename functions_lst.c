/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:02:02 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/29 15:40:12 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_lstsize_stack(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstnew_stack(int content)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (!(x))
		return (NULL);
	x->content = content;
	x->next = NULL;
	return (x);
}

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*i;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	i = *lst;
	while (i->next)
	{
		i = i->next;
	}
	i->next = new;
}

void	ft_lstadd_front_stack(t_stack **head, t_stack *new)
{
	t_stack	*element;

	if (!new)
		return ;
	if (!head)
		return ;
	element = new;
	element->next = *head;
	*head = element;
}
