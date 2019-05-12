#include "printf.h"

void    ft_hachtag(va_list args, t_conv *lst_fct)
{
    if (lst_fct->type == 'o' && (unsigned int)va_arg(args, unsigned int) != 0)
        ft_putnbr(0);
}
void    ft_attribut(va_list args, t_conv *lst_fct)
{
    if (lst_fct->attribut[0] == '#')
        ft_hachtag(args, lst_fct);
}