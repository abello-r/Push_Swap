/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_update_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <abello-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:14:17 by abello-r          #+#    #+#             */
/*   Updated: 2021/05/03 19:22:03 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_gnl_control(char ***line, int fd, char **buff)
{
	if (fd < 0 || *line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buff)
		return (-1);
	return (0);
}
