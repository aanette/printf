/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:45:59 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			widthzero16(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_base(f, i);
	k = f->w - ft_strlen(s);
	if (f->zero == 1)
		printnull(k);
	write(1, s, ft_strlen(s));
	free(s);
	return (f->w);
}

void		q2(t_struct *f, unsigned int i)
{
	char	*s;

	s = ft_itoa_u(i);
	if (((int)(ft_strlen(s)) > f->p))
		printprobel(f->w - f->p - (ft_strlen(s) - f->p));
	else
		printprobel(f->w - f->p);
	printprec1(f, i);
	free(s);
}

int			r3(t_struct *f, int i)
{
	if (f->w > f->p)
	{
		q2(f, i);
		return (f->w);
	}
	else
	{
		printprec(f, i);
		return (f->p);
	}
}

void		printnull(int k)
{
	while (k != 0)
	{
		write(1, "0", 1);
		k--;
	}
}
