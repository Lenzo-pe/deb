/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:06 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/03 15:03:14 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int how_many_zeros(const char *pointer)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (pointer[i] == '0')
	{
		i++;
		n++;
	}
	return n;
}

int	ft_is_precision(const char *pointer, va_list lista, struct s_var *global)
{
	int	n;
	int check;

	
	n = 0;
	if(pointer[0] == '.')
	{
		global->precision_pass = true;
		if (pointer[1] == '0' && pointer[2] == 's')
		{
			n += 2;
			global->abort = true;
			return n;
		}
		n++;
		check = ft_atoi(&pointer[1]);
		if (global->width_size > 0 && (pointer[1] == '0' && check == 0))
		{
			n++;
			global->noPrecVal = true;
			return n;
		}
		if (check == 0 && pointer[1] == '0')
		{
			n++;
			global->width_size = global->flag_zero;
			global->flag_zero = 0;
			global->noPrecVal = true;
			return n;
		}
		if (is_type(pointer[1]))
		{
			if (!check && pointer[1] != 'p')
			{
				global->abort = true;
				return n;
			}
		}
		if (check)
		{
			global->precision_size = check;
			n += len_int(check);
			n += how_many_zeros(&pointer[1]);
		}
		if (pointer[1] == '*')
		{
			global->precision_size = va_arg(lista, int);
			if (!global->precision_size)
				return 0;
			n++;
		}
	}
	return n;
}

int	ft_prec_error_hand(int parameter, int d, struct s_var *global)
{
	int n;
	int original_zero;
	char *temp;

	original_zero = global->flag_zero;
	if (parameter == 'd')
	{
		if (d < 0 && d != -2147483648)
		{
			d *= -1;
			global->print_a_minus = true;
			if (global->flag_zero == 0)
				global->flag_zero++;
		}
		temp = ft_itoa(d);
		n = ft_strlen(temp);
		free(temp);
		if (n < global->precision_size)
			global->flag_zero += (global->precision_size - n) + n;
		else
		{
			if (global->zero_before && global->precision_size > 0)
			{
				global->width_size += global->flag_zero;
				global->flag_zero = 0;
			}
			global->precision_size = 0;
		}
		if (global->zero_before && global->precision_size > 0)
		{
			global->flag_zero -= global->precision_size + (original_zero - global->precision_size);
			global->width_size += n + (original_zero - global->precision_size);
			global->precision_size = 0;
			if (global->print_a_minus)
				global->flag_zero++;
		}
	
	}
	if (parameter == 'i')
	{
		if (d < 0 && d != -2147483648)
		{
			d *= -1;
			global->print_a_minus = true;
			if (global->flag_zero == 0)
				global->flag_zero++;
		}
		temp = ft_itoa(d);
		n = ft_strlen(temp);
		free(temp);
		if (n < global->precision_size)
			global->flag_zero += (global->precision_size - n) + n;
		else
		{
			if (global->zero_before && global->precision_size > 0)
			{
				global->width_size += global->flag_zero;
				global->flag_zero = 0;
			}
			global->precision_size = 0;
		}
		if (global->zero_before && global->precision_size > 0)
		{
			global->flag_zero -= global->precision_size + (original_zero - global->precision_size);
			global->width_size += n + (original_zero - global->precision_size);
			global->precision_size = 0;
			if (global->print_a_minus)
				global->flag_zero++;
		}
	}
	return d;
}

void	ft_prec_error_hand_c(struct s_var *global)
{
	global->width_size -= 1;
	global->flag_minus -= 1;
}

int	ft_prec_error_hand_u(unsigned int u, struct s_var *global)
{
	int n;
	int original_zero;

	original_zero = global->flag_zero;

	n = len_int(u);
	if (n < global->precision_size)
		global->flag_zero += (global->precision_size - n) + n;
	else
	{
		if (global->zero_before && global->precision_size > 0)
		{
			global->width_size += global->flag_zero;
			global->flag_zero = 0;
		}
		global->precision_x = global->precision_size;
		global->precision_size = 0;
	}
	if (global->zero_before && global->precision_size > 0)
	{
		global->flag_zero -= global->precision_size + (original_zero - global->precision_size);
		global->width_size += n + (original_zero - global->precision_size);
		global->precision_x = global->precision_size;
		global->precision_size = 0;
	}
	return u;
}

int	ft_prec_error_hand_x(int parameter, unsigned int u, struct s_var *global)
{
	int n;
	char *temp;
	int original_zero;

	original_zero = global->flag_zero;

	if (parameter == 'x')
		temp = ft_htoa_lower(u);
	else
		temp = ft_htoa_upper(u);
	n = ft_strlen(temp);
	free(temp);
	if (n < global->precision_size)
		global->flag_zero += (global->precision_size - n) + n;
	else
	{
		if (global->zero_before && global->precision_size > 0)
		{
			global->width_size += global->flag_zero;
			global->flag_zero = 0;
		}
		global->precision_x = global->precision_size;
		global->precision_size = 0;
	}
	if (global->zero_before && global->precision_size > 0)
	{
		global->flag_zero -= global->precision_size + (original_zero - global->precision_size);
		global->width_size += n + (original_zero - global->precision_size);
		global->precision_x = global->precision_size;
		global->precision_size = 0;
	}
	return u;
}
	