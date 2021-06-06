/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:09:25 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/03 16:41:13 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_precision(char *pointer, struct s_var *global)
{
	char	*precision;

	precision = 0;
	if (pointer == NULL)
	{
		if (global->precision_size < (int)ft_strlen("(null)"))
		{
			global->flag_minus--;
			global->width_size--;
			precision = ft_substr("(null)", 0, global->precision_size);
			ft_putsomething(true, 0, precision, global);
			free(precision);
		}
		else
		{
			global->precision_size = 0;
			ft_putsomething(true, 0, "(null)", global);
		}
		return ;
	}
}

void	ft_parameter_s(char *pointer, struct s_var *global)
{
	char	*precision;
	int		check;

	check = 0;
	precision = 0;
	if (global->precision_size > 0)
	{
		ft_s_precision(pointer, global);
		check = (int)ft_strlen(pointer);
		if (global->precision_size < check)
		{
			precision = ft_substr(pointer, 0, global->precision_size);
			global->precision_size = 0;
		}
	}
	global->precision_size = 0;
	if (pointer == NULL)
		ft_putsomething(true, 0, "(null)", global);
	else if (precision != 0)
	{
		ft_putsomething(true, 0, precision, global);
		free(precision);
	}
	else
		ft_putsomething(true, 0, pointer, global);
}
