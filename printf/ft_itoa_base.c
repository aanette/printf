/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:45:17 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_l(unsigned int nbr)
{
	int l;

	l = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		l++;
	}
	return (l);
}

static char		ft_s(t_struct *f, int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	else if (nbr >= 0 && nbr < 10)
		return (nbr + '0');
	else if (f->type == 3)
		return (nbr - 10 + 'A');
	else if (f->type == 4)
		return (nbr - 10 + 'a');
	return ('0');
}

char			*ft_itoa_base(t_struct *f, unsigned int n)
{
	char	*str;
	int		k;

	k = 0;
	k = ft_l(n);
	str = (char *)malloc(sizeof(char) * (k + 1));
	str[k] = '\0';
	while (k != 0)
	{
		str[--k] = ft_s(f, ((int)(n % 16)));
		n = n / 16;
	}
	return (str);
}

int				widthnbrb16(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_base(f, i);
	k = f->w - ft_strlen(s);
	if ((f->zero == 0) && (f->minus == 0))
	{
		printprobel(k);
		printres16(f, i);
	}
	else if ((f->zero == 1) && (f->minus == 0))
		widthzero16(f, i);
	else if (f->minus == 1)
	{
		printres16(f, i);
		printprobel(k);
	}
	free(s);
	return (f->w);
}

int				widthnbrd16(t_struct *f, unsigned int i)
{
	char	*str;

	str = ft_itoa_base(f, i);
	if (!str)
		return (-1);
	if (f->minus == 0)
	{
		printnull(f->p - ft_strlen(str));
		printres16(f, i);
	}
	else if (f->minus == 1)
	{
		printres16(f, i);
		printprobel(f->p - ft_strlen(str));
	}
	free(str);
	return (f->p);
}
