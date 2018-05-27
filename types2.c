/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:56:49 by akotilie          #+#    #+#             */
/*   Updated: 2018/03/05 13:23:17 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

char	*print_uox2(t_pm **pm, va_list arg, uintmax_t i)
{
	char	*res;

	if ((*pm)->sz[0] == 'l' && (*pm)->sz[1] == 'l')
		i = (unsigned long long int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'l' && (*pm)->sz[1] == 0)
		i = (unsigned long int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'j')
		i = (long long int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'z')
		i = (size_t)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 't')
		i = (ptrdiff_t)(va_arg(arg, void *));
	if ((*pm)->tp == 'o' || (*pm)->tp == 'O')
		res = uint_itoa(i, 8, (*pm)->tp);
	if ((*pm)->tp == 'x' || (*pm)->tp == 'X')
		res = uint_itoa(i, 16, (*pm)->tp);
	if ((*pm)->tp == 'u')
		res = uint_itoa(i, 10, (*pm)->tp);
	return (res);
}

char	*print_u(t_pm **pm, va_list arg)
{
	uintmax_t	i;
	char		*res;

	i = (unsigned long)(va_arg(arg, void *));
	(*pm)->tp = 'u';
	res = uint_itoa(i, 10, (*pm)->tp);
	return (res);
}

char	*print_d(t_pm **pm, va_list arg)
{
	char		*res;
	long int	i;

	i = va_arg(arg, long int);
	(*pm)->tp = 'd';
	res = int_itoa(i, 10);
	return (res);
}
