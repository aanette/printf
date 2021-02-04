/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:39:08 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 06:13:02 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		widthnbrppneg(t_struct *f, int i)
{
	int k;

	if (f->minus == 0)
	{
		if (f->w > f->p)
		{
			k = f->w - f->p - 1;
			printprobel(k);
			printprecneg(f, i);
			return (f->w);
		}
		else if (f->w <= f->p)
		{
			printprecneg(f, i);
			return (f->p + 1);
		}
	}
	else
		printprecneg(f, i);
	return (f->p + 1);
}

int		widthnbrblastneg(int i)
{
	char	*s;
	int		q;

	s = ft_itoa(i);
	q = ft_strlen(s);
	write(1, "-", 1);
	write(1, s, q);
	if (i == -2147483648)
	{
		free(s);
		return (q + 1);
	}
	free(s);
	return (q + 1);
}

int		widthnbrblast1(unsigned int i, t_struct *f)
{
	char	*s;
	int		q;

	s = ft_itoa_u(i);
	q = ft_strlen(s);
	if ((i == 0) && (f->p == 0))
	{
		free(s);
		return (printzero(f));
	}
	write(1, s, q);
	free(s);
	return (q);
}

int		widthnbrdb2(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	k = f->p - ft_strlen(s);
	if (f->minus == 0)
	{
		printnull(k);
		printres(i);
	}
	else if (f->minus == 1)
		printprec(f, i);
	free(s);
	return (f->p);
}

int		widthnbrdb1(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_u(i);
	k = f->p - ft_strlen(s);
	if (f->minus == 0)
	{
		printnull(k);
		printres1(i);
	}
	else if (f->minus == 1)
		printprec1(f, i);
	free(s);
	return (f->p);
}
