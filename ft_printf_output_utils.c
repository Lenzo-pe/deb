/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:10:40 by rpaulino          #+#    #+#             */
/*   Updated: 2021/04/16 11:10:40 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putsomething(bool type, char c, char *s, struct s_var *global)
{
	if (!s)
	{
		while (global->width_size > 0 && type)
		{
			ft_putchar_fd(' ', 1);
			global->width_size--;
			global->final_size++;
		}
		ft_putchar_fd(c, 1);
		while (global->flag_minus > 0 && type)
		{
			ft_putchar_fd(' ', 1);
			global->flag_minus--;
			global->final_size++;
		}
		if (type)
			global->flag_minus -= 1;
		global->final_size++;
	}
	else
	{
		if (type)
		{
			global->flag_minus = global->flag_minus - ft_strlen(s);
			global->flag_zero = global->flag_zero - ft_strlen(s);
			global->width_size = global->width_size - ft_strlen(s);
			if (global->print_a_minus)
			{
				global->flag_minus--;
				global->width_size--;
				global->flag_zero--;
			}
			if (global->precision_size > 0)
			{
				global->width_size -= global->flag_zero;
				global->flag_minus -= global->flag_zero;
			}
		}
		if (global->right_zero > 0)
		{
			if (global->width_size > 0)
			{
				global->flag_minus = global->width_size;
				global->width_size = 0;
			}
			else if (global->flag_zero > 0)
			{
				global->flag_minus = global->flag_zero;
				global->flag_zero = 0;
			}
		}
		while (global->width_size > 0 && type)
		{
			ft_putchar_fd(' ', 1);
			global->width_size--;
			global->final_size++;
		}
		if (global->print_a_minus)
			ft_putsomething(false, '-', 0, global);
		while (global->flag_zero > 0 && type)
		{
			ft_putchar_fd('0', 1);
			global->flag_zero--;
			global->final_size++;
		}
		ft_putstr_fd(s, 1);
		while (global->flag_minus > 0 && type)
		{
			ft_putchar_fd(' ', 1);
			global->flag_minus--;
			global->final_size++;
		}
		global->final_size += ft_strlen(s);
	}
}
