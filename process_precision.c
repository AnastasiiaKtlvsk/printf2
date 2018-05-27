/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:56:39 by akotilie          #+#    #+#             */
/*   Updated: 2018/03/02 14:56:41 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_pr(t_pm **pm, char **str)
{
	char	*t1;
	char	*t2;

	if ((*pm)->pr == 0 && !((*pm)->tp == 'o' && (*pm)->fl[0] == '#')
		&& ft_strcmp(*str, "0") == 0)
	{
		t1 = *str;
		*str = ft_memalloc(sizeof(char) * 1);
		free(t1);
	}
	if ((*pm)->tp == 's' && (*pm)->pr < (int)ft_strlen(*str) &&
		(*pm)->pr > -1)
	{
		t1 = *str;
		t2 = ft_memalloc(sizeof(char) * (*pm)->pr + 1);
		ft_strncpy(t2, t1, (size_t)(*pm)->pr);
		*str = t2;
		free(t1);
	}
	if ((*pm)->tp != 's' && (*pm)->tp != 'c' && (int)ft_strlen(*str) < (*pm)->pr
		&& (*pm)->pr > 0)
		return (process_pr2(pm, str));
	return (*str);
}

char	*process_pr2(t_pm **pm, char **str)
{
	char	*t1;
	char	*tm;
	int		number;

	number = (*pm)->pr - ft_strlen(*str);
	if ((*pm)->fl[0] == '#' && ((*pm)->tp == 'o' || (*pm)->tp == 'O'))
		(*pm)->pr--;
	if ((*str)[0] != '-' && number > 0)
	{
		tm = insert_in_front(str, '0', ((*pm)->pr - ft_strlen(*str)));
		*str = tm;
	}
	else if ((*str)[0] == '-' && ft_strcmp((*str), "-9223372036854775808") != 0)
	{
		t1 = *str;
		*str = ft_strdup(ft_strchr(*str, '-') + 1);
		free(t1);
		tm = insert_in_front(str, '0', ((*pm)->pr - ft_strlen(*str)));
		*str = tm;
		tm = insert_in_front(str, '-', 1);
		*str = tm;
	}
	return (*str);
}
