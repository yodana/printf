#include "printf.h"

int     ft_conv_spe(va_list args, int flags, t_conv *lst_fct)
{
    (void)flags;
    (void)(lst_fct);
    (void)args;
    ft_putchar('%');
    return (0);
}