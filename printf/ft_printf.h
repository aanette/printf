/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanette <aanette@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:05:31 by aanette           #+#    #+#             */
/*   Updated: 2021/01/22 05:44:50 by aanette          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define TYPE "cspdiuxX%"

typedef struct	s_struct
{
	int		minus;
	int		minusint;
	int		zero;
	int		w;
	int		p;
	int		star;
	int		type;
}				t_struct;

const char		*parse(va_list ap, const char *fr, t_struct *f);
int				ft_putchar(char c);
int				print_type(va_list ap, t_struct *flags);
void			init_flags(t_struct *f);
int				ft_printnbrneg(int i, t_struct *f);
void			check_minus_zero_dot(const char *fr, t_struct *f);
void			check_star(va_list ap, t_struct *f);
void			check(va_list ap, const char *fr, t_struct *f);
void			check_type(const char *fr, t_struct *f);
char			*ft_strchr(const char *s, int c);
int				ft_isdigit(int c);
int				ft_printf(const char *fr, ...);
int				ft_printnbr(va_list ap, t_struct *f);
int				widthnbrb(t_struct *f, int i);
int				widthnbrp(t_struct *f, int i);
int				widthnbrbneg(t_struct *f, int i);
int				widthnbrpneg(t_struct *f, int i);
int				widthzero(t_struct *f, int i);
char			*ft_itoa(int n);
size_t			ft_strlen(char *str);
int				widthnbrblast(int i, t_struct *f);
int				widthnbrblastneg(int i);
void			printprec(t_struct *f, int i);
void			printnull(int k);
void			printprobel(int k);
void			printres(int i);
int				widthnbrdb(t_struct *f, int i);
int				widthnbrdbneg(t_struct *f, int i);
int				widthzeroneg(t_struct *f, int i);
void			printprecneg(t_struct *f, int i);
int				ft_printnbrneg(int i, t_struct *f);
int				widthnbrppneg(t_struct *f, int i);
int				widthnbrdb2(t_struct *f, int i);
int				ft_printnbrneg(int i, t_struct *f);
int				printzero(t_struct *f);
char			*ft_itoa_u(unsigned int n);
void			printres1(unsigned int i);
void			printprec1(t_struct *f, unsigned int i);
int				widthnbrb1(t_struct *f, unsigned int i);
int				widthnbrd1(t_struct *f, unsigned int i);
int				widthnbrdb1(t_struct *f, unsigned int i);
int				widthnbrp1(t_struct *f, unsigned int i);
int				widthnbrblast1(unsigned int i, t_struct *f);
int				widthzero1(t_struct *f, unsigned int i);
int				ft_printnbru(va_list ap, t_struct *f);
int				widthzero16(t_struct *f, unsigned int i);
int				widthnbrblast16(unsigned int i, t_struct *f);
int				widthnbrp16(t_struct *f, unsigned int i);
int				ft_printnbrx(va_list ap, t_struct *f);
int				widthnbrdb16(t_struct *f, unsigned int i);
int				widthnbrd16(t_struct *f, unsigned int i);
int				widthnbrb16(t_struct *f, unsigned int i);
void			printprec16(t_struct *f, unsigned int i);
char			*ft_itoa_base(t_struct *f, unsigned int n);
void			printres16(t_struct *f, unsigned int i);
int				widthchar(int w, int len, int zero);
int				ft_printchar(va_list ap, t_struct *f);
int				ft_printstr(va_list ap, t_struct *f);
int				width_str_zero(t_struct *f, char *s);
int				width_str_p2(t_struct *f, char *s);
void			ft_printcut(char *s, int i, t_struct *f);
int				width_str_2(t_struct *f, char *s);
int				width_str2(t_struct *f, char *s);
int				pstr(char *str);
void			p1(t_struct *f, unsigned long long i);
void			p2(t_struct *f, unsigned long long i);
void			p21(t_struct *f, unsigned int i);
void			p11(t_struct *f, unsigned int i);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_printnbrp(va_list ap, t_struct *f);
void			printres16p(unsigned long long i);
char			*ft_itoa_basep(unsigned long long n);
void			printprec16p(t_struct *f, unsigned long long i);
int				widthnbrb16p(t_struct *f, unsigned long long i);
int				widthnbrd16p(t_struct *f, unsigned long long i);
int				widthnbrdb16p(t_struct *f, unsigned long long i);
int				widthnbrp16p(t_struct *f, unsigned long long i);
int				widthnbrblast16p(unsigned long long i, t_struct *f);
int				widthzero16p(t_struct *f, unsigned long long i);
void			q2(t_struct *f, unsigned int i);
void			q1(t_struct *f, unsigned int i);
void			q11(t_struct *f, int i);
void			q21(t_struct *f, int i);
void			w1(t_struct *f, int i);
int				w2(t_struct *f, int i);
int				r(t_struct *f, unsigned int i);
int				r2(t_struct *f, unsigned int i);
int				r3(t_struct *f, int i);
int				ft_printnbrpos(int i, t_struct *f);
char			*ft_strdup(const char *str);

#endif
