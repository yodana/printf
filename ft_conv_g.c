#include "printf.h"
#include <stdio.h>


char    *ft_sup_zero(char *res)
{
    char *new; 
    int i;

    i = ft_strlen(res) - 1;
    while (res[i] == '0')
        i--;
    new = ft_strsub(res, 0, i + 1);
    ft_strdel(&res);
    return (new);
}

char *ft_g_science(t_float d1, t_conv *lst_fct)
{
    char		*res_final;
	char		*m_2;
    int size;

    lst_fct->precision--;
    if (d1.f < 1 && d1.f > -1 && d1.f != 0)
        lst_fct->final = ft_e_zero(lst_fct, d1);
    else
    {
        m_2 = ft_i_to_bi(d1.parts.m);
	    if ((size = ft_check_excep(d1.parts.e, m_2, d1.parts.sign, lst_fct)) != -1)
	    {
		    ft_strdel(&m_2);
		    return (NULL);
	    }
        res_final = ft_bi_to_dec(m_2, 0, 1, 66 + lst_fct->precision);
        res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
        lst_fct->final = ft_print_float(res_final, lst_fct, 0);
	    lst_fct->final = ft_scientific(lst_fct, lst_fct->final);
        ft_strdel(&m_2);
        ft_strdel(&res_final);
    }
    return (lst_fct->final);
}

int		ft_conv_g(t_conv *lst_fct, va_list args, int flags)
{
  t_float		d1;
    char		*res_final;
	char		*m_2;
	int			size;

    d1.f = flags == FL ? va_arg(args, long double) : va_arg(args, double);
    if (lst_fct->precision == 1)
        lst_fct->precision = 2; 
    lst_fct->precision = lst_fct->precision == 0 ? 7 : lst_fct->precision;
    if ((d1.parts.e - 16383) < -4 || ((d1.parts.e - 16383) >= lst_fct->precision - 1))
        lst_fct->final = ft_g_science(d1, lst_fct);
    else
    {
        m_2 = ft_i_to_bi(d1.parts.m);
        if ((size = ft_check_excep(d1.parts.e, m_2, d1.parts.sign, lst_fct)) != -1)
        {
            ft_strdel(&m_2);
            return (size);
        }
        res_final = ft_bi_to_dec(m_2, 0, 1, 66 + lst_fct->precision);
        res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
        lst_fct->final = ft_print_float(res_final, lst_fct, 0);
        lst_fct->final = ft_sup_zero(lst_fct->final);
        ft_strdel(&res_final);
	    ft_strdel(&m_2);
    }
    if (d1.parts.sign == 1)
            lst_fct->final = ft_strjoin_fr("-", lst_fct->final, 2);
	lst_fct->final = ft_attribut(d1.f, lst_fct);
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}