/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:37:44 by ydonse            #+#    #+#             */
/*   Updated: 2019/03/06 12:25:11 by ydonse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define WRITE_SIZE		10
# define ERROR			-1
# define HEXA_HIGH		1
# define HEXA_LOW		2
# define OCTAL			3

typedef struct			s_sfloat
{
	int					zap;
	long long			i_part;
	long double			num;
	char				*s;
}						t_sfloat;

typedef enum			e_bool
{
	false,
	true
}						t_bool;

typedef enum			e_data
{
	number,
	character
}						t_data;

typedef union			u_type
{
	short				s;
	unsigned short		us;
	int					i;
	unsigned int		u;
	long				l;
	long long			ll;
	unsigned long		lu;
	unsigned long long	llu;
	float				f;
	double				lf;
	long double			ld;
	char				c;
	unsigned char		uc;
	char				*str;
}						t_type;

typedef struct			s_plist
{
	t_type				type;
	t_bool				finish;
	t_bool				string;
	short				mode;
	short				sharp;
	short				plus;
	short				minus;
	int					min_w;
	short				dot;
	int					dot_size;
	short				zero;
	short				space;
	char				*type_str;
	int					skip;
	t_data				type_entree;
	int					nb_size;
	t_bool				percent;
	t_bool				sharp_placed;
	t_bool				f_type;
	t_bool				pointer;
	t_bool				uns;
	struct s_plist		*next;
}						t_plist;

char					*add_attributes(t_plist *list, long double nb);
void					check_attribute_1(t_plist *list, const char *str_ptr,
						va_list *ap);
void					check_attribute_2(t_plist *list, const char *str_ptr,
						va_list *ap);
void					check_attribute_3(t_plist *list, const char *str_ptr,
						va_list *ap);
void					check_attribute_4(t_plist *list, const char *str_ptr,
						va_list *ap);
int						check_field(t_plist *list, long double nb, int i,
						char *str);
int						check_field_minus(t_plist *list, long double nb, int i,
						char *str);
void					check_flags_1(t_plist *list, const char *str_ptr,
						va_list *ap);
int						check_if_copy(t_plist *list, long double nb, int i,
						char *str);
void					check_ll_type(t_plist *list, const char *str_ptr,
						va_list *ap, int skip);
void					check_hh_type(t_plist *list, const char *str_ptr,
						va_list *ap, int skip);
void					check_l_maj_type(t_plist *list, const char *str_ptr,
						va_list *ap, int skip);
int						check_char_field(t_plist *list, int i, char *str);
int						check_char_field_minus(t_plist *list, int i, char *str);
int						check_nb_field(t_plist *list, long double nb, int i,
						char *str);
int						check_nb_field_minus(t_plist *list, long double nb,
						int i, char *str);
int						check_negative_precision(t_plist *list, int i,
						char *str);
int						check_plus(t_plist *list, long double nb, int i,
						char *str);
int						check_precision(t_plist *list, long double nb, int i,
						char *str);
int						check_sharp_hexa(t_plist *list, long double nb, int i,
						char *str);
int						check_sharp_hexa_field(t_plist *list, long double nb,
						int i, char *str);
int						check_sharp_hexa_minus(t_plist *list, long double nb,
						int i, char *str);
int						check_sharp_octal(t_plist *list, long double nb, int i,
						char *str);
int						check_space(t_plist *list, long double nb, int i,
						char *str);
char					*convert_hexa(unsigned long long nb, t_plist *list);
char					*convert_octal(unsigned long long nb);
t_plist					*fill_list(const char *restrict format, va_list *ap,
						t_plist *list);
int						flags_cmp(const char *str, const char *flags, int size);
void					free_list(t_plist *list);
char					*ft_ftoa_ld(long double num, char sign, t_plist *list);
t_sfloat				*init_sfloat(int zap, long long i_part,
						long double num);
int						ft_printf(const char *restrict format, ...);
int						get_attributes_length(t_plist *list, int i);
int						get_base_size(unsigned long long nb,
						unsigned long long base);
void					handle_d(t_plist *list, va_list *ap, int skip);
void					handle_u(t_plist *list, va_list *ap, int skip);
void					handle_f(t_plist *list, va_list *ap, int skip);
void					handle_s(t_plist *list, va_list *ap, int skip);
void					handle_c(t_plist *list, va_list *ap, int skip);
void					handle_p(t_plist *list, va_list *ap, int skip);
void					handle_o(t_plist *list, va_list *ap, int skip);
void					handle_x(t_plist *list, va_list *ap, int skip);
void					handle_xmaj(t_plist *list, va_list *ap, int skip);
void					handle_percent(t_plist *list, va_list *ap, int skip);
void					handle_hd(t_plist *list, va_list *ap, int skip);
void					handle_ho(t_plist *list, va_list *ap, int skip);
void					handle_hu(t_plist *list, va_list *ap, int skip);
void					handle_hx(t_plist *list, va_list *ap, int skip);
void					handle_hx_maj(t_plist *list, va_list *ap, int skip);
void					handle_hhd(t_plist *list, va_list *ap, int skip);
void					handle_hho(t_plist *list, va_list *ap, int skip);
void					handle_hhu(t_plist *list, va_list *ap, int skip);
void					handle_hhx(t_plist *list, va_list *ap, int skip);
void					handle_hhx_maj(t_plist *list, va_list *ap, int skip);
void					handle_ld(t_plist *list, va_list *ap, int skip);
void					handle_lld(t_plist *list, va_list *ap, int skip);
void					handle_lf(t_plist *list, va_list *ap, int skip);
void					handle_maj_lf(t_plist *list, va_list *ap, int skip);
void					handle_lo(t_plist *list, va_list *ap, int skip);
void					handle_llo(t_plist *list, va_list *ap, int skip);
void					handle_lu(t_plist *list, va_list *ap, int skip);
void					handle_llu(t_plist *list, va_list *ap, int skip);
void					handle_lx(t_plist *list, va_list *ap, int skip);
void					handle_llx(t_plist *list, va_list *ap, int skip);
void					handle_lx_maj(t_plist *list, va_list *ap, int skip);
void					handle_llx_maj(t_plist *list, va_list *ap, int skip);
void					handle_null(t_plist *list, const char *strptr, int ptr);
void					handle_sharp(t_plist *list, const char *str_ptr);
void					handle_plus(t_plist *list, const char *str_ptr);
void					handle_minus(t_plist *list, const char *str_ptr);
void					handle_zero(t_plist *list, const char *str_ptr);
void					handle_space(t_plist *list, const char *str_ptr);
void					handle_field(t_plist *list, const char *str_ptr);
void					handle_precision(t_plist *list, const char *str_ptr);
void					check_modifiers(t_plist *list, const char *str_ptr,
						va_list *ap);
int						check_field_minus(t_plist *list, long double nb,
						int i, char *str);
t_plist					*new_list(void);
char					*pf_strncpy(char *dst, const char *src, size_t len);
int						write_full_str(t_plist *list, const char *restrict
						format);
#endif
