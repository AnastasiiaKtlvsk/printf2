/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:22:51 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/26 17:29:06 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_itoa(intmax_t num, int base)
{
	int			count;
	intmax_t	nbr_len;
	char		*res;
	int			fl;

	count = 1;
	fl = 0;
	if (num == -9223372036854775807 - 1)
	{
		res = ft_strdup("-9223372036854775808\0");
		return (res);
	}
	else
	{
		if (num < 0)
		{
			count++;
			fl = 1;
			num *= (-1);
		}
		nbr_len = num;
		while ((nbr_len = nbr_len / base) != 0)
			count++;
		return (int_itoa2(num, base, count, fl));
	}
}

char	*int_itoa2(intmax_t num, int base, int count, int fl)
{
	char	*d;

	d = ft_memalloc(sizeof(char) * count + 1);
	while (--count > -1)
	{
		d[count] = (num % base > 9) ? num % base - 10 + 'A' : num % base + '0';
		num = num / base;
	}
	if (fl == 1)
		d[0] = '-';
	return (d);
}

char	*uint_itoa(uintmax_t num, int base, char type)
{
	int			count;
	char		*d;
	uintmax_t	nbr_len;
	int			b;

	count = 1;
	b = base;
	nbr_len = num;
	while ((nbr_len = nbr_len / base) != 0)
		count++;
	d = (char *)ft_memalloc(sizeof(char) * count + 1);
	while (--count > -1)
	{
		if (type == 'X')
			d[count] = (num % b > 9) ? num % b - 10 + 'A' : num % b + '0';
		else
			d[count] = (num % b > 9) ? num % b - 10 + 'a' : num % b + '0';
		num = num / b;
	}
	return (d);
}
