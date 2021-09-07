/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto-@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:57:49 by fporto            #+#    #+#             */
/*   Updated: 2021/02/27 16:59:00 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*memdest;
	unsigned char	*memsrc;
	size_t			i;

	memdest = (unsigned char *)dest;
	memsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		memdest[i] = memsrc[i];
		if (memsrc[i] == (unsigned char)c)
			return (memdest + i + 1);
		i++;
	}
	return (NULL);
}
