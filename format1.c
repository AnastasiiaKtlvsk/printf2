/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:57:27 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/20 19:57:33 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		choose_format(char *format, va_list arg, t_pm **pm)
{
	int		form;
	char	*f;

	f = ft_memalloc(sizeof(char) * ft_strlen(format) + 1);
	ft_strcpy(f, format);
	form = 0;
	if (check_fls(f, pm) == 1)
		form++;
	if (check_wd(f, pm, arg, 0) == 1)
		form++;
	if (check_pr(f, pm, arg) == 1)
		form++;
	if (check_size(f, pm) == 1)
		form++;
	ft_strcpy(format, f);
	free(f);
	(*pm)->tp = 0;
	return (form);
}

int		check_fls(char *format, t_pm **pm)
{
	char	*f;
	int		i;
	char	*tm;

	f = format;
	i = 0;
	(*pm)->fl[0] = 0;
	(*pm)->fl[1] = 0;
	(*pm)->fl[2] = 0;
	(f_ch(f, '#', '\0') == 1) ? (*pm)->fl[0] = '#' : 0;
	while (f[i] && f[i] != ' ')
		i++;
	(f[i] == ' ' && f[i + 1] != ' ') ? (*pm)->fl[1] = ' ' : 0;
	(f_ch(f, '+', '\0') == 1) ? (*pm)->fl[1] = '+' : 0;
	if (f_ch(f, '0', '\0') == 1)
		if (f_ch(f, '.', '0') == 0)
		{
			tm = ft_strchr(format, '0') - 1;
			(tm[0] < 48 || tm[0] > 56) ? (*pm)->fl[2] = '0' : 0;
		}
	(f_ch(f, '-', '\0') == 1) ? (*pm)->fl[2] = '-' : 0;
	if ((*pm)->fl[0] != 0 || (*pm)->fl[1] != 0 || (*pm)->fl[2] != 0)
		return (1);
	return (0);
}

int		check_wd(char *f, t_pm **pm, va_list arg, int i)
{
	int		ni;
	char	n[11];

	ni = 0;
	(*pm)->wd = 0;
	while ((f[i] < '1' || f[i] > '9') && f[i] != '\0' && f[i] != '*')
		i++;
	if (f[i - 1] != '.')
	{
		if (f[i] == '*')
		{
			(*pm)->wd = (int)(va_arg(arg, void *));
			((*pm)->wd < 0) ? (*pm)->wd *= -1 : 0;
			((*pm)->wd < 0) ? (*pm)->fl[2] = '-' : 0;
		}
		else
		{
			while (f[i] > 47 && f[i] < 58)
				n[ni++] = f[i++];
			n[ni] = '\0';
			(*pm)->wd = ft_atoi(n);
		}
	}
	return ((*pm)->wd != 0) ? 1 : 0;
}

int		check_pr(char *format, t_pm **pm, va_list arg)
{
	int		i;

	i = 0;
	(*pm)->pr = -1;
	while (format[i] != '.' && format[i] != '\0')
		i++;
	if (format[i] == '.')
	{
		(*pm)->pr = 0;
		check_pr2(format, pm, arg, i);
		return (1);
	}
	return (0);
}

int		check_pr2(char *format, t_pm **pm, va_list arg, int i)
{
	int		ni;
	char	n[11];

	ni = -1;
	if (format[i + 1] == '*')
	{
		(*pm)->pr = (int)(va_arg(arg, void *));
		if ((*pm)->pr < 0)
		{
			(*pm)->pr *= -1;
			(*pm)->fl[2] = '-';
		}
	}
	else
	{
		while (format[++i] > 47 && format[i] < 58)
			n[++ni] = format[i];
		n[++ni] = '\0';
		(*pm)->pr = ft_atoi(n);
	}
	return (1);
}
