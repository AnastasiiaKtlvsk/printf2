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

char	**pf2(t_pm **pm, char **s)
{
	if ((*pm)->pr == 0)
	{
		*s = ft_memalloc(sizeof(char) * 1);
		(*pm)->pr = -1;
	}
	if (((*pm)->wd < (int)ft_strlen(*s) && (*pm)->pr == -1) ||
		((*pm)->pr == -1 && (*pm)->fl[2] != '0'))
	{
		*s = insert_in_front(s, 'x', 1);
		*s = insert_in_front(s, '0', 1);
	}
	else
		(*pm)->fl[0] = '#';
	return (s);
}

char	*print_string(va_list arg)
{
	char	*res;
	char	*s;

	s = (char*)va_arg(arg, void*);
	if (s == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(s);
	return (res);
}

char	*print_char(va_list arg)
{
	char	*res;
	int		c;

	c = va_arg(arg, int);
	if (c == 0)
		return (NULL);
	res = ft_memalloc(sizeof(char) * 2);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*print_di(t_pm **pm, va_list arg)
{
	intmax_t	i;
	char		*res;

	i = 0;
	if ((*pm)->sz[0] == 0)
		i = (int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'h' && (*pm)->sz[1] == 'h')
		i = (char)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'h' && (*pm)->sz[1] == 0)
		i = (short int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'l' && (*pm)->sz[1] == 'l')
		i = (long long int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'l' && (*pm)->sz[1] == 0)
		i = (long int)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'j')
		i = (intmax_t)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'z')
		i = (size_t)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 't')
		i = (ptrdiff_t)(va_arg(arg, void *));
	res = int_itoa(i, 10);
	return (res);
}

char	*print_uox(t_pm **pm, va_list arg)
{
	uintmax_t	i;

	i = 0;
	if ((*pm)->sz[0] == 0 || (((*pm)->sz[0] == 'h' && (*pm)->sz[1] == 'h')
		&& (*pm)->tp == 'O'))
	{
		if ((*pm)->tp == 'O')
			i = (unsigned long)(va_arg(arg, void *));
		else
			i = (unsigned int)(va_arg(arg, void *));
		((*pm)->tp == 'O') ? (*pm)->tp = 'o' : 0;
	}
	else if ((*pm)->sz[0] == 'h' && (*pm)->sz[1] == 'h')
		i = (unsigned char)(va_arg(arg, void *));
	else if ((*pm)->sz[0] == 'h' && (*pm)->sz[1] == 0)
	{
		if ((*pm)->tp == 'u')
		{
			i = (unsigned long)(va_arg(arg, void *));
			(i < 4294967296) ? i = (unsigned short int)i : 0;
		}
		else
			i = (unsigned short int)(va_arg(arg, void *));
	}
	return (print_uox2(pm, arg, i));
}
