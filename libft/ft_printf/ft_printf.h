/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:20:05 by mel-idri          #+#    #+#             */
/*   Updated: 2019/12/12 19:43:56 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef LIBFT_H
#  include "../libft.h"
# endif
# include <stdarg.h>

# define FLAG_ZERO 1U
# define FLAG_HASH 2U
# define FLAG_SPACE 4U
# define FLAG_PLUS 8U
# define FLAG_MINUS 16U
# define ZERO 0
# define INF 1
# define NAN 2
# define FLOAT 3
# define IS_DIGIT(x) '0' <= x && x <= '9'
# define ABS(number) number > 0 ? number : (-1) * number
# define MAX(a, b) (a > b ? a : b)

typedef	enum		e_length
{
	HH = 1,
	H,
	L,
	LL,
	CAPITAL_L
}					t_length;

typedef struct		s_conv_spec
{
	__uint64_t		flags;
	int				width;
	int				is_pset;
	int				precision;
	t_length		length;
	char			conv_char;
}					t_conv_spec;

typedef struct		s_specs
{
	__uint64_t	unbr;
	int			sign;
	int			unbr_len;
	int			spaces;
	int			zeros;
}					t_specs;

typedef union		u_ext_db
{
	long double		val;
	__uint128_t		unbr;
	struct
	{
		__uint64_t	m : 64;
		__uint64_t	e : 15;
		__uint64_t	sign : 1;
	}				s;
}					t_ext_dbl;

typedef struct		s_float_specs
{
	t_ext_dbl		ldbl;
	t_bigint		*whole;
	t_bigint		*frac;
	int				float_type;
}					t_float_specs;

int					parse_conversion(char **conv_str, va_list *ap);
int					apply_conv_function(t_conv_spec *conv_spec, va_list *ap,
						int c);
int					is_in_str(int c, char *str);
int					ft_printf(char *format, ...);
int					conv_di(t_conv_spec *conv_spec, va_list *ap);
int					conv_u(t_conv_spec *conv_spec, va_list *ap);
int					conv_o(t_conv_spec *conv_spec, va_list *ap);
int					conv_c(t_conv_spec *conv_spec, va_list *ap);
int					conv_s(t_conv_spec *conv_spec, va_list *ap);
int					conv_percenatge(t_conv_spec *conv_spec);
__int64_t			read_int(va_list *ap, t_length len);
__uint64_t			read_uint(va_list *ap, t_length len);
void				put_octal(unsigned long decimal);
int					conv_f(t_conv_spec *conv_spec, va_list *ap);
t_bigint			*get_whole(unsigned long mantissa, int exp);
t_bigint			*get_fraction(unsigned long mantissa, int exp);
int					bit_is_set(unsigned long nbr, int index);
long double			read_long_double(va_list *ap, t_length len);
int					round_float(t_bigint **whole, t_bigint **frac, int precis);
int					conv_x(t_conv_spec *conv_spec, va_list *ap);
int					conv_p(t_conv_spec *conv_spec, va_list *ap);
int					print_float_prefix(t_conv_spec *conv_spec, int float_sign);
int					check_float_type(t_conv_spec *conv_spec,
						t_float_specs *f_specs);

#endif
