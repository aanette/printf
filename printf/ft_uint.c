/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:33:26 by aanette           #+#    #+#             */
/*   Updated: 2021/01/21 22:22:14 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printnbru(va_list ap, t_struct *f)
{
	unsigned int	i;
	int				len;
	char			*s;

	i = va_arg(ap, unsigned int);
	s = ft_itoa_u(i);
	len = ft_strlen(s);
	if ((f->w != 0) && (f->p == -1) && ((f->w) > len))
		len = widthnbrb1(f, i);
	else if ((f->w != 0) && (f->p != -1) && ((f->w) > len))
		len = widthnbrp1(f, i);
	else if ((f->w == 0) && (f->p != -1) && ((f->p) > len))
		len = widthnbrdb1(f, i);
	else if ((f->w != 0) && (f->p != -1) && (f->p > len))
		len = widthnbrdb1(f, i);
	else
		len = widthnbrblast1(i, f);
	free(s);
	return (len);
}

void		printprec1(t_struct *f, unsigned int i)
{
	int		k;
	char	*s;

	s = ft_itoa_u(i);
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

static int	ft_l_u(unsigned int nbr)
{
	int l;

	l = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		l++;
	}
	return (l);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*s;
	int		k;

	k = ft_l_u(n);
	s = (char*)(malloc(sizeof(char) * (k + 1)));
	if (!s)
		return (NULL);
	s[k] = '\0';
	k--;
	while (k >= 0)
	{
		s[k] = '0' + (n % 10);
		n = (n / 10);
		k--;
	}
	return (s);
}
