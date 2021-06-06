/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:12:03 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/07 13:12:03 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	long int	number;
	char		*result;
	size_t		len;

	number = (long)n;
	len = len_int(number);
	result = (char *)malloc(len * sizeof(char) + 1);
	if (result == 0)
		return (0);
	return (int_to_str(number, len, result, 0));
}
