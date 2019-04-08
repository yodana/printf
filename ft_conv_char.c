#include "printf.h"
#include <stdio.h>
int		ft_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (0);
}

int		ft_str(va_list args)
{
	char *str;
	//printf("here");
	str = va_arg(args, char*);
	ft_putstr(str);
	return (0);
}

int		ft_pointer(va_list args)
{
	void  *p;
	p = va_arg(args, void *);
	ft_putstr("0x");
	ft_calc_hexa((unsigned long)p);
	return (0);
}