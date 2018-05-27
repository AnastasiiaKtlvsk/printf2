/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fl2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:29:01 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/26 15:29:05 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_0(t_pm **pm, char **str, int len)
{
	char	*cur;

	if ((int)ft_strlen(*str) < (*pm)->wd && ((*pm)->pr < 0 || ((*pm)->pr <
		(*pm)->wd && (*pm)->wd > 0 && (*pm)->pr > 0 && (*str)[0] == '-')))
	{
		if (((*str)[0] == '-') || ((*str)[0] == '+'))
			return (process_01(pm, str, len));
		else if (((*pm)->tp == 'x' && (*pm)->fl[0] == '#') || ((*str)[0] == 'X'
			&& (*pm)->fl[0] == '#') || ((*pm)->fl[1] == ' ' && ((*pm)->tp == 'i'
				|| (*pm)->tp == 'd')))
			return (process_02(pm, str, len));
		else
		{
			cur = insert_in_front(str, '0', ((*pm)->wd - len));
			*str = cur;
		}
	}
	else if (((*pm)->tp == 's' || (*pm)->tp == 'c') && (*pm)->wd > len)
	{
		cur = insert_in_front(str, '0', ((*pm)->wd - len));
		*str = cur;
	}
	return (*str);
}

char	*process_01(t_pm **pm, char **str, int len)
{
	char *tm;

	if ((*str)[0] == '-')
	{
		tm = *str;
		*str = ft_strdup(ft_strchr(tm, '-') + 1);
		free(tm);
		*str = insert_in_front(str, '0', ((*pm)->wd - len));
		*str = insert_in_front(str, '-', 1);
	}
	else if ((*str)[0] == '+')
	{
		tm = *str;
		*str = ft_strdup(ft_strchr(tm, '+') + 1);
		free(tm);
		*str = insert_in_front(str, '0', ((*pm)->wd - len));
		*str = insert_in_front(str, '+', 1);
	}
	return (*str);
}

char	*process_02(t_pm **pm, char **str, int len)
{
	if ((*pm)->tp == 'x' && (*pm)->fl[0] == '#')
	{
		*str = insert_in_front(str, '0', ((*pm)->wd - len - 2));
		*str = insert_in_front(str, 'x', 1);
		*str = insert_in_front(str, '0', 1);
	}
	else if ((*str)[0] == 'X' && (*pm)->fl[0] == '#')
	{
		*str = insert_in_front(str, '0', ((*pm)->wd - len - 2));
		*str = insert_in_front(str, 'X', 1);
		*str = insert_in_front(str, '0', 1);
	}
	else if ((*pm)->fl[1] == ' ' && ((*pm)->tp == 'i' || (*pm)->tp == 'd'))
	{
		*str = insert_in_front(str, '0', ((*pm)->wd - len - 1));
		*str = insert_in_front(str, ' ', 1);
	}
	return (*str);
}

char	*process_wd(t_pm **pm, char **str, int len)
{
	char *tm;

	if (len < (*pm)->wd && (*pm)->fl[2] != '-')
	{
		if (((*pm)->tp == 'x' || (*str)[0] == 'X') && (*pm)->fl[0] == '#'
				&& (*pm)->fl[2] != '0' && ft_atoi(*str))
		{
			((*pm)->tp == 'x') ? tm = insert_in_front(str, 'x', 1) : 0;
			((*str)[0] == 'X') ? tm = insert_in_front(str, 'X', 1) : 0;
			*str = tm;
			tm = insert_in_front(str, '0', 1);
			*str = tm;
			tm = insert_in_front(str, ' ', ((*pm)->wd - len - 2));
		}
		else
			tm = insert_in_front(str, ' ', ((*pm)->wd - len));
		*str = tm;
	}
	else if (len < (*pm)->wd && (*pm)->fl[2] == '-')
	{
		tm = insert_in_back(str, ' ', ((*pm)->wd - len));
		*str = tm;
	}
	return (*str);
}
