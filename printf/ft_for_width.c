/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:27:50 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 06:52:14 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printzero(t_struct *f)
{
	if (f->w == 0)
		write(1, 0, 1);
	else
		printprobel(f->w);
	return (f->w);
}

int	widthnbrblast(int i, t_struct *f)
{
	char	*s;
	int		q;

	s = ft_itoa(i);
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

int	widthzero(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	k = f->w - ft_strlen(s);
	if (f->zero == 1)
		printnull(k);
	write(1, s, ft_strlen(s));
	free(s);
	return (f->w);
}

int	widthzero1(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_u(i);
	k = f->w - ft_strlen(s);
	if (f->zero == 1)
		printnull(k);
	write(1, s, ft_strlen(s));
	free(s);
	return (f->w);
}

int	widthzeroneg(t_struct *f, int i)
{
	int		k;
	char	*s;

	s = ft_itoa(i);
	k = f->w - ft_strlen(s) - 1;
	if (f->zero == 1)
		printnull(k);
	write(1, s, ft_strlen(s));
	free(s);
	return (f->w);
}
