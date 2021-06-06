/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:15:58 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/12 17:15:58 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_global(struct s_var *global)
{
	global->right_zero = 0;
	global->precision_x = 0;
	global->precision_pass = false;
	global->noPrecVal = false;
	global->zero_before = false;
	global->error = false;
	global->abort = false;
	global->prec_print_minus = false;
	global->print_a_minus = false;
	global->flag_minus = 0;
	global->flag_zero = 0;
	global->width_size = 0;
	global->precision_size = 0;
	global->final_size = 0;
}

void	reset_global(struct s_var *global)
{
	global->precision_x = 0;
	global->right_zero = 0;
	global->precision_pass = false;
	global->noPrecVal = false;
	global->zero_before = false;
	global->error = false;
	global->abort = false;
	global->prec_print_minus = false;
	global->print_a_minus = false;
	global->flag_minus = 0;
	global->flag_zero = 0;
	global->width_size = 0;
	global->precision_size = 0;
}

int	ft_len_after(const char *format)
{
	int	i;

	i = 0;
	while (is_type(format[i]) == 0)
		i++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	struct s_var	global;
	va_list			lista;

	init_global(&global);
	va_start(lista, format);
	i = 0;
	while ((char)format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_after((&format[i + 1]), lista, &global);
			i += ft_len_after(&format[i] + 1) + 1;
			if (global.error)
				return (0);
			reset_global(&global);
		}
		else
			ft_putsomething(false, format[i], 0, &global);
		i++;
	}
	va_end(lista);
	return (global.final_size);
}
