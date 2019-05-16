#include "printf.h"
#include <stdio.h>
char    *ft_precision(long long d, t_conv *lst_fct)
{
    int i;
    int size;
    char *res;

    size = ft_strlen(lst_fct->final);
    i = 0;
    if (d < 0)
    {
        res = ft_strsub(lst_fct->final, 1, size);
        size--;
    }
    else
        res = ft_strdup(lst_fct->final);
    while (i < lst_fct->precision - size)
    {
        res = ft_strjoin_fr("0", res, 2);
        i++;
    }
    if (d < 0)
        res = ft_strjoin_fr("-", res, 2);
    return (res);
}
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

char    *ft_zero(long long i, t_conv *lst_fct)
{
    char *res;
    int size;

    size = ft_strlen(lst_fct->final);
   // if (ft_strrchr(lst_fct->attribut, '-') == NULL) //&& ft_strrchr(lst_fct->detail, '.'))
    //    return (lst_fct->final);
     if (i < 0 || ft_strrchr(lst_fct->attribut, '+') != NULL)      
    {
        res = ft_strsub(lst_fct->final, 1, size);
    }
    else
        res = ft_strdup(lst_fct->final);
    //printf("champ== %d\n",lst_fct->champ);
    while (size <= lst_fct->precision || size < lst_fct->champ)
    {
        res = ft_strjoin_fr("0", res, 2);
        size++;
    }
    if (i < 0)
        res = ft_strjoin_fr("-", res, 2);
    return (res) ;
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
   // printf("attribut == %s\n",lst_fct->attribut);
    if (lst_fct->precision >= 0 && lst_fct->type != 'f' && ft_strrchr(lst_fct->attribut, '0') == NULL)
        lst_fct->final = ft_precision(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, '#') != NULL)
        lst_fct->final = ft_hachtag(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, ' ') != NULL && i >= 0)
        ft_space(lst_fct);
    if (ft_strrchr(lst_fct->attribut, '+') && i >= 0)
       lst_fct->final = ft_plus(lst_fct);
    if (ft_strrchr(lst_fct->attribut, '0'))
        lst_fct->final = ft_zero(i, lst_fct);
    if (lst_fct->champ != 0 && ft_strrchr(lst_fct->attribut, '0') == NULL)
        lst_fct->final = ft_space(lst_fct);
    return (lst_fct->final);
}