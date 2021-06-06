/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:04:43 by rpaulino          #+#    #+#             */
/*   Updated: 2021/06/05 14:12:32 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pnull(void *pointer, struct s_var *global)
{
	if (global->precision_size > 0 && pointer == 0)
	{
		ft_putsomething(false, 0, "0x", global);
		global->flag_zero = global->precision_size;
		global->precision_size = 0;
		ft_putsomething(true, 0, "", global);
		return ;
	}
	if (global->precision_pass)
	{
		if (global->precision_size > 0)
		{
			global->flag_zero = global->precision_size;
			global->precision_size = 0;
			ft_putsomething(false, 0, "0x", global);
			ft_putsomething(true, 0, "", global);
		}
		else
			ft_putsomething(true, 0, "0x", global);
	}	
	else
		ft_putsomething(true, 0, "0x0", global);
	return ;
}

void	case_p(char *kk, char *times_zero, char *temp, struct s_var *global)
{
	times_zero = x_times_zero(global->precision_size - (int)ft_strlen(kk));
	temp = ft_strdup(kk);
	free(kk);
	kk = ft_strjoin(times_zero, temp);
	free(temp);
	temp = ft_strdup(kk);
	free(kk);
	kk = ft_strjoin("0x", temp);
	free(temp);
	free(times_zero);
}

void	case_mp(char *kk, char *temp)
{
	temp = ft_strdup(kk);
	free(kk);
	kk = ft_strjoin("0x", temp);
	free(temp);
}

void	ft_parameter_p(void *pointer, struct s_var *global)
{
	char	*kk;
	char	*times_zero;
	char	*temp;

	times_zero = 0;
	temp = 0;
	if (pointer == NULL)
	{
		ft_pnull(pointer, global);
		return ;
	}
	kk = pointeraddress((unsigned long int)pointer);
	if (global->precision_size > (int)ft_strlen(kk) + 1)
		case_p(kk, times_zero, temp, global);
	else
		case_mp(kk, temp);
	global->precision_size = 0;
	if (!global->precision_pass || (global->precision_pass && pointer != NULL))
	{
		ft_putsomething(true, 0, kk, global);
		free(kk);
	}
}
