/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:06:52 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		widthnbrb(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	k = f->w - ft_strlen(s);
	if ((f->zero == 0) && (f->minus == 0))
	{
		printprobel(k);
		printres(i);
	}
	else if ((f->zero == 1) && (f->minus == 0))
		widthzero(f, i);
	else if (f->minus == 1)
	{
		printres(i);
		printprobel(k);
	}
	free(s);
	return (f->w);
}

int		widthnbrdb(t_struct *f, int i)
{
	char	*s;

	s = ft_itoa(i);
	if (f->minus == 0)
	{
		printnull(f->p - ft_strlen(s));
		printres(i);
	}
	else if (f->minus == 1)
	{
		printnull(f->p - ft_strlen(s));
		printres(i);
	}
	free(s);
	return (f->p);
}

int		widthnbrp(t_struct *f, int i)
{
	if ((i == 0) && (f->p == 0))
		return (printzero(f));
	if (f->minus == 0)
		return (r3(f, i));
	else
	{
		if (f->w > f->p)
		{
			q1(f, i);
			return (f->w);
		}
		else
			printprec(f, i);
	}
	return (f->p);
}

void	q11(t_struct *f, int i)
{
	char	*s;

	s = ft_itoa(i);
	if (((int)(ft_strlen(s)) > f->p))
	{
		printres(i);
		printprobel(f->w - f->p - (ft_strlen(s) - f->p));
	}
	else
	{
		printprec(f, i);
		printprobel(f->w - f->p);
	}
	free(s);
}

void	q21(t_struct *f, int i)
{
	char	*s;

	s = ft_itoa(i);
	if (((int)(ft_strlen(s)) > f->p))
		printprobel(f->w - f->p - (ft_strlen(s) - f->p));
	else
		printprobel(f->w - f->p);
	free(s);
	printprec(f, i);
}
