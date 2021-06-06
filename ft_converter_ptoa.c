/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:25:31 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/06 13:25:31 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pointeraddress(unsigned long int n)
{
	char	*temp;
	char	*p;
	char	*result;

	if (n == 0)
		return ("0");
	p = "abcdef";
	result = (char *)malloc(sizeof(char) * (hex_len(n) + 1));
	ft_htoa_calc(result, p, n);
	temp = ft_revstr(result);
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}
