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

typedef struct s_conv
{
    char type;
    int (*f)(va_list,int );
    struct  s_conv *next;
}               t_conv;

int     ft_printf(const char *format, ...);
int     ft_char(va_list args,int flags);
int     ft_str(va_list args,int flags);
int     ft_pointer(va_list args, int flags);
t_conv  *ft_create_lst(void);
void    ft_free_lst(t_conv *list);
void     ft_calc_hexa(unsigned long nbr);
int   ft_conv_d(va_list args, int flags);
#endif
