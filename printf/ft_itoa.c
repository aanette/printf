/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:57:05 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 06:42:19 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int	ft_s(long int nbr)
{
	if (nbr >= 0)
		return (nbr);
	else
		return (-nbr);
}

static int		ft_l(long int nbr)
{
	int l;

	if (nbr <= 0)
		l = 1;
	else
		l = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		l++;
	}
	return (l);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		k;
	int		i;

	i = (n >= 0) ? 1 : -1;
	k = ft_l(n);
	if (n == -2147483648)
	{
		s = ft_strdup("2147483648");
		return (s);
	}
	if (!(s = (char*)(malloc(sizeof(char) * (k + 1)))))
		return (NULL);
	s[k] = '\0';
	k--;
	while (k >= 0)
	{
		s[k] = '0' + ft_s(n % 10);
		n = ft_s(n / 10);
		k--;
	}
	if (i == -1)
		s[0] = '-';
	return (s);
}
