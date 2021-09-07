/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:21:53 by fporto            #+#    #+#             */
/*   Updated: 2021/08/11 23:51:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char *s, char c)
{
	size_t		i;
	size_t		nb;

	if (s)
	{
		i = 0;
		nb = 0;
		while (s[i])
		{
			while (s[i] && s[i] == c)
			{
				i++;
			}
			if (!s[i])
				return (0);
			while (s[i] && s[i] != c)
				i++;
			nb++;
			while (s[i] && s[i] == c)
				i++;
		}
		return (nb);
	}
	return (0);
}

static int	spaces(char *s, char c)
{
	int			i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

static char	*get_word(char *s, char c)
{
	char		*word;
	size_t		i;

	i = 0;
	if (s[i])
	{
		while (*s && *s == c)
			s++;
		while (s[i] && s[i] != c)
			i++;
		word = malloc(i + 1);
		if (!word)
			return (NULL);
		i = 0;
		while (s[i] && s[i] != c)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
		return (word);
	}
	return (0);
}

static char	*append(char **arr, char *s, int n, char c)
{
	char		*word;

	word = get_word(s, c);
	arr[n] = word;
	return (arr[n]);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char		*str;
	size_t		i;
	size_t		start;
	size_t		nb;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	nb = nb_words((char *)str, c);
	arr = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!arr)
		return (NULL);
	arr[nb] = NULL;
	if (!nb)
		return (arr);
	i = -1;
	start = spaces(str, c);
	while (++i < nb)
	{
		arr[i] = append(arr, str + start, i, c);
		start += (ft_strlen(arr[i]));
		start += spaces(str + start, c);
	}
	return (arr);
}
