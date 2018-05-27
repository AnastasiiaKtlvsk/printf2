/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:03:56 by akotilie          #+#    #+#             */
/*   Updated: 2018/03/05 13:23:54 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	char	*tm;
	char	*bf;
	int		res;
	va_list	arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	tm = ft_memalloc(sizeof(char) * ft_strlen(format) + 2);
	tm[ft_strlen(format)] = '\0';
	ft_memcpy(tm, format, ft_strlen(format));
	bf = ft_memalloc(sizeof(char) * BF_SIZE + 1);
	ret_buff((unsigned long long int)&bf);
	res = mediator(tm, arg);
	va_end(arg);
	free(tm);
	if (res == 1)
	{
		free(bf);
		return (-1);
	}
	res = ft_strlen(bf);
	ft_putstr(bf);
	free(bf);
	return (res);
}

int		mediator(char *tm, va_list arg)
{
	t_pm	*pm;
	int		r;

	pm = (t_pm*)ft_memalloc(sizeof(t_pm));
	pm->fl = ft_memalloc(sizeof(int) * 3);
	r = ft_printf0(tm, arg, &pm);
	if (pm)
	{
		free(pm);
		free(pm->fl);
	}
	return (r);
}

int		ft_printf0(char *tm, va_list arg, t_pm **pm)
{
	char	*f;
	int		r;

	ret_i(0, 0);
	f = ft_memalloc(sizeof(char) * ft_strlen(tm) + 1);
	while (tm[ret_i(0, -1)])
	{
		if ((ret_i(0, ft_printf1(tm, ret_i(0, -1)))) == -1)
		{
			free(f);
			return (0);
		}
		if (tm[ret_i(0, -1)] == '%')
		{
			r = printf01(tm, arg, pm, &f);
			(r == -5 || r == 1) ? free(f) : 0;
			if (r == -5 || r == 1)
				return (r);
		}
		else
			ret_i('+', -1);
	}
	free(f);
	return (r);
}

int		printf01(char *tm, va_list arg, t_pm **pm, char **f)
{
	int	r;

	r = 0;
	if (tm[ret_i('+', -1)])
	{
		if (tm[ret_i(0, -1)] == '%')
			ret_i(0, ft_printf2(tm, *f, arg, pm));
		else
		{
			ret_i(0, ft_printf3(tm, ret_i(0, -1), f));
			r = ft_printf4(pm, *f, tm, arg);
			if (r == -5 || r == 1)
				return (r);
		}
	}
	return (r);
}

int		ft_printf1(char *tm, int i)
{
	int		l;

	l = ft_strlen(tm);
	while (tm[i] != '%' && i < l)
		write_in_bf_c(tm[i++]);
	if (tm[i] == '\0')
		write_in_bf_c('\0');
	return (i);
}
