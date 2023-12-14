/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 03:51:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/12/03 03:51:57 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_print(int character)
{
	return (character >= 32 && character <= 126);
}