#include "printf.h"

int     ft_conv_spe(va_list args, int flags, void(*display)(long long))
{
    (void)flags;
    (void)(display);
    (void)args;
    ft_putchar('%');
    return (0);
}