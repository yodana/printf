#include "printf.h"

int		ft_char(va_list args, int flags, t_conv *lst_fct)
{
	char *res;

	res = ft_strnew(0);
	res[0] = va_arg(args, int);
	lst_fct->final = res;
	lst_fct->final = ft_space(1, lst_fct);
	if (res[0] == '\0')
	{
		ft_putstr(lst_fct->final);
		ft_putchar(res[0]);
	}
	ft_putstr(lst_fct->final);
	return (flags);
}

int		ft_str(va_list args, int flags, t_conv *lst_fct)
{
	char *str;
	
	str = va_arg(args, char*);
	if (str != NULL)
	{
	lst_fct->final = ft_strdup(str);
	lst_fct->final = ft_space(1, lst_fct);
	ft_putstr(lst_fct->final);
	}
	else
		ft_putstr(NULL);
	return (flags);
}

int		ft_pointer(va_list args, int flags, t_conv *lst_fct)
{
	void  *p;
	char *res;

	res = ft_strnew(0);
	(void)lst_fct;
	p = va_arg(args, void *);
	res = ft_strjoin_fr("0x", res, 2);
	res = ft_strjoin_fr(res, ft_calc_hexa((unsigned long)p), 3);
	lst_fct->final = res;
	lst_fct->final = ft_space(1, lst_fct);
	ft_putstr(lst_fct->final);
	return (flags);
}