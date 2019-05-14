#include "printf.h"

int		ft_char(va_list args, int flags, t_conv *lst_fct)
{
	char *res;

	res = ft_strnew(0);
	res[0] = va_arg(args, int);
	lst_fct->final = res;
	if (lst_fct->final[0] == '\0')
		ft_putchar(res[0]);
	ft_putstr(lst_fct->final);
	return (flags);
}

int		ft_str(va_list args, int flags, t_conv *lst_fct)
{
	char *str;
	
	if (!(str = va_arg(args, char*)))
		return (0);
	lst_fct->final = str;
	ft_putstr(lst_fct->final);
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
	ft_putstr(lst_fct->final);
	return (flags);
}