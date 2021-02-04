/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:53:05 by aanette           #+#    #+#             */
/*   Updated: 2021/01/21 22:26:27 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		widthnbrb1(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_u(i);
	k = f->w - ft_strlen(s);
	if ((f->zero == 0) && (f->minus == 0))
	{
		printprobel(k);
		printres1(i);
	}
	else if ((f->zero == 1) && (f->minus == 0))
		widthzero1(f, i);
	else if (f->minus == 1)
	{
		printres1(i);
		printprobel(k);
	}
	free(s);
	return (f->w);
}

int		widthnbrd1(t_struct *f, unsigned int i)
{
	if (f->minus == 0)
	{
		printnull(f->p - ft_strlen(ft_itoa_u(i)));
		printres1(i);
	}
	else if (f->minus == 1)
	{
		printres1(i);
		printprobel(f->p - ft_strlen(ft_itoa_u(i)));
	}
	return (f->p);
}

int		widthnbrp1(t_struct *f, unsigned int i)
{
	if ((i == 0) && (f->p == 0))
		return (printzero(f));
	if (f->minus == 0)
		return (r2(f, i));
	else
	{
		if (f->w > f->p)
		{
			q1(f, i);
			return (f->w);
		}
		else
			printprec1(f, i);
	}
	return (f->p);
}

int		r2(t_struct *f, unsigned int i)
{
	if (f->w > f->p)
	{
		q2(f, i);
		return (f->w);
	}
	else
	{
		printprec1(f, i);
		return (f->p);
	}
}

void	q1(t_struct *f, unsigned int i)
{
	char	*s;

	s = ft_itoa_u(i);
	if (((int)(ft_strlen(s)) > f->p))
	{
		printres1(i);
		printprobel(f->w - ft_strlen(s));
	}
	else
	{
		printprec1(f, i);
		printprobel(f->w - f->p);
	}
	free(s);
}
