#include "printf.h"

void    ft_space(void)
{
    ft_putchar(' ');
}

void    ft_plus(void)
{
    ft_putchar('+');
}

void    ft_zero(t_conv *lst_fct)
{
    if (ft_strrchr(lst_fct->attribut, '-') == NULL) //&& ft_strrchr(lst_fct->detail, '.'))
        return ;
    return ;
}

void    ft_hachtag(long long i, t_conv *lst_fct)
{
    if (lst_fct->type == 'o' && i != 0)
         ft_putnbr(0);
    if (lst_fct->type == 'x' && i != 0)
        ft_putstr("0x");
    if (lst_fct->type == 'X' && i != 0)
        ft_putstr("0X");
}

void    ft_attribut(long long i, t_conv *lst_fct)
{
    if (ft_strrchr(lst_fct->attribut, '#') != NULL)
        ft_hachtag(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, '0') != NULL && ft_strrchr(lst_fct->attribut, '-') == NULL)
        ft_zero(lst_fct);
    if (ft_strrchr(lst_fct->attribut, ' ') != NULL && i >= 0)
        ft_space();
    if (ft_strrchr(lst_fct->attribut, '+') && i >= 0)
        ft_plus();
}