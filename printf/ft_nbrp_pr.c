/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrp_pr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 07:11:43 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 01:43:02 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printprec16p(t_struct *f, unsigned long long i)
{
	int		k;
	int		q;
	char	*s;

	s = ft_itoa_basep(i);
	q = ft_strlen(s);
	if (f->p < (int)(q))
		write(1, s, q);
	else if (f->w < ((int)(q)))
	{
		k = f->p - q;
		printnull(k);
		write(1, s, q);
	}
	else
	{
		write(1, s, q);
		printnull(f->w);
	}
	free(s);
}

int		widthnbrb16p(t_struct *f, unsigned long long i)
{
	int		k;
	char	*s;

	s = ft_itoa_basep(i);
	k = f->w - ft_strlen(s);
	if ((f->zero == 0) && (f->minus == 0))
	{
		printprobel(k);
		printres16p(i);
	}
	else if ((f->zero == 1) && (f->minus == 0))
		widthzero16p(f, i);
	else if (f->minus == 1)
	{
		printres16p(i);
		printprobel(k);
	}
	free(s);
	return (f->w);
}
