#include "printf.h"


char    *ft_space(t_conv *lst_fct)
{
    int i;

    i = ft_strlen(lst_fct->final);
    while (lst_fct->champ > 0 && i < lst_fct->champ)
    {
        lst_fct->final = ft_strjoin_fr(" ", lst_fct->final, 2);
        i++;
    }
    while (lst_fct->champ < 0 && i < (lst_fct->champ * -1))
    {
        lst_fct->final = ft_strjoin_fr(lst_fct->final, " ", 1);
        i++;
    }
    return (lst_fct->final);
}

char    *ft_plus(t_conv *lst_fct)
{
    lst_fct->final = ft_strjoin_fr("+", lst_fct->final, 2);
    return (lst_fct->final);
}

void    ft_zero(t_conv *lst_fct)
{
    if (ft_strrchr(lst_fct->attribut, '-') == NULL) //&& ft_strrchr(lst_fct->detail, '.'))
        return ;
    return ;
}

char    *ft_hachtag(long long i, t_conv *lst_fct)
{
    if (lst_fct->type == 'o' && i != 0)
         lst_fct->final = ft_strjoin_fr("0",lst_fct->final, 2);
    if (lst_fct->type == 'x' && i != 0)
       lst_fct->final = ft_strjoin_fr("0x",lst_fct->final, 2);
    if (lst_fct->type == 'X' && i != 0)
        lst_fct->final = ft_strjoin_fr("0X",lst_fct->final, 2);
    return (lst_fct->final);
}

char   *ft_attribut(long long i, t_conv *lst_fct)
{
    if (ft_strrchr(lst_fct->attribut, '#') != NULL)
        lst_fct->final = ft_hachtag(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, '0') != NULL && ft_strrchr(lst_fct->attribut, '-') == NULL)
        ft_zero(lst_fct);
    if (ft_strrchr(lst_fct->attribut, ' ') != NULL && i >= 0)
        ft_space(lst_fct);
    if (ft_strrchr(lst_fct->attribut, '+') && i >= 0)
       lst_fct->final = ft_plus(lst_fct);
    if (lst_fct->champ != 0)
        lst_fct->final = ft_space(lst_fct);
    return (lst_fct->final);
}