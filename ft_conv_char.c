#include "printf.h"

int		ft_char(va_list args, int flags, t_conv *lst_fct)
{
	char *res;
	int size;

	size = 0;
	(void)flags;
	res = ft_strnew(1);
	res[0] = va_arg(args, int);
	lst_fct->final = ft_strdup(res);
	lst_fct->final = ft_space(1, lst_fct);
	if (res[0] == '\0')
	{
		ft_putstr(lst_fct->final);
		ft_putchar(res[0]);
		size++;
	}
	size = size + ft_strlen(lst_fct->final);
	ft_putstr(lst_fct->final);
	ft_strdel(&res);
	ft_strdel(&lst_fct->final);
	return (size);
}

int		ft_str(va_list args, int flags, t_conv *lst_fct)
{
	char *str;
	int size;

	(void)flags;
	str = va_arg(args, char*);
	if (lst_fct->precision != 1 && str != NULL)
	{
		if (lst_fct->precision == 0)
			lst_fct->final = ft_strsub(str, 0, ft_strlen(str) + 1);
		else
			lst_fct->final = ft_strsub(str, 0, lst_fct->precision - 1);
	}
	else if (lst_fct->precision == 1 && str != NULL)
		lst_fct->final = ft_strnew(0);
	else if (lst_fct->precision != 1)
		lst_fct->final = ft_strdup("(null)");
	else
		lst_fct->final = ft_strdup("");
	lst_fct->final = ft_space(1, lst_fct);
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}

int		ft_pointer(va_list args, int flags, t_conv *lst_fct)
{
	void  *p;
	char *res;
	int size;

	(void)flags;
	(void)res;
	p = va_arg(args, void *);
	res = ft_strnew(0);
	res = ft_strjoin_fr("0x", res, 2);
	res = ft_strjoin_fr(res, ft_calc_hexa((unsigned long)p), 3);
	lst_fct->final = res;
	lst_fct->final = ft_space(1, lst_fct);
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}