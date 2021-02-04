/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:49:37 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:52:19 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if ((!s))
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		pstr(char *str)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

int		width_str2(t_struct *f, char *s)
{
	int k;

	if (f->w <= ((int)ft_strlen(s)))
	{
		k = ft_strlen(s) - f->w;
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else
		k = f->w - ft_strlen(s);
	if ((f->zero == 0) && (f->minus == 0))
	{
		printprobel(k);
		ft_putstr(s);
	}
	else if ((f->zero == 1) && (f->minus == 0))
		width_str_zero(f, s);
	else if (f->minus == 1)
	{
		ft_putstr(s);
		printprobel(k);
	}
	return (f->w);
}

int		width_str_2(t_struct *f, char *s)
{
	if (((int)ft_strlen(s)) <= f->p)
	{
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else if (f->minus == 0)
	{
		ft_printcut(s, f->p, f);
	}
	else if (f->minus == 1)
	{
		if (((int)ft_strlen(s)) >= f->p)
			ft_printcut(s, f->p, f);
	}
	return (f->p);
}

int		width_str_zero(t_struct *f, char *s)
{
	int k;

	k = f->w - ft_strlen(s);
	if (f->zero == 1)
		printnull(k);
	ft_putstr(s);
	return (f->w);
}
