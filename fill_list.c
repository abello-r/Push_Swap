#include "swap.h"

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

int	fill_list(t_global *global, int *numbers)
{
	int		i;
	t_stack	*lst;

	i = 0;
	global->a = ft_lstnew_stack(numbers[i]); // Crear la primera caja de la lista
	while (++i <= global->len) // Por cada número
	{
		lst = ft_lstnew_stack(numbers[i]); // Crear una caja con el contenido
		ft_lstadd_back_stack(&global->a, lst); // Linkearla a la caja anterior
	}
	lst = global->a; // Apuntar lst a la primera caja de la lista
	while (lst) // Mientras lst recorra la lista 
	{
		printf("[%d SOY LA LISTA MI PANA]\n", lst->content); // Imprimir el contenido de cada caja
		lst = lst->next; // Pasar a la siguiente caja de la lista
	}
	return (0);
}
