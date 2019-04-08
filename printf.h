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

typedef struct s_conv
{
    char type;
    int (*f)(va_list);
    struct  s_conv *next;
}               t_conv;

int     ft_printf(const char *format, ...);
int     ft_char(va_list args);
int     ft_str(va_list args);
int     ft_pointer(va_list args);
t_conv  *ft_create_lst(void);
void    ft_free_lst(t_conv *list);
void     ft_calc_hexa(unsigned long nbr);
int   ft_conv_d(va_list args);
#endif
