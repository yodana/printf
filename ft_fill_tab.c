#include "printf.h"

char    *ft_fill_attribut(void)
{
    char *tab;

    tab = ft_strnew(2);
    tab[0] = '#';
    tab[1] = '\0';
    return (tab);
}