/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_null_rets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:41:12 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/20 19:41:19 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ret_i(int op, int n)
{
	static int i;

	if (op == '+')
		i += 1;
	if (op == '-')
		i -= 1;
	if (n != -1)
		i = n;
	return (i);
}

unsigned long long int	ret_buff(unsigned long long int bf)
{
	static unsigned long long int buff;

	if (bf != 0)
		buff = bf;
	return (buff);
}

int						ft_printf4(t_pm **pm, char *f, char *tm, va_list arg)
{
	int		type;
	int		form;
	char	*line;

	form = choose_format(f, arg, pm);
	type = choose_type(f, pm, arg);
	if (((*pm)->tp == 0 && form != 0) || ft_strchr(f, '%') != NULL)
		if (pm_typenull(pm, ft_strchr(tm, '%') + 1, arg) == -5)
			return (-5);
	if ((*pm)->tp == 0 && form == 0)
	{
		if (ft_strchr(tm, '%') == NULL || (ft_strchr(tm, '%') != NULL &&
					!ft_strchr((ft_strchr(tm, '%') + 1), '%')))
		{
			line = ft_strchr(tm, '%') + 1;
			write_in_bf_s(&line);
		}
		else if (ft_strchr(tm, '%') + 1 != NULL)
		{
			line = (ft_strdup((ft_strchr((ft_strchr(tm, '%') + 1), '%'))));
			write_in_bf_s(&line);
			free(line);
		}
	}
	return (type);
}

int						pm_typenull(t_pm **pm, char *f, va_list arg)
{
	int		i;
	int		l;
	char	*cur;
	int		in;
	char	*line;

	i = 0;
	in = 0;
	(*pm)->tp = 's';
	l = ft_strlen(f);
	(f[i] == '%') ? write_in_bf_c('%') : 0;
	(f[i] == '%') ? i++ : 0;
	while (i < l && check_format(f[i]) != 1)
		i++;
	cur = ft_memalloc(sizeof(char) * 2);
	(f[i] && f[i] != '%') ? cur[in] = f[i++] : 0;
	line = ft_memalloc(sizeof(char) * (l - i + 1));
	while (f[i] && f[i] != '%')
		line[in++] = f[i++];
	(check_format(f[i - 1]) != 1 && f[i] == '%') ? cur[in++] = f[i++] : 0;
	--i;
	line[i] = '\0';
	pm_typenull2(cur, pm, line);
	(f[i] == '%' && f[i + 1]) ? ft_printf0(ft_strchr(f, '%') + 1, arg, pm) : 0;
	return (-5);
}

void					pm_typenull2(char *cur, t_pm **pm, char *line)
{
	char	*help;
	char	**str;

	if (cur && ft_strcmp(cur, "") != 0)
	{
		str = &cur;
		help = process_fls(pm, str);
		*str = help;
		help = process_wd(pm, str, ft_strlen(*str));
		*str = help;
		write_in_bf_s(str);
		if (line)
		{
			write_in_bf_s(&line);
			free(line);
		}
		free(*str);
	}
}
