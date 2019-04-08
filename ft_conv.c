#include "printf.h"
#include <stdio.h>
int    ft_conv_d(va_list args)
{
    char d;
    d = va_arg(args, typeof(d));
    ft_putnbr(d);
    return (0);
}