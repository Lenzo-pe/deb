/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:25:29 by rpaulino          #+#    #+#             */
/*   Updated: 2021/03/27 11:25:29 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

struct s_var
{
	long int	precision_x;
	int			right_zero;
	bool		malloc_used;
	bool		precision_pass;
	bool		noPrecVal;
	bool		zero_before;
	bool		zero_string;
	bool		error;
	bool		abort;
	bool		prec_print_minus;
	bool		print_a_minus;
	long int	flag_minus;
	long int	flag_zero;
	long int	width_size;
	long int	precision_size;
	int			final_size;
};

struct s_flag_stats
{
	int			flag_check;
	int			flag_current;
};

char			*x_times_zero(int d);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_htoa_calc(char *result, char *p, unsigned int n);
int				ft_len_after(const char *format);
char			*pointeraddress(unsigned long int n);
char			*ft_strdup(const char *s);
void			ft_parameter_s(char *pointer, struct s_var *global);
void			ft_parameter_p(void *pointer, struct s_var *global);
int				ft_is_precision(const char *pointer, va_list lista,
					struct s_var *global);
int				ft_prec_error_hand(int parameter, int d, struct s_var *global);
void			ft_prec_error_hand_c(struct s_var *global);
int				ft_prec_error_hand_u(unsigned int u, struct s_var *global);
int				ft_prec_error_hand_x(int parameter, unsigned int u,
					struct s_var *global);
int				ft_is_flag(const char *pointer, va_list lista,
					struct s_var *global);
int				ft_is_width(const char *pointer, va_list lista,
					struct s_var *global);

int				how_many_zeros(const char *pointer);
int				ft_printf(const char *format, ...);
char			*ft_itoa(int n);
char			*ft_htoa_upper(unsigned int n);
char			*ft_htoa_lower(unsigned int n);
int				next_char(const char *pointer);
int				ft_isdigit(int argument);
int				is_type(char n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
int				calc_atoi(const char *str, int len, int counter);
int				ft_isspace(int chr);
void			ft_after(const char *pointer, va_list lista,
					struct s_var *global);
int				ft_final_len(void);
char			*ft_strjoin(char *s1, char const *s2);
void			ft_putsomething(bool type, char c, char *s,
					struct s_var *global);
char			*int_to_str(long int n, int len, char *result, int counter);
int				len_int(long long n);
int				power(long int n, int p);
int				hex_len(unsigned long int n);
char			*ft_utoa(unsigned int n);
char			*ft_revstr(char *result);
size_t			ft_strlen(const char *pointer);
#endif