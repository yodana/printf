/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:41:00 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 05:04:26 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include "structures.h"
# include "union.h"
# define H 1
# define HH 2
# define L 4
# define LL 5
# define FL 7
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define END_COLOR "\033[0m"

int		ft_printf(const char *format, ...);
char	*ft_calc_hexa(unsigned long nbr);
char	*ft_calc_octa(long long nbr);
char	*ft_calc_long_hexa(long long nbr);
char	*ft_calc_long_hexam(long long nbr);
char	*ft_i_to_bi(unsigned long long nbr);
char	*ft_bi_to_dec(char *m, int i, int power, int precision);
char	*ft_dtoa(long double mantisse, int size);
char	*ft_calc_exposant(long double f, char *res, unsigned int exposant);
char	*ft_fill_attribut(void);
int		ft_check_flags(const char *format);
int		ft_check_float_round(char *print, int precision);
int		ft_char(t_conv *lst_fct, va_list args, int flags);
int		ft_str(t_conv *lst_fct, va_list args, int flags);
int		ft_pointer(t_conv *lst_fct, va_list args, int flags);
t_conv	*ft_create_lst(void);
void	ft_free_lst(t_conv *list);
int		ft_conv(t_conv *lst_fct, va_list args, int flags);
int		ft_conv_2(t_conv *lst_fct, va_list args, int flags);
int		ft_conv_f(t_conv *lst_fct, va_list args, int flags);
int		ft_conv_spe(t_conv *lst_fct, va_list args, int flags);
char	*ft_space(long long i, t_conv *lst_fct, int size);
char	*ft_attribut(long long i, t_conv *lst_fct);
char	*ft_plus(t_conv *lst_fct);
char	*ft_precision(long long i, t_conv *lst_fct, int d, int size);
char	*ft_zero(long long i, t_conv *lst_fct, int d, int size);
char	*ft_check_attribut(int *i, const char *format, int k, int j);
int		ft_check_flags(const char *format);
int		ft_check_champ(int *i, const char *format);
int		ft_check_precision(int *i, const char *format);
char    *ft_conv_e(t_conv *lst_fct, char *res, int comma);
#endif
