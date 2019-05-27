#include "printf.h"
#include <stdio.h>
int     ft_conv_spe(va_list args, int flags, t_conv *lst_fct)
{
    (void)flags;
    (void)args;
    char *res;

    res = ft_strnew(1);
    res[0] = '%';
    lst_fct->final = ft_strdup(res);
    lst_fct->final = ft_space(1, lst_fct);
    ft_putstr(lst_fct->final);
    ft_strdel(&res);
    ft_strdel(&lst_fct->final);
    return (0);
}