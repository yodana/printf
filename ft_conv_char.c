#include "printf.h"
#include <stdio.h>
int		ft_char(va_list args, int flags)
{
	char c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (flags);
}

int		ft_str(va_list args, int flags)
{
	char *str;
	//printf("here");
	str = va_arg(args, char*);
	ft_putstr(str);
	return (flags);
}

int		ft_pointer(va_list args, int flags)
{
	void  *p;
	p = va_arg(args, void *);
	ft_putstr("0x");
	ft_calc_hexa((unsigned long)p);
	return (flags);
}