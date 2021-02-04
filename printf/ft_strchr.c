/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:50:22 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 06:34:56 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (((char*)s)[i] == ((char)c))
			return (&((char*)s)[i]);
		i++;
	}
	if (((char)c) == '\0')
		return (&((char*)s)[i]);
	return (0);
}

void	ft_printcut(char *s, int i, t_struct *f)
{
	int j;

	j = 0;
	if (f->p > ((int)ft_strlen(s)))
		i = ft_strlen(s);
	if (s)
	{
		while (j != i)
		{
			write(1, &s[j], 1);
			j++;
		}
	}
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	k;
	char			*su;

	i = 0;
	if (!s)
		return (NULL);
	k = ft_strlen(s);
	if (!(su = (char*)(malloc(sizeof(char) * (k - start)))))
		return (NULL);
	if (start >= k)
	{
		su[i] = '\0';
		return (su);
	}
	while (i < len)
	{
		su[i] = s[start + i];
		i++;
	}
	su[i] = '\0';
	return (su);
}
