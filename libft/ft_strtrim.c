/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:20:02 by fporto            #+#    #+#             */
/*   Updated: 2021/08/11 23:52:17 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	nset(char *s, char *set)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (is_set(s[i], (char *)set) && s[i])
	{
		i++;
		n++;
	}
	if (i < ft_strlen((char *)s))
	{
		i = ft_strlen((char *)s) - 1;
		while (is_set(s[i], (char *)set) && s[i])
		{
			i--;
			n++;
		}
	}
	return (n);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (is_set(s1[i], (char *)set))
		i++;
	start = i;
	i = ft_strlen((char *)s1) - 1;
	while (i > 0 && is_set(s1[i], (char *)set))
		i--;
	end = i;
	str = malloc(ft_strlen((char *)s1) - nset((char *)s1, (char *)set) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end + 1)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
