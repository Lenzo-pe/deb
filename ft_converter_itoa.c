/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:23:44 by rpaulino          #+#    #+#             */
/*   Updated: 2021/03/27 11:23:44 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	long int	number;
	char		*result;
	size_t		len;
	int			counter;

	number = (long)n;
	counter = 0;
	if (n < 0)
	{
		number *= -1;
		len = len_int(number);
		result = (char *)malloc((len * sizeof(char)) + 2);
		if (result == 0)
			return (0);
		result[0] = '-';
		counter = 1;
	}
	else
	{
		len = len_int(number);
		result = (char *)malloc(len * sizeof(char) + 1);
	}
	if (result == 0)
		return (0);
	return (int_to_str(number, len, result, counter));
}
