#include "printf.h"
#include <stdio.h>
void   ft_calc_bi(double nbr)
{
    
}

int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
    double i;
    (void)flags;
    (void)(*display);
    i = va_arg(args, double);
    int d = (int)i;
    printf("tests == %d\n",d);
    i = i - (double)d;
    printf("| re == %f\n",i);
    ft_calc_bi(i);
    return (0);
}