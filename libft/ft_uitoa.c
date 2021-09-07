/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:38:22 by fporto            #+#    #+#             */
/*   Updated: 2021/08/16 02:21:47 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(unsigned int n)
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

static char	*cat(char *str, long number, int i)
{
	while (i >= 0)
	{
		str[i] = (number % 10) + '0';
		number /= 10;
		i--;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char			*number;
	size_t			len;
	int				i;

	len = ft_nlen(n);
	number = malloc(len + 1);
	if (!number)
		return (NULL);
	i = len - 1;
	if (n)
		number = cat(number, n, i);
	number[len] = '\0';
	if (!n)
		number[0] = 0 + 48;
	return (number);
}
