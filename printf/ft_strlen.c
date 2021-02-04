/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:49:57 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:34:54 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		k;
	char	*str2;

	i = 0;
	k = 0;
	while (str[k] != '\0')
		k++;
	str2 = (char*)(malloc(sizeof(char) * (k + 1)));
	if (!str2)
		return (NULL);
	while (i != k)
	{
		str2[i] = str[i];
		i++;
	}
	str2[k] = '\0';
	return (str2);
}
