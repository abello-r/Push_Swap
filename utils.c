/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:10:14 by abello-r          #+#    #+#             */
/*   Updated: 2021/04/21 17:27:45 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	ft_error(int ret, char *error)
{
	if (ret == 1)
	{
		write(2, RED, ft_strlen(RED));
		write(2, "Error: ", 7);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		write(2, RESET, ft_strlen(RESET));
		return (ret);
	}
	if (ret == 2)
	{
		write(2, YELLOW, ft_strlen(YELLOW));
		write(2, "Advertencia: ", 13);
		write(2, error, ft_strlen(error));
		write(2, "\n", 1);
		write(2, RESET, ft_strlen(RESET));
		return (ret);
	}
	return (0);
}
