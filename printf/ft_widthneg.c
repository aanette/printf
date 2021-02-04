/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthneg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 03:09:40 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 06:50:57 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		widthnbrbneg(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	k = f->w - ft_strlen(s) - 1;
	if ((f->zero == 0) && (f->minus == 0))
	{
		printprobel(k);
		write(1, "-", 1);
		printres(i);
	}
	else if ((f->zero == 1) && (f->minus == 0))
	{
		write(1, "-", 1);
		widthzeroneg(f, i);
	}
	else if (f->minus == 1)
	{
		write(1, "-", 1);
		printres(i);
		printprobel(k);
	}
	free(s);
	return (f->w);
}

int		widthnbrdbneg(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	k = f->p - ft_strlen(s);
	if (f->minus == 0)
	{
		write(1, "-", 1);
		printnull(k);
		printres(i);
	}
	else if (f->minus == 1)
	{
		write(1, "-", 1);
		printnull((k));
		printres(i);
	}
	free(s);
	return (f->p + 1);
}

int		widthnbrpneg(t_struct *f, int i)
{
	if (f->minus == 0)
	{
		if (f->w > f->p)
		{
			w1(f, i);
			return (f->w);
		}
		else if (f->w <= f->p)
		{
			printprecneg(f, i);
			return (f->p + 1);
		}
	}
	else
	{
		return (w2(f, i));
	}
	return (f->p);
}

int		w2(t_struct *f, int i)
{
	char *s;

	s = ft_itoa(i);
	printprecneg(f, i);
	if (f->w > f->p)
	{
		if (((int)(ft_strlen(s)) > f->p))
		{
			printprobel(f->w - f->p - (ft_strlen(s) - f->p + 1));
			free(s);
			return (f->w);
		}
		else
		{
			printprobel(f->w - f->p - 1);
			free(s);
			return (f->w);
		}
	}
	free(s);
	return (f->p + 1);
}

void	w1(t_struct *f, int i)
{
	char *s;

	s = ft_itoa(i);
	if (((int)(ft_strlen(s)) > f->p))
	{
		printprobel(f->w - f->p - (ft_strlen(s) - f->p + 1));
		write(1, "-", 1);
	}
	else
	{
		printprobel(f->w - f->p - 1);
		write(1, "-", 1);
	}
	printprec(f, i);
	free(s);
}
