#include "printf.h"

int     ft_conv_spe(va_list args, int flags, t_conv *lst_fct)
{
    (void)flags;
    (void)(lst_fct);
    (void)args;
    char *res;

    res = ft_strnew(0);
    res[0] = '%';
    lst_fct->final = res;
    ft_putstr(lst_fct->final);
    return (0);
}