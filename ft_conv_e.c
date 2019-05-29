#include "printf.h"
#include <stdio.h>
char    *ft_conv_e(t_conv *lst_fct, char *res, int comma)
{
    char *new;
    size_t i;
    int j;
    char *str_comma; 
    
   printf("comma == %d",lst_fct->precision);
    str_comma = ft_itoa(comma - 1);
    j = 0;
    i = 0;
    new = ft_strnew(ft_strlen(res));
    while (i <= (size_t)lst_fct->precision)
    {
        if (i != (size_t)comma)
            new[j] = res[i];
        if (j == 1)
            new[j] = '.';
        if (i != (size_t)comma)
            j++;
        if (j != 1)
            i++;
    }
    if (comma < 10)
        str_comma = ft_strjoin_fr("0", str_comma, 2);
    new = ft_strjoin_fr(new, "e+", 1);
    new = ft_strjoin_fr(new, str_comma, 1);
    return (new);
}