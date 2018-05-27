/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:28:45 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/26 15:28:51 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_fls(t_pm **pm, char **str)
{
	if ((*pm)->fl[0] == '#')
		*str = process_sharp(pm, str);
	if ((*pm)->fl[1] == '+')
		*str = process_plus(pm, str);
	if ((*pm)->fl[2] == '-')
		*str = process_minus(pm, str);
	if ((*pm)->fl[1] == ' ' && ((*pm)->tp == 'i' || (*pm)->tp == 'd'))
		*str = process_space(pm, str);
	if ((*pm)->fl[2] == '0')
		*str = process_0(pm, str, ft_strlen(*str));
	return (*str);
}

char	*insert_in_front(char **str, char c, int count)
{
	int		length;
	char	*newstr;
	int		in;
	int		i;

	length = ft_strlen(*str);
	i = -1;
	in = -1;
	newstr = ft_memalloc(sizeof(char) * (count + length + 1));
	while (count-- > 0)
		newstr[++in] = c;
	while (length-- > 0)
		newstr[++in] = (*str)[++i];
	newstr[++in] = '\0';
	if (str && ft_strcmp((*str), "9223372036854775807") != 0)
		free(*str);
	return (newstr);
}

char	*insert_in_back(char **str, char c, int count)
{
	int		length;
	char	*newstr;
	int		in;
	int		i;

	length = ft_strlen(*str);
	i = -1;
	in = -1;
	newstr = ft_memalloc(sizeof(char) * (count + length + 1));
	while (length-- > 0)
		newstr[++in] = (*str)[++i];
	while (count-- > 0)
		newstr[++in] = c;
	newstr[++in] = '\0';
	if (*str && ft_strcmp((*str), "9223372036854775807") != 0)
		free(*str);
	return (newstr);
}
