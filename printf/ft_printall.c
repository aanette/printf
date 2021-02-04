/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:16:14 by aanette           #+#    #+#             */
/*   Updated: 2021/01/21 20:44:28 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printprobel(int k)
{
	while (k != 0)
	{
		write(1, " ", 1);
		k--;
	}
}

void	printres(int i)
{
	char *s;

	s = ft_itoa(i);
	write(1, s, ft_strlen(s));
	free(s);
}

void	printres1(unsigned int i)
{
	char *s;

	s = ft_itoa_u(i);
	write(1, s, ft_strlen(s));
	free(s);
}

void	printres16(t_struct *f, unsigned int i)
{
	char *s;

	s = ft_itoa_base(f, i);
	write(1, s, ft_strlen(s));
	free(s);
}

void	printres16p(unsigned long long i)
{
	char *s;

	s = ft_itoa_basep(i);
	write(1, s, ft_strlen(s));
	free(s);
}
