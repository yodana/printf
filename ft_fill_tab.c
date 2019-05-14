#include "printf.h"

char    *ft_fill_attribut(void)
{
    char *tab;

    tab = ft_strnew(6);
    tab[0] = '#';
    tab[1] = '0';
    tab[2] = '-';
    tab[3] = '+';
    tab[4] = ' ';
    tab[5] = '\0';
    return (tab);
}