/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:38:22 by fporto            #+#    #+#             */
/*   Updated: 2021/08/17 19:29:44 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int n)
{
	size_t		len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*cat(char *str, long number, int i, int neg)
{
	if (neg)
		str[0] = '-';
	while (i >= neg)
	{
		str[i] = (number % 10) + '0';
		number /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	char		*number;
	int			neg;
	size_t		len;
	int			i;

	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	len = ft_nlen(n);
	number = malloc(len + neg + 1);
	if (!number)
		return (NULL);
	i = len + neg - 1;
	if (n)
		number = cat(number, n, i, neg);
	number[len + neg] = '\0';
	if (!n)
		number[0] = 0 + 48;
	return (number);
}
