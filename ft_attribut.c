#include "printf.h"
#include <stdio.h>
char    *ft_space(long long i, t_conv *lst_fct)
{
    char *res;
    (void)res;
    int d;
    int size;
    (void)i;
    size = ft_strlen(lst_fct->final);
    d = lst_fct->champ;
    res = ft_strdup(lst_fct->final);
    if (ft_strrchr(lst_fct->attribut, ' ') != NULL && i >= 0)
    {
        res = ft_strjoin_fr(" ", res, 2);
        lst_fct->final = res;
        size++;
    }
    if (ft_strrchr(lst_fct->attribut, '0') != NULL && lst_fct->precision == 0)
        return (lst_fct->final);
    while (d > size && lst_fct->champ > 0)
    {
        res = ft_strjoin_fr(" ", res, 2);
        d--;
    }
    while (size < (d * -1) && lst_fct->champ < 0)
    {
        res = ft_strjoin_fr(res, " ", 1);
        size++;
    }
    lst_fct->final = res;
    ft_strdel(&res);
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
    int d;

    d = 0;
    size = ft_strlen(lst_fct->final);
    while (lst_fct->final[d] == ' ' || lst_fct->final[d] == '+' || lst_fct->final[d] == '-')      
    {
        d++;
        res = ft_strsub(lst_fct->final, d, size);
    }
    if (d == 0)
        res = ft_strdup(lst_fct->final);
    while ((size < lst_fct->precision || size < lst_fct->champ))
    {
        res = ft_strjoin_fr("0", res, 2);
        size++;
    }
    if (i < 0)
        res = ft_strjoin_fr("-", res, 2);
    if (ft_strrchr(lst_fct->attribut, ' ') && i >= 0)
         res = ft_strjoin_fr(" ", res, 2);
     if (ft_strrchr(lst_fct->attribut, '+') && i >= 0)
       res = ft_strjoin_fr("+", res, 2);
    return (res);
}

char    *ft_precision(long long i, t_conv *lst_fct)
{
    char *res;
    int size;
    int d;

    d = 0;
    size = ft_strlen(lst_fct->final);
    if (i == 0 && lst_fct->precision == 1)
        return (NULL);
    if (i < 0)
        size--;
    //printf("szie == %d\n",size);
     while (lst_fct->final[d] == ' ' || lst_fct->final[d] == '+' || lst_fct->final[d] == '-')      
    {
        d++;
        res = ft_strsub(lst_fct->final, d, size);
    }
    if (d == 0)
        res = ft_strdup(lst_fct->final);
    while (size < lst_fct->precision - 1)
    {
        res = ft_strjoin_fr("0", res, 2);
        size++;
    }
    if (i < 0)
        res = ft_strjoin_fr("-", res, 2);
    return (res);
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

    if (lst_fct->precision != 0 && lst_fct->type != 'f')
       lst_fct->final = ft_precision(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, '+') && i >= 0)
      lst_fct->final = ft_plus(lst_fct);
    if (ft_strrchr(lst_fct->attribut, '#') != NULL)
        lst_fct->final = ft_hachtag(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, ' ') != NULL || lst_fct->champ != 0)
     lst_fct->final = ft_space(i, lst_fct);
    if (ft_strrchr(lst_fct->attribut, '0') && lst_fct->precision == 0)
        lst_fct->final = ft_zero(i, lst_fct);
    return (lst_fct->final);
}