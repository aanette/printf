/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 22:45:43 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:30:46 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_l2(unsigned long long nbr)
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

static char		ft_s(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	else if (nbr >= 0 && nbr < 10)
		return (nbr + '0');
	else
		return (nbr - 10 + 'a');
	return ('0');
}

char			*ft_itoa_basep(unsigned long long n)
{
	char	*str;
	int		k;

	k = 0;
	k = ft_l2(n) + 2;
	str = (char *)malloc(sizeof(char) * (k + 1));
	str[k] = '\0';
	while (k != 2)
	{
		str[--k] = ft_s(((int)(n % 16)));
		n = n / 16;
	}
	str[1] = 120;
	str[0] = 48;
	return (str);
}

int				widthnbrd16p(t_struct *f, unsigned long long i)
{
	char	*str;

	str = ft_itoa_basep(i);
	if (!str)
		return (-1);
	if (f->minus == 0)
	{
		printnull(f->p - ft_strlen(str));
		printres16p(i);
	}
	else if (f->minus == 1)
	{
		printres16p(i);
		printprobel(f->p - ft_strlen(str));
	}
	free(str);
	return (f->p);
}

int				widthnbrp16p(t_struct *f, unsigned long long i)
{
	if ((i == 0) && (f->p == 0))
		return (printzero(f));
	if (f->minus == 0)
	{
		if (f->w > f->p)
		{
			p1(f, i);
			return (f->w);
		}
		else if (f->w <= f->p)
		{
			printprec16p(f, i);
			return (f->w + ft_strlen(ft_itoa_basep(i)));
		}
	}
	else
	{
		if (f->w > f->p)
		{
			p2(f, i);
			return (f->w);
		}
	}
	return (f->p);
}
