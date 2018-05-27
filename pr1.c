/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:03:56 by akotilie          #+#    #+#             */
/*   Updated: 2018/03/05 13:23:54 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**sff(t_pm **pm, va_list a, char **s)
{
	(*pm)->tp = 's';
	if ((*pm)->sz[0] == 0)
		*s = print_string(a);
	else if ((*pm)->sz[0] == 'l')
		(*pm)->tp = 'S';
	return (s);
}

char	**cf(t_pm **pm, va_list a, char **s)
{
	char					*tm;
	unsigned long long int	c;

	c = 0;
	(*pm)->tp = 'c';
	if ((*pm)->sz[0] == 0)
	{
		if ((tm = print_char(a)) == NULL)
		{
			while (--(*pm)->wd > 0 && (*pm)->fl[2] == 0 && ++c)
				write_in_bf_c(' ');
			++(*pm)->wd;
			while (--(*pm)->wd > 0 && (*pm)->fl[2] == '0' && ++c)
				write_in_bf_c('0');
			write_in_bf_c(-1);
			return ((char **)5);
		}
		*s = tm;
	}
	else if ((*pm)->sz[0] == 'l')
		(*pm)->tp = 'C';
	return (s);
}

char	**Сf(t_pm **pm, va_list a, char **s)
{
	char *tm;

	(*pm)->tp = 'C';
	tm = print_cc(pm, a);
	*s = tm;
	if (ft_strcmp((*s), "-1") == 0)
		return ((char **)1);
	if (ft_strcmp((*s), "-2") == 0)
	{
		write_in_bf_c(-1);
		return ((char **)2);
	}
	return (s);
}

char	**sff2(t_pm **pm, va_list a, char **s)
{
	char *tm;

	(*pm)->tp = 'S';
	tm = print_ss(pm, a, 0, -1);
	if (ft_strcmp((*s), "-1") == 0)
		return ((char**)1);
	*s = tm;
	return (s);
}

void	pf(t_pm **pm)
{
	(*pm)->tp = 'x';
	(*pm)->sz[0] = 'l';
	(*pm)->sz[1] = '\0';
}
