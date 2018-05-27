/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2_p3_format2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 20:09:13 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/20 20:09:18 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf2(char *tm, char *f, va_list arg, t_pm **pm)
{
	int		t;
	int		i;
	char	*cur;

	t = 0;
	cur = ft_memalloc(sizeof(char) * ft_strlen(tm) + 1);
	ft_memcpy(cur, tm, ft_strlen(tm));
	write_in_bf_c('%');
	while (cur[ret_i('+', -1)])
		f[t++] = cur[ret_i(0, -1)];
	i = ret_i(0, -1);
	if (has_type(cur) == 1)
		ft_printf0(f, arg, pm);
	else
		ft_printf0(f, NULL, pm);
	free(cur);
	return (i);
}

int		ft_printf3(char *tm, int i, char **f)
{
	int k;
	int t;

	k = check_format(tm[i]);
	t = 0;
	while (k == 0 && tm[i])
	{
		(*f)[t++] = tm[i++];
		k = check_format(tm[i]);
	}
	if (k == 2 && tm[i])
		(*f)[t++] = tm[i++];
	while (k == 1 && tm[i] && tm[i] != '%')
	{
		(*f)[t++] = tm[i++];
		k = check_format(tm[i]);
	}
	if (tm[i] == '%' && tm[i + 1] == '\0')
		(*f)[t++] = tm[i++];
	(*f)[t] = '\0';
	return (i);
}

int		check_size(char *format, t_pm **pm)
{
	(*pm)->sz[0] = 0;
	(*pm)->sz[1] = 0;
	if (f_ch(format, 'l', 'l') == 1)
	{
		(*pm)->sz[0] = 'l';
		(*pm)->sz[1] = 'l';
	}
	else if (f_ch(format, 'l', '\0') == 1)
		(*pm)->sz[0] = 'l';
	else if (f_ch(format, 'z', '\0') == 1)
		(*pm)->sz[0] = 'z';
	else if (f_ch(format, 'j', '\0') == 1)
		(*pm)->sz[0] = 'j';
	else
		check_size2(format, pm);
	if ((*pm)->sz[1] != 'l' && (*pm)->sz[1] != 'h')
		(*pm)->sz[1] = '\0';
	if ((*pm)->sz[0])
		return (1);
	return (0);
}

void	check_size2(char *format, t_pm **pm)
{
	if (f_ch(format, 't', '\0') == 1)
		(*pm)->sz[0] = 't';
	else if (f_ch(format, 'L', '\0') == 1)
		(*pm)->sz[0] = 'L';
	else if (f_ch(format, 'h', 'h') == 1)
	{
		(*pm)->sz[0] = 'h';
		(*pm)->sz[1] = 'h';
	}
	else if (f_ch(format, 'h', '\0') == 1)
		(*pm)->sz[0] = 'h';
}
