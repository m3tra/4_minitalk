/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:35:04 by fporto            #+#    #+#             */
/*   Updated: 2021/08/11 23:46:54 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		neg;
	int		pos;
	int		result;

	neg = 1;
	pos = 0;
	result = 0;
	while (*s && (ft_isspace(*s)))
		s++;
	if (*s && *s == '-')
	{
		neg *= -1;
		s++;
	}
	if (*s && *s == '+')
	{
		pos = 1;
		s++;
	}
	if (neg == -1 && pos == 1)
		return (result);
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * neg);
}
