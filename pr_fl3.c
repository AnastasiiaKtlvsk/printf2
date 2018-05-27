/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_fl3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:29:10 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/26 15:29:23 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_space(t_pm **pm, char **str)
{
	char *tm;

	if ((*str)[0] != '-' && (*pm)->fl[2] != '0')
	{
		tm = insert_in_front(str, ' ', 1);
		*str = tm;
	}
	return (*str);
}

char	*process_minus(t_pm **pm, char **str)
{
	char *tm;

	if ((int)ft_strlen(*str) < (*pm)->wd && (*pm)->fl[0] == '#' &&
			((*pm)->tp == 'x' || (*pm)->tp == 'X'))
	{
		tm = insert_in_back(str, ' ', (*pm)->wd - ft_strlen(*str) - 2);
		*str = tm;
	}
	else if ((int)ft_strlen(*str) < (*pm)->wd && (*pm)->fl[0] == '#'
		&& (*pm)->tp == 'o')
	{
		tm = insert_in_back(str, ' ', (*pm)->wd - ft_strlen(*str) - 1);
		*str = tm;
	}
	else if ((int)ft_strlen(*str) < (*pm)->wd && (*pm)->fl[0] != '#')
	{
		tm = insert_in_back(str, ' ', ((*pm)->wd - ft_strlen(*str)));
		*str = tm;
	}
	return (*str);
}

char	*process_plus(t_pm **pm, char **str)
{
	char *tm;

	if ((*pm)->tp == 'd' || (*pm)->tp == 'i')
	{
		if ((*str)[0] != '-')
		{
			tm = insert_in_front(str, '+', 1);
			*str = tm;
		}
	}
	return (*str);
}

char	*process_sharp(t_pm **pm, char **s)
{
	char *tm;

	if ((*pm)->fl[2] != '0' && ((int)ft_strlen(*s) >= (*pm)->wd ||
	((int)ft_strlen(*s) < (*pm)->wd && (*pm)->fl[2] == '-'))
		&& ft_atoi(*s) != 0)
	{
		if ((*pm)->tp == 'x' && ft_atoi(*s) != 0)
		{
			tm = insert_in_front(s, 'x', 1);
			*s = tm;
			tm = insert_in_front(s, '0', 1);
			*s = tm;
		}
		if ((*pm)->tp == 'X' && ft_atoi(*s) != 0)
		{
			tm = insert_in_front(s, 'X', 1);
			*s = tm;
			tm = insert_in_front(s, '0', 1);
			*s = tm;
		}
	}
	return (process_sharp2(pm, s));
}

char	*process_sharp2(t_pm **pm, char **str)
{
	char *tm;

	if (((*pm)->tp == 'O' || (*pm)->tp == 'o') && ft_atoi(*str) != 0)
	{
		tm = insert_in_front(str, '0', 1);
		*str = tm;
	}
	return (*str);
}
