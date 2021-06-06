/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversor_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:30:35 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/16 11:30:35 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_str(long int n, int len, char *result, int counter)
{
	int	original;

	original = len + counter;
	while (len > 0)
	{
		result[counter] = ((n / power(10, len - 1)) + '0');
		n = (n % power(10, len - 1));
		counter++;
		len--;
	}
	result[original] = '\0';
	return (result);
}

int	calc_atoi(const char *str, int len, int counter)
{
	int	result;

	result = 0;
	while (counter < len)
	{
		if (ft_isdigit(str[counter]))
		{
			result = (result * 10) + (str[counter] - '0');
			counter++;
		}
		else
			return (result);
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		len;
	int		final_result;
	int		counter;

	counter = 0;
	len = ft_strlen(str);
	while (ft_isspace(str[counter]))
		counter++;
	if (str[counter] == '+')
		final_result = calc_atoi(str, len, counter + 1);
	else if (str[counter] == '-')
		final_result = calc_atoi(str, len, counter + 1) * -1;
	else
		final_result = calc_atoi(str, len, counter);
	return (final_result);
}
