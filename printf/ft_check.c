/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:11:48 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_minus_zero_dot(const char *fr, t_struct *f)
{
	if (*fr == '0' && f->w == 0 && f->p == -1)
		f->zero = 1;
	else if (*fr == '-')
		f->minus = 1;
	else if (*fr == '.')
		f->p = 0;
}

void		check(va_list ap, const char *fr, t_struct *f)
{
	if (((*fr == '0') && (f->w == 0) && (f->p == -1)) || \
	(*fr == '-') || (*fr == '.'))
		check_minus_zero_dot(fr, f);
	else if (ft_isdigit(*fr))
	{
		if (f->p == -1)
			f->w = f->w * 10 + *fr - 48;
		else
			f->p = f->p * 10 + *fr - 48;
	}
	else if (*fr == '*')
		check_star(ap, f);
}

void		check_star(va_list ap, t_struct *f)
{
	if (f->p == -1)
	{
		f->w = va_arg(ap, int);
		if (f->w < 0)
		{
			f->minus = 1;
			f->w *= -1;
			f->zero = 0;
		}
	}
	else
	{
		f->p = va_arg(ap, int);
		if (f->p < 0)
			f->p = -1;
	}
}

void		check_type(const char *fr, t_struct *f)
{
	if ((*fr == 'd') || (*fr == 'i'))
		f->type = 1;
	else if (*fr == 'u')
		f->type = 2;
	else if (*fr == 'X')
		f->type = 3;
	else if (*fr == 'x')
		f->type = 4;
	else if (*fr == 'c')
		f->type = 5;
	else if (*fr == 's')
		f->type = 6;
	else if (*fr == 'p')
		f->type = 7;
	else if (*fr == '%')
		f->type = 8;
}
