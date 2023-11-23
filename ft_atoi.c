/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:13:00 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/23 09:13:00 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:31:47 by jbadaire          #+#    #+#             */
/*   Updated: 2023/01/17 17:11:31 by jbadaire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		index;
	int		result;
	int		is_pos;

	index = 0;
	is_pos = 1;
	result = 0;
	while (ft_is_space(nptr[index]))
		index++;
	while (ft_is_sign(nptr[index]))
	{
		if (index > 0 && ft_is_sign(nptr[index -1]))
			return (0);
		if (nptr[index++] == '-')
			is_pos = 0;
	}
	while (ft_isdigit(nptr[index]))
	{
		if (result != ((result * 10 + (is_pos * (nptr[index] - '0'))) / 10))
			return (((is_pos + 1) / 2 / -1));
		result = result * 10 + (nptr[index++] - 48);
	}
	if (!is_pos)
		result = 0 - result;
	return (result);
}

long	ft_atoi_long(const char *nptr)
{
	int		index;
	int		result;
	int		is_pos;

	index = 0;
	is_pos = 1;
	result = 0;
	while (ft_is_space(nptr[index]))
		index++;
	while (ft_is_sign(nptr[index]))
	{
		if (index > 0 && ft_is_sign(nptr[index -1]))
			return (0);
		if (nptr[index++] == '-')
			is_pos = 0;
	}
	while (ft_isdigit(nptr[index]))
	{
		if (result != ((result * 10 + (is_pos * (nptr[index] - '0'))) / 10))
			return (((is_pos + 1) / 2 / -1));
		result = result * 10 + (nptr[index++] - 48);
	}
	if (!is_pos)
		result = 0 - result;
	return (result);
}
