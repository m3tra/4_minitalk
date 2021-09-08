/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:14:50 by fporto            #+#    #+#             */
/*   Updated: 2021/09/08 14:14:51 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_char(char *str, char c)
{
	char	*new;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_char_to_str(c));
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		new[i] = str[i];
	free(str);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}
