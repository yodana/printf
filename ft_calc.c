#include "printf.h"
#include <stdio.h>
void     ft_calc_hexa(unsigned long nbr)
{
    if (nbr >= 1)
    {
        ft_calc_hexa(nbr / 16);
        if (nbr % 16 >= 10)
        {
            //printf("before = %d\n",87 + (nbr % 16));
            ft_putchar(87 + (nbr % 16));
           // printf("%d\n",nbr % 16);
        }
        else
            ft_putnbr(nbr % 16);
    }
}