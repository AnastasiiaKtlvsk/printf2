/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:29:36 by akotilie          #+#    #+#             */
/*   Updated: 2018/05/26 16:26:36 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "locale.h"

char	*print_cc(t_pm **pm, va_list arg)
{
	char		*res;
	wchar_t		wc;
	int			size;

	wc = va_arg(arg, wchar_t);
	if (wc == 0)
		return ("-2");
	if (MB_CUR_MAX <= 1)
		return ("-1");
	size = size_of_wchar(wc);
	res = ft_memalloc(sizeof(char) * size + 1);
	write_wchar(&res, wc, size, 0);
	(*pm)->tp = 'c';
	return (res);
}

void	write_wchar(char **str, wchar_t wc, int size, int s)
{
	if (wc < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		(*str)[s] = (unsigned char)wc;
	else if (size == 2)
	{
		(*str)[s] = (unsigned char)((wc >> 6) | 0xC0);
		(*str)[++s] = (unsigned char)((wc & 0x3F) | 0x80);
	}
	else if (size == 3)
	{
		(*str)[s] = (unsigned char)(((wc >> 12)) | 0xE0);
		(*str)[++s] = (unsigned char)(((wc >> 6) & 0x3F) | 0x80);
		(*str)[++s] = (unsigned char)((wc & 0x3F) | 0x80);
	}
	else if (size == 4)
	{
		(*str)[s] = (unsigned char)(((wc >> 18)) | 0xF0);
		(*str)[++s] = (unsigned char)(((wc >> 12) & 0x3F) | 0x80);
		(*str)[++s] = (unsigned char)(((wc >> 6) & 0x3F) | 0x80);
		(*str)[++s] = (unsigned char)((wc & 0x3F) | 0x80);
	}
}

int		size_of_wchar(wchar_t wc)
{
	if (wc < (1 << 7))
		return (1);
	else if (wc < (1 << 11))
		return (2);
	else if (wc < (1 << 16))
		return (3);
	else if (wc < (1 << 21))
		return (4);
	return (0);
}
