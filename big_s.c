/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_S.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:12:57 by akotilie          #+#    #+#             */
/*   Updated: 2018/03/21 18:12:58 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "locale.h"

char	*print_ss(t_pm **pm, va_list arg, int whole_len, int i)
{
	char	*res;
	wchar_t	*ws;
	int		len;

	ws = va_arg(arg, wchar_t *);
	if (ws == NULL)
		return (ft_strdup("(null)"));
	if (MB_CUR_MAX <= 1)
		return ("-1");
	while (ws[++i])
		whole_len += size_of_wchar(ws[i]);
	res = ft_memalloc(sizeof(char) * whole_len + 1);
	i = -1;
	len = 0;
	((*pm)->pr > 0) ? whole_len = (*pm)->pr : 0;
	while (ws[++i])
	{
		if (whole_len - len - size_of_wchar(ws[i]) > -1)
		{
			write_wchar(&res, ws[i], size_of_wchar(ws[i]), len);
			len += size_of_wchar(ws[i]);
		}
	}
	(*pm)->tp = 's';
	return (res);
}
