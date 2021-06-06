/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_after_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:15:44 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/16 11:15:44 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	next_char(const char *pointer)
{
	while (*pointer != '\0')
	{
		if (*pointer == 'c')
			return (2);
		if (*pointer == 'd' || *pointer == 'i')
			return (0);
		if (*pointer == 's')
			return (1);
		pointer++;
	}
	return (-1);
}

int 	is_type(char n)
{
	if (n == 's' || n == 'p' || n == 'c' || n == 'd'
		|| n == 'i' || n == 'x' || n == 'X' || n == 'u'
		|| n == '%')
		return (1);
	return (0);
}
