/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:13:12 by aanette           #+#    #+#             */
/*   Updated: 2021/01/21 22:29:13 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			p1(t_struct *f, unsigned long long i)
{
	char *s;

	s = ft_itoa_basep(i);
	if (((int)(ft_strlen(s)) > f->p))
		printprobel(f->w - f->p - (ft_strlen(s) - f->p));
	else
		printprobel(f->w - f->p);
	printprec16p(f, i);
	free(s);
}

void			p11(t_struct *f, unsigned int i)
{
	char *s;

	s = ft_itoa_base(f, i);
	if (((int)(ft_strlen(s)) > f->p))
		printprobel(f->w - f->p - (ft_strlen(s) - f->p));
	else
		printprobel(f->w - f->p);
	printprec16(f, i);
	free(s);
}

void			p2(t_struct *f, unsigned long long i)
{
	char *s;

	s = ft_itoa_basep(i);
	if (((int)(ft_strlen(s)) > f->p))
	{
		printres16p(i);
		printprobel(f->w - f->p - (ft_strlen(s)) - f->p);
	}
	else
	{
		printprec16p(f, i);
		printprobel(f->w - f->p);
	}
	free(s);
}

void			p21(t_struct *f, unsigned int i)
{
	char *s;

	s = ft_itoa_base(f, i);
	if (((int)(ft_strlen(s)) > f->p))
	{
		printres16(f, i);
		printprobel(f->w - f->p - (ft_strlen(s) - f->p));
	}
	else
	{
		printprec16(f, i);
		printprobel(f->w - f->p);
	}
	free(s);
}
