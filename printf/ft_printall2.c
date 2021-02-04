/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:18:46 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 01:49:17 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		widthnbrdb16(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_base(f, i);
	k = f->p - ft_strlen(s);
	if (f->minus == 0)
	{
		printnull(k);
		printres16(f, i);
	}
	else if (f->minus == 1)
		printprec16(f, i);
	free(s);
	return (f->p);
}

int		widthnbrp16(t_struct *f, unsigned int i)
{
	if ((i == 0) && (f->p == 0))
		return (printzero(f));
	if (f->minus == 0)
		return (r(f, i));
	else
	{
		if (f->w > f->p)
		{
			p21(f, i);
			return (f->w);
		}
		else
			printprec16(f, i);
	}
	return (f->p);
}

int		r(t_struct *f, unsigned int i)
{
	if (f->w > f->p)
	{
		p11(f, i);
		return (f->w);
	}
	else
	{
		printprec16(f, i);
		return (f->p);
	}
}

int		widthnbrblast16(unsigned int i, t_struct *f)
{
	char	*s;
	int		q;

	s = ft_itoa_base(f, i);
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

void	printprec16(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_base(f, i);
	if (f->p < (int)(ft_strlen(s)))
	{
		write(1, s, ft_strlen(s));
	}
	else if (f->w < (int)(ft_strlen(s)))
	{
		k = f->p - ft_strlen(s);
		printnull(k);
		write(1, s, ft_strlen(s));
	}
	else
	{
		printnull(f->p - ft_strlen(s));
		write(1, s, ft_strlen(s));
	}
	free(s);
}
