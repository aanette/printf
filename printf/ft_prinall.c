/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 00:02:53 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:31:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printprec(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
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

void		printprecneg(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	if (f->p < (int)(ft_strlen(s)))
	{
		write(1, "-", 1);
		write(1, s, ft_strlen(s));
	}
	else if (f->w < (int)(ft_strlen(s)))
	{
		k = f->p - ft_strlen(s);
		write(1, "-", 1);
		printnull(k);
		write(1, s, ft_strlen(s));
	}
	else
	{
		write(1, "-", 1);
		printnull(f->p - (ft_strlen(s)));
		write(1, s, ft_strlen(s));
	}
	free(s);
}

int			ft_printnbr(va_list ap, t_struct *f)
{
	int		i;
	int		len;

	i = 0;
	i = va_arg(ap, int);
	if (i >= 0)
	{
		len = ft_printnbrpos(i, f);
		return (len);
	}
	else if (i < 0)
		return (ft_printnbrneg(i, f));
	return (0);
}

int			ft_printnbrpos(int i, t_struct *f)
{
	int		len;
	char	*s;

	s = ft_itoa(i);
	len = ft_strlen(s);
	if ((f->w != 0) && (f->p == -1) && ((f->w) > len))
		len = widthnbrb(f, i);
	else if ((f->w != 0) && (f->p != -1) && ((f->w) > len))
		len = widthnbrp(f, i);
	else if ((f->w == 0) && (f->p != -1) && ((f->p) > len))
		len = widthnbrdb(f, i);
	else if ((f->w != 0) && (f->p != -1) && (f->p > len))
		len = widthnbrdb2(f, i);
	else
		len = widthnbrblast(i, f);
	free(s);
	return (len);
}

int			ft_printnbrneg(int i, t_struct *f)
{
	int		len;
	char	*s;

	s = ft_itoa(i);
	len = ft_strlen(s) - 1;
	f->minusint = -1;
	i = f->minusint * i;
	if ((f->w != 0) && (f->p == -1) && ((f->w) > len))
		len = widthnbrbneg(f, i);
	else if ((f->w != 0) && (f->p != -1) && (f->w > len))
		len = widthnbrpneg(f, i);
	else if ((f->w != 0) && (f->p != -1) && (f->p > len))
		len = widthnbrppneg(f, i);
	else if ((f->w == 0) && (f->p != -1) && ((f->p) > len))
		len = widthnbrdbneg(f, i);
	else
		len = widthnbrblastneg(i);
	free(s);
	return (len);
}
