#include "printf.h"
#include <stdio.h>

int    ft_conv_d(va_list args, int flags)
{
    int d;
    if (flags == HH)
        d = (char)va_arg(args, int);
    else if (flags == H)
        d = (short int)va_arg(args, int);
    //else if (flags == L)
    else
        d = va_arg(args, int);
    ft_putnbr(d);
    return (0);
}