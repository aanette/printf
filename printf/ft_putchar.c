/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:05:27 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:52:19 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int		ft_printchar(va_list ap, t_struct *f)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (f->type == 8)
		i = '%';
	else
		i = va_arg(ap, int);
	if (f->type == 8 && f->minus == 1)
		f->zero = 0;
	if (f->minus == 1)
		len += ft_putchar(i);
	len += widthchar(f->w, 1, f->zero);
	if (f->minus == 0)
		len += ft_putchar(i);
	return (len);
}

int		widthchar(int w, int len, int zero)
{
	int		l;

	l = 0;
	while (len < w)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		l++;
	}
	return (l);
}

int		ft_printstr(va_list ap, t_struct *f)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if ((f->w != 0) && (f->p == -1))
		len = width_str2(f, str);
	else if ((f->w != 0) && (f->p != -1))
		len = width_str_p2(f, str);
	else if ((f->w == 0) && (f->p != -1))
		len = width_str_2(f, str);
	else if ((f->w == 0) && (f->p == -1))
		len = pstr(str);
	return (len);
}

int		width_str_p2(t_struct *f, char *s)
{
	char	*s2;
	int		i;

	if (f->p < ((int)ft_strlen(s)))
	{
		s2 = ft_substr(s, 0, f->p);
		i = width_str2(f, s2);
		free(s2);
		return (i);
	}
	return (width_str2(f, s));
}
