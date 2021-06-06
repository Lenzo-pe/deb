/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:34:27 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/05 12:26:06 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*x_times_zero(int d)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(char) * d);
	while (i < d)
	{
		string[i] = '0';
		i++;
	}
	string[d] = '\0';
	return (string);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointerdest;
	unsigned char	*pointersource;

	pointerdest = dest;
	pointersource = (unsigned char *)src;
	if (pointerdest == 0 && pointersource == 0)
		return (dest);
	while (n-- > 0)
		*pointerdest++ = *pointersource++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s) + 1;
	dup = malloc(len * sizeof(char));
	if (dup)
	{
		ft_memcpy(dup, s, len);
	}
	return (dup);
}
