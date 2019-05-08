/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:41:00 by yodana            #+#    #+#             */
/*   Updated: 2019/04/01 15:56:52 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

#define H 1
#define HH 2
#define L 4
#define LL 5
#define FL 7

typedef struct s_conv
{
    char type;
    int (*f)(va_list,int , void(*display)(long long));
    void (*display)(long long);
    struct  s_conv *next;
}               t_conv;

typedef struct s_float
{
    char *mantisse;
    double res_mantisse;
    int   exposant;
    int signe;
    char *format;
}              t_float;

typedef union {
 long double f;
  struct {
    unsigned long long m:32;
    unsigned long long m1:32;
	unsigned int e:15;
	unsigned int sign:1;
    unsigned int empty:16;
  } parts;
}     float_cast;

typedef union{
    long double f;
    struct {
        unsigned long long mantisse:64;
        unsigned int exponent:15;
        unsigned int sign:1;
    } parts1;
}      float_cast1;

int     ft_printf(const char *format, ...);
int     ft_char(va_list args,int flags, void(*display)(long long));
int     ft_str(va_list args,int flags, void(*display)(long long));
int     ft_pointer(va_list args, int flags, void(*display)(long long));
t_conv  *ft_create_lst(void);
void    ft_free_lst(t_conv *list);
void     ft_calc_hexa(unsigned long nbr);
int   ft_conv(va_list args, int flags,void(*display)(long long));
void     ft_calc_octa(long long nbr);
int    ft_conv_2(va_list args, int flags, void(*display)(long long));
void     ft_calc_long_hexa(long long nbr);
void     ft_calc_long_hexam(long long nbr);
int    ft_conv_f(va_list args, int flags, void(*display)(long long));
char *ft_i_to_bi(unsigned long long nbr);
char    *ft_bi_to_dec(char *m);
char    *ft_calc_exposant_neg(char *res, int stop, int hold);
char    *ft_calc_exposant_pos(char *res, int exposant);
char	*ft_dtoa(long double mantisse);
#endif
