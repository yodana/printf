#include "printf.h"

int		ft_char(va_list args, int flags, t_conv *lst_fct)
{
	char c;

	(void)(lst_fct);
	c = va_arg(args, int);
	ft_putchar(c);
	return (flags);
}

int		ft_str(va_list args, int flags, t_conv *lst_fct)
{
	char *str;
	
	(void)(lst_fct);
	if (!(str = va_arg(args, char*)))
		return (0);
	ft_putstr(str);
	return (flags);
}

int		ft_pointer(va_list args, int flags, t_conv *lst_fct)
{
	void  *p;

	(void)(lst_fct);
	p = va_arg(args, void *);
	ft_putstr("0x");
	ft_calc_hexa((unsigned long)p);
	return (flags);
}