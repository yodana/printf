#include "printf.h"
#include <stdio.h>

void     ft_calc_octa(long long nbr)
{
    if (nbr >= 1)
    {
        if ((nbr / 8) != 0)
            ft_calc_octa(nbr / 8);
        ft_putnbr((unsigned long)(nbr % 8));
    }
    else if (nbr == 0)
        ft_putnbr(0);
}

void     ft_calc_long_hexam(long long nbr)
{
    if (nbr >= 1)
    {
        if ((nbr / 16) != 0)
            ft_calc_long_hexam(nbr / 16);
        if (nbr % 16 >= 10)
        {
            //printf("before =");
            ft_putchar(55 + (nbr % 16));
           // printf("%d\n",nbr % 16);
        }
        else
            ft_putnbr(nbr % 16);
    }
    else if (nbr == 0)
        ft_putnbr(0);
}

void     ft_calc_long_hexa(long long nbr)
{
    if (nbr >= 1)
    {
        if ((nbr / 16) != 0)
            ft_calc_long_hexa(nbr / 16);
        if (nbr % 16 >= 10)
        {
            //printf("before = %lld\n",87 + (nbr % 16));
            ft_putchar(87 + (nbr % 16));
           // printf("%d\n",nbr % 16);
        }
        else
            ft_putnbr(nbr % 16);
    }
    else if (nbr == 0)
        ft_putnbr(0);
}

void     ft_calc_hexa(unsigned long nbr)
{
    if (nbr >= 1)
    {
        if ((nbr / 16) != 0)
            ft_calc_hexa(nbr / 16);
        if (nbr % 16 >= 10)
        {
            //printf("before = %lu\n",87 + (nbr % 16));
            ft_putchar(87 + (nbr % 16));
           // printf("%d\n",nbr % 16);
        }
        else
            ft_putnbr(nbr % 16);
    }
    else if (nbr == 0)
        ft_putnbr(0);
}