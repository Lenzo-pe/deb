/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:07:18 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/08 16:07:18 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *pointer)
{
	size_t	counter;

	counter = 0;
	while (pointer[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_revstr(char *result)
{
	char	*rev_result;
	int		result_len;
	int		i;

	i = 0;
	result_len = ft_strlen(result);
	rev_result = malloc(sizeof(char) * result_len + 1);
	while (i < result_len)
	{
		rev_result[i] = result[result_len - i - 1];
		i++;
	}
	rev_result[i] = '\0';
	return (rev_result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (s == 0)
		return (0);
	sub = malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	i = 0;
	while ((i < len) && (start < ft_strlen(s)))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*pointer;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	pointer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (pointer == 0)
		return (0);
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		pointer[i] = s2[j];
		i++;
		j++;
	}
	pointer[i] = '\0';
	return (pointer);
}
