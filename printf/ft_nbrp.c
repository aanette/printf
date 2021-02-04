/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 07:09:58 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 01:47:29 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printnbrx(va_list ap, t_struct *f)
{
	unsigned int	i;
	int				len;
	char			*s;

	i = va_arg(ap, unsigned int);
	s = ft_itoa_base(f, i);
	len = ft_strlen(s);
	if ((f->w != 0) && (f->p == -1) && ((f->w) > len))
		len = widthnbrb16(f, i);
	else if ((f->w != 0) && (f->p != -1) && ((f->w) > len))
		len = widthnbrp16(f, i);
	else if ((f->w == 0) && (f->p != -1) && ((f->p) > len))
		len = widthnbrdb16(f, i);
	else if ((f->w != 0) && (f->p != -1) && (f->p > len))
		len = widthnbrdb16(f, i);
	else
		len = widthnbrblast16(i, f);
	free(s);
	return (len);
}

int		ft_printnbrp(va_list ap, t_struct *f)
{
	unsigned long long	i;
	int					len;
	char				*s;

	i = va_arg(ap, unsigned long long);
	s = ft_itoa_basep(i);
	len = ft_strlen(s);
	if ((f->w != 0) && (f->p == -1) && ((f->w) > len))
		len = widthnbrb16p(f, i);
	else if ((f->w != 0) && (f->p != -1) && ((f->w) > len))
		len = widthnbrp16p(f, i);
	else if ((f->w == 0) && (f->p != -1) && ((f->p) > len))
		len = widthnbrdb16p(f, i);
	else if ((f->w != 0) && (f->p != -1) && (f->p > len))
		len = widthnbrdb16p(f, i);
	else
		len = widthnbrblast16p(i, f);
	free(s);
	return (len);
}

int		widthnbrblast16p(unsigned long long i, t_struct *f)
{
	char	*s;
	int		q;

	if ((i == 0) && (f->p == 0))
		return (printzero(f));
	s = ft_itoa_basep(i);
	q = ft_strlen(s);
	write(1, s, ft_strlen(s));
	free(s);
	return (q);
}

int		widthzero16p(t_struct *f, unsigned long long i)
{
	int		k;
	char	*s;

	s = ft_itoa_basep(i);
	k = f->w - ft_strlen(s);
	if (f->zero == 1)
		printnull(k);
	write(1, s, ft_strlen(s));
	free(s);
	return (f->w);
}

int		widthnbrdb16p(t_struct *f, unsigned long long i)
{
	int k;

	k = f->p - ft_strlen(ft_itoa_basep(i));
	if (f->minus == 0)
	{
		printnull(k);
		printres16p(i);
	}
	else if (f->minus == 1)
	{
		printprec16p(f, i);
	}
	return (f->p);
}
