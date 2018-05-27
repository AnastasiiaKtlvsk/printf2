/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:32:13 by akotilie          #+#    #+#             */
/*   Updated: 2018/02/09 14:32:14 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BF_SIZE 256

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <stdarg.h>

typedef struct			s_pm
{
	int					*fl;
	int					wd;
	int					pr;
	int					sz[2];
	char				tp;
}						t_pm;

int						has_type(char *s);
void					write_in_bf_c(char c);
void					write_in_bf_s(char **s);
int						f_ch(char *s, char c1, char c2);
int						check_format(char c);
int						ret_i(int op, int n);
unsigned long long int	ret_buff(unsigned long long int bf);
int						ft_printf4(t_pm **pm, char *f, char *tm, va_list arg);
int						pm_typenull(t_pm **pm, char *f, va_list arg);
void					pm_typenull2(char *cur, t_pm **pm, char *line);
int						choose_format(char *format, va_list arg, t_pm **pm);
int						check_fls(char *format, t_pm **pm);
int						check_wd(char *f, t_pm **pm, va_list arg, int i);
int						check_pr(char *format, t_pm **pm, va_list arg);
int						check_pr2(char *format, t_pm **pm, va_list arg, int i);
int						ft_printf2(char *tm, char *f, va_list arg, t_pm **pm);
int						ft_printf3(char *tm, int i, char **f);
int						ft_printf3(char *tm, int i, char **f);
int						check_size(char *format, t_pm **pm);
void					check_size2(char *format, t_pm **pm);
char					**sff2(t_pm **pm, va_list a, char **s);
char					**cf(t_pm **pm, va_list a, char **s);
char					**sff(t_pm **pm, va_list a, char **s);
void					pf(t_pm **pm);
void					fr(char *f, t_pm **pm);
char					**co(t_pm **pm, va_list a, char **s);
char					**process(char *f, t_pm **pm, char **s);
int						choose_type(char *f, t_pm **pm, va_list arg);
void					reallocate(char **line, int add_size);
int						ft_printf(char *format, ...);
int						mediator(char *tm, va_list arg);
int						ft_printf0(char *tm, va_list arg, t_pm **pm);
int						printf01(char *tm, va_list arg, t_pm **pm, char **f);
int						ft_printf1(char *tm, int i);
char					**pf2(t_pm **pm, char **s);
char					*print_string(va_list arg);
char					*print_char(va_list arg);
char					*print_di(t_pm **pm, va_list arg);
char					*print_uox(t_pm **pm, va_list arg);
char					*print_u(t_pm **pm, va_list arg);
char					*print_d(t_pm **pm, va_list arg);
char					*print_uox2(t_pm **pm, va_list arg, uintmax_t i);
char					*int_itoa(intmax_t num, int base);
char					*uint_itoa(uintmax_t num, int base, char type);
char					*process_fls(t_pm **pm, char **str);
char					*process_sharp2(t_pm **pm, char **str);
char					*process_01(t_pm **pm, char **str, int len);
char					*process_02(t_pm **pm, char **str, int len);
char					*insert_in_front(char **str, char c, int count);
char					*insert_in_back(char **str, char c, int count);
char					*process_space(t_pm **pm, char **str);
char					*process_minus(t_pm **pm, char **str);
char					*process_plus(t_pm **pm, char **str);
char					*process_sharp(t_pm **pm, char **s);
char					*process_0(t_pm **pm, char **str, int len);
char					*process_wd(t_pm **pm, char **str, int len);
char					*process_pr(t_pm **pm, char **str);
char					*process_pr2(t_pm **pm, char **str);
char					*print_ss(t_pm **pm, va_list arg, int whole_len, int i);
char					*print_cc(t_pm **pm, va_list arg);
void					write_wchar(char **str, wchar_t wc, int size, int s);
int						size_of_wchar(wchar_t wc);
char					*print_ss2(t_pm **pm, va_list arg, int i, int len);
char					*int_itoa2(intmax_t num, int base, int count, int fl);
#endif
