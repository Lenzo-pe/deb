/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:28:21 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/05 14:11:38 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int until_type(const char *pointer)
{
	int i;

	i = 0;
	while(is_type(pointer[i]) == 0)
		i++;
	return i;
}

int	case_minus(int n, const char *pointer, va_list lista, struct s_var *global, struct s_flag_stats *c_c)
{
	if (pointer[0] == '-' || (pointer[0] == '0' && pointer[1] == '-'))
	{
		if (pointer[1] == '0')
		{
			if (pointer[2] == '*' || ft_atoi(&pointer[2]) != 0)
			{
				global->right_zero = 1;
				n++;
				c_c->flag_current += 2;
			}
			if (pointer[3] == '0')
				return n + 2;
		}
		else
		{
			if (pointer[1] == '.')
			{
				n++;
				return n;
			}
			if (pointer[0] == '0')
			{
				c_c->flag_check++;
				n++;
			}
		}
		n++;
		if (pointer[c_c->flag_check] == '*')
		{
			global->flag_minus = va_arg(lista, int);
			if (global->flag_minus < 0)
				global->flag_minus *= -1;
			if (!global->flag_minus)
				return 0;
			n++;
		}
		else if (ft_isdigit(pointer[c_c->flag_check]))
		{
			global->flag_minus = ft_atoi(&pointer[c_c->flag_check]);
			if (ft_atoi(&pointer[c_c->flag_check]) != 0)
				n += len_int(ft_atoi(&pointer[c_c->flag_check]));
			n += how_many_zeros(&pointer[c_c->flag_check]);
		}
		else
		{
			if (!is_type(pointer[c_c->flag_check]))
			{
				global->error = true;
				return 0;
			}
		}
	}
	return (n);
}

int case_zero(int n, const char *pointer, va_list lista, struct s_var *global, struct s_flag_stats *c_c)
{
	if (c_c->flag_current == 0)
		c_c->flag_current = 1;
	if ((pointer[0] == '0' && pointer[1] != '-') || global->right_zero > 0)
	{
		global->zero_before = true;
		n++;
		if (pointer[0] == '0' && (pointer[1] == 'i' || pointer[1] == 'd'))
			return n;
		if (!ft_isdigit(pointer[c_c->flag_current]) && pointer[c_c->flag_current] != '*')
		{
			global->abort = true;
			return n;
		}
		if (pointer[c_c->flag_current] == '*')
		{
			c_c->flag_check = va_arg(lista, int);
			global->flag_zero = c_c->flag_check;
			if (global->flag_zero < 0 && global->right_zero > 0)
			{
				global->flag_zero = 0;
				global->width_size = c_c->flag_check * -1;
				return n + 1;
			}
			if (!global->flag_zero)
				return 0;
			n++;
		}
		if (ft_atoi(&pointer[c_c->flag_current]) == 0 && pointer[c_c->flag_current] != '*')
		{
			n += until_type(&pointer[c_c->flag_current]);
			return n;
		}
		if (ft_isdigit(pointer[c_c->flag_current]))
		{
			global->flag_zero = ft_atoi(&pointer[c_c->flag_current]);
			n += len_int(ft_atoi(&pointer[c_c->flag_current]));
			n += how_many_zeros(&pointer[c_c->flag_current]);
		}
		if (global->flag_zero < 0)
		{
			global->flag_minus = global->flag_zero * -1;
			global->flag_zero = 0;
		}
	}
	return (n);
}

int ft_is_flag(const char *pointer, va_list lista, struct s_var *global)
{
	int n;
	struct s_flag_stats	c_c;

	c_c.flag_current = 0;
	c_c.flag_check = 1;
	n = 0;
	
	n += case_minus(n, pointer, lista, global, &c_c);
	n += case_zero(n, pointer, lista, global, &c_c);
	return n;
}