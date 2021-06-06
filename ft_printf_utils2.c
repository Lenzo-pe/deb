/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:13:11 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/08 16:13:11 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	power(long int n, int p)
{
	int	result;

	result = 1;
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

int	len_int(long long n)
{
	int	counter;

	counter = 0;
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	counter++;
	return (counter);
}

int	hex_len(unsigned long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}

int	ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int chr)
{
	if (chr == '\n' || chr == '\t' || chr == '\v'
		|| chr == '\r' || chr == '\f' || chr == ' ')
		return (1);
	else
		return (0);
}
