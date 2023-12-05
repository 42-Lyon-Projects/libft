/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:13:00 by jbadaire          #+#    #+#             */
/*   Updated: 2023/11/24 15:38:51 by jbadaire         ###   ########.fr       */
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
#include <limits.h>

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

long long	ft_ll_overflow_atoi(const char *str)
{
	int			sign;
	long long	value;
	int			i;

	sign = 1;
	value = 0;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (ft_is_sign(str[i]))
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] && ft_isdigit(str[i]))
	{
		if (value > LLONG_MAX / 10 || \
		(value == LLONG_MAX / 10 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		value = 10 * value + (str[i++] - '0');
	}
	return (value * sign);
}
