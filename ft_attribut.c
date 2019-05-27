#include "printf.h"
#include <stdio.h>
char    *ft_space(long long i, t_conv *lst_fct)
{
    char *res;
    int d;
    int size;

    size = ft_strlen(lst_fct->final);
    d = lst_fct->champ;
    if (!(res = ft_strdup(lst_fct->final)))
        return (NULL);
    if (ft_strrchr(lst_fct->attribut, ' ') != NULL && i >= 0 && ft_strrchr(lst_fct->final, '-') == NULL && lst_fct->type != '%')
    {
        if (!(res = ft_strjoin_fr(" ", res, 2)))
            return (NULL);
        if (lst_fct->type == 'f')
        {
            ft_strdel(&lst_fct->final);
            lst_fct->final = ft_strdup(res);
        }
        size++;
    }
    if (ft_strrchr(lst_fct->attribut, '0') != NULL && (lst_fct->precision < 1 || lst_fct->type == 'f'))
    {
        ft_strdel(&res);
        return (lst_fct->final);
    }
    ft_strdel(&lst_fct->final);
    while (d > size && lst_fct->champ > 0)
    {
        if (!(res = ft_strjoin_fr(" ", res, 2)))
            return (NULL);
        d--;
    }
    while (size < (d * -1) && lst_fct->champ < 0)
    {
        if (!(res = ft_strjoin_fr(res, " ", 1)))
            return (NULL);
        size++;
    }
    return (res);
}

char    *ft_plus(t_conv *lst_fct)
{
    if (lst_fct->final == 0 && lst_fct->precision == 1)
    {
        ft_strdel(&lst_fct->final);
        lst_fct->final = ft_strdup("+");
        return (lst_fct->final);
    }
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
        if (!(res = ft_strsub(lst_fct->final, d, size)))
            return (NULL);
    }
    if ((lst_fct->type == 'x' || lst_fct->type == 'X') && ft_strrchr(lst_fct->attribut,'#') != NULL)
    {
        d = 1;
        if (!(res = ft_strsub(lst_fct->final, 2, size)))
            return (NULL);
    }
    else if (d == 0)
    {
        if (!(res = ft_strdup(lst_fct->final)))
            return (NULL);
    }
    while ((size < lst_fct->precision || size < lst_fct->champ))
    {
        if (!(res = ft_strjoin_fr("0", res, 2)))
            return (NULL);
        size++;
    }
    if (i < 0 || ft_strrchr(lst_fct->final, '-') != NULL) 
    {
         if (!(res = ft_strjoin_fr("-", res, 2)))
            return (NULL);
    }
    if (ft_strrchr(lst_fct->attribut, ' ') && i >= 0 && ft_strrchr(lst_fct->final, '-') == NULL)
    {
            if (!(res = ft_strjoin_fr(" ", res, 2)))
                return (NULL);
    }
    if (ft_strrchr(lst_fct->attribut, '+') && i >= 0 && ft_strrchr(lst_fct->final, '-') == NULL)
    {
        if (!(res = ft_strjoin_fr("+", res, 2)))
            return (NULL);
    }
    if ((lst_fct->type == 'x' || lst_fct->type == 'X') && ft_strrchr(lst_fct->attribut,'#'))
    {
        if (lst_fct->type == 'x')
        {
             if (!(res = ft_strjoin_fr("0x",res, 2)))
                return (NULL);
        }
        else
         {  
             if (!(res = ft_strjoin_fr("0X", res, 2)))
                return (NULL);
         }
    }
    ft_strdel(&lst_fct->final);
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
        return (ft_strdup(""));
   if (ft_strrchr(lst_fct->attribut, '#') && i != 0 && lst_fct->type == 'o')
        size++; 
    if (i < 0)
        size--;
     while (lst_fct->final[d] == ' ' || lst_fct->final[d] == '+' || lst_fct->final[d] == '-')      
    {
        d++;
        if (!(res = ft_strsub(lst_fct->final, d, size)))
            return (NULL);
    }
    if (d == 0)
        if (!(res = ft_strdup(lst_fct->final)))
            return (NULL);
    while (size < lst_fct->precision - 1)
    {
        if (!(res = ft_strjoin_fr("0", res, 2)))
            return (NULL);
        size++;
    }
    if (i < 0 && ft_strrchr(lst_fct->final, '-') != NULL)
        res = ft_strjoin_fr("-", res, 2);
    ft_strdel(&lst_fct->final);
    return (res);
}

char    *ft_hachtag(long long i, t_conv *lst_fct)
{
    if (lst_fct->type == 'o' && (i != 0 || ft_strlen(lst_fct->final) == 0))
         lst_fct->final = ft_strjoin_fr("0",lst_fct->final, 2);
    if (lst_fct->type == 'x' && i != 0)
       lst_fct->final = ft_strjoin_fr("0x",lst_fct->final, 2);
    if (lst_fct->type == 'X' && i != 0)
        lst_fct->final = ft_strjoin_fr("0X",lst_fct->final, 2);
    if (lst_fct->type == 'f' && lst_fct->precision <= 1)
        lst_fct->final = ft_strjoin_fr(lst_fct->final, ".", 1);
    return (lst_fct->final);
}

char   *ft_attribut(long long i, t_conv *lst_fct)
{
    if (lst_fct->type == 'f')
        lst_fct->precision--;
    if (lst_fct->final != NULL && lst_fct->precision != 0 && lst_fct->type != 'f')
      lst_fct->final = ft_precision(i, lst_fct);
   if (lst_fct->final != NULL && ft_strrchr(lst_fct->attribut, '+') && i >= 0 && ft_strrchr(lst_fct->final, '-') == NULL)
     lst_fct->final = ft_plus(lst_fct);
    if (lst_fct->final != NULL && ft_strrchr(lst_fct->attribut, '#') != NULL)
        lst_fct->final = ft_hachtag(i, lst_fct);
    if (lst_fct->final != NULL && (ft_strrchr(lst_fct->attribut, ' ') != NULL || lst_fct->champ != 0))
     lst_fct->final = ft_space(i, lst_fct);
    if (lst_fct->final != NULL && ft_strrchr(lst_fct->attribut, '0') && (lst_fct->precision < 1 || lst_fct->type == 'f'))
        lst_fct->final = ft_zero(i, lst_fct);
    return (lst_fct->final);
}