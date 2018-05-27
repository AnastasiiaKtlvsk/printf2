/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr2_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:03:56 by akotilie          #+#    #+#             */
/*   Updated: 2018/03/05 13:23:54 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fr(char *f, t_pm **pm)
{
	(f_ch(f, 'd', '\0') || f_ch(f, 'D', '\0')) ? (*pm)->tp = 'd' : 0;
	(f_ch(f, 'i', '\0')) ? (*pm)->tp = 'i' : 0;
	(f_ch(f, 'o', '\0')) ? (*pm)->tp = 'o' : 0;
	(f_ch(f, 'O', '\0')) ? (*pm)->tp = 'O' : 0;
	(f_ch(f, 'x', '\0')) ? (*pm)->tp = 'x' : 0;
	(f_ch(f, 'X', '\0')) ? (*pm)->tp = 'X' : 0;
	(f_ch(f, 'u', '\0')) ? (*pm)->tp = 'u' : 0;
	(f_ch(f, 'U', '\0')) ? (*pm)->tp = 'U' : 0;
	(f_ch(f, 'D', '\0')) ? (*pm)->tp = 'D' : 0;
}

char	**co(t_pm **pm, va_list a, char **s)
{
	char *tm;

	((*pm)->tp == 'd' || (*pm)->tp == 'i') ? (tm = print_di(pm, a)) : 0;
	((*pm)->tp == 'u' || (*pm)->tp == 'o' || (*pm)->tp == 'x' ||
	(*pm)->tp == 'X' || (*pm)->tp == 'O') ? (tm = print_uox(pm, a)) : 0;
	((*pm)->tp == 'U') ? (tm = print_u(pm, a)) : 0;
	((*pm)->tp == 'D') ? (tm = print_d(pm, a)) : 0;
	((*pm)->tp == 0) ? (tm = NULL) : 0;
	*s = tm;
	return (s);
}

char	**process(char *f, t_pm **pm, char **s)
{
	char *tm;

	tm = process_pr(pm, s);
	*s = tm;
	tm = process_fls(pm, s);
	*s = tm;
	tm = process_wd(pm, s, ft_strlen(*s));
	*s = tm;
	if (f_ch(f, 'p', '\0') == 1)
	{
		if ((*pm)->pr > 0 && (*pm)->wd == 0)
		{
			tm = insert_in_front(s, 'x', 1);
			*s = tm;
			tm = insert_in_front(s, '0', 1);
			*s = tm;
		}
	}
	write_in_bf_s(s);
	return (s);
}

int		choose_type(char *f, t_pm **pm, va_list arg)
{
	char *tm;
	char **s;

	s = &tm;
	(f_ch(f, 's', '\0')) ? (s = sff(pm, arg, s)) : 0;
	(f_ch(f, 'c', '\0')) ? (s = cf(pm, arg, s)) : 0;
	(f_ch(f, 'C', '\0') || (*pm)->tp == 'C') ? (s = Сf(pm, arg, s)) : 0;
	(f_ch(f, 'S', '\0') || (*pm)->tp == 'S') ? (s = sff2(pm, arg, s)) : 0;
	if (s < (char **)200)
		return ((int)s);
	(f_ch(f, 'p', '\0') == 1) ? pf(pm) : 0;
	((*pm)->tp == 0) ? fr(f, pm) : 0;
	((*pm)->tp != 's' && (*pm)->tp != 'c' && (*pm)->tp != 'S' &&
	(*pm)->tp != 'C') ? (s = co(pm, arg, s)) : 0;
	if (*s)
	{
		(f_ch(f, 'p', '\0')) ? (s = pf2(pm, s)) : 0;
		s = process(f, pm, s);
		free(*s);
	}
	return (0);
}

void	reallocate(char **line, int add_size)
{
	char			*newline;
	int				size;

	size = ft_strlen(*line);
	newline = (char*)ft_memalloc(sizeof(char) * (size + add_size + 1));
	ft_memcpy(newline, line, size);
	*line = newline;
}
