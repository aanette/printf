/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:03:44 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_type(va_list ap, t_struct *f)
{
	int		len;

	len = 0;
	if (f->type == 1)
		len = ft_printnbr(ap, f);
	if (f->type == 2)
		len = ft_printnbru(ap, f);
	if ((f->type == 3) || (f->type == 4))
		len = ft_printnbrx(ap, f);
	if (f->type == 5)
		len = ft_printchar(ap, f);
	if (f->type == 6)
		len = ft_printstr(ap, f);
	if (f->type == 7)
		len = ft_printnbrp(ap, f);
	if (f->type == 8)
		len = ft_printchar(ap, f);
	return (len);
}

void			init_flags(t_struct *f)
{
	f->type = 0;
	f->w = 0;
	f->minus = 0;
	f->minusint = 0;
	f->zero = 0;
	f->p = -1;
	f->star = 0;
}

const char		*parse(va_list ap, const char *fr, t_struct *f)
{
	while (*fr)
	{
		if (ft_strchr(TYPE, *fr))
		{
			check_type(fr, f);
			fr++;
			return (fr);
		}
		else
		{
			check(ap, fr, f);
			fr++;
		}
	}
	return (fr);
}

int				ft_printf(const char *fr, ...)
{
	t_struct	f;
	va_list		ap;
	int			len;

	va_start(ap, fr);
	len = 0;
	init_flags(&f);
	while (*fr != '\0')
	{
		if (*fr != '%')
		{
			len += ft_putchar(*fr);
			fr++;
		}
		else
		{
			fr++;
			fr = parse(ap, fr, &f);
			len += print_type(ap, &f);
			init_flags(&f);
		}
	}
	va_end(ap);
	return (len);
}
