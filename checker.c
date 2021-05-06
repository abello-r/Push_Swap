/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:51:11 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/06 15:27:35 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

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
	read_term(&g);
	return (0);
}
