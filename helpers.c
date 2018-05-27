/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:32:19 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/20 19:32:27 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		has_type(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (check_format(s[i]) == 2)
			return (1);
	return (0);
}

void	write_in_bf_c(char c)
{
	int		i;
	char	**bf;

	bf = (char**)ret_buff(0);
	i = ft_strlen(*bf);
	if (i + 1 < BF_SIZE)
		(*bf)[i] = c;
	else
	{
		reallocate(bf, 1);
		(*bf)[i] = c;
	}
}

void	write_in_bf_s(char **s)
{
	int		i;
	int		is;
	char	**bf;

	bf = (char**)ret_buff(0);
	is = 0;
	i = ft_strlen(*bf);
	if (i < BF_SIZE - (int)ft_strlen(*s))
		ft_strcat((*bf), *s);
	else
	{
		reallocate(bf, (ft_strlen(*s) + 1));
		ft_strcat((*bf), *s);
	}
}

int		f_ch(char *s, char c1, char c2)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c1)
			if (c2 == '\0' || s[i + 1] == c2)
				return (1);
	return (0);
}

int		check_format(char c)
{
	if (c == 's' || c == 'S' || c == 'x' ||
		c == 'X' || c == 'o' || c == 'O' ||
		c == 'i' || c == 'c' || c == 'd' || c == 'D' ||
		c == 'p' || c == 'u' || c == 'U' || c == 'C')
		return (2);
	if (c != '-' && c != '+' && c != ' ' && c != '0' && c != '#' &&
		c != '.' && !(c > 47 && c < 58) && c != 'l' && c != 'h' &&
		c != 'j' && c != 'z' && c != 't' && c != '*')
		return (1);
	return (0);
}
