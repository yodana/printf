#include "printf.h"
#include <stdio.h>

void    ft_conv_wf_2(va_list args, int flags, void(*display)(long long))
{  
   unsigned short int hd;
   unsigned char hhd;
   unsigned long ld;
   unsigned long long lld;

   if (flags == HH)
    {
       hhd = ( unsigned char)va_arg(args,  unsigned  char*);
       display(hhd);
    }
    else if (flags == H)
    {
       hd = ( unsigned short)va_arg(args,  unsigned int);
       display(hd);
    }    
    else if (flags == L)
    {
       ld = (unsigned long)va_arg(args,  unsigned long);
       display(ld);
    }
    else if (flags == LL)
    {
        lld = (unsigned long long)va_arg(args,  unsigned long long);
         display(lld);
    }
}

int    ft_conv_2(va_list args, int flags, t_conv *lst_fct)
{
   unsigned int d;
   
   if (ft_strlen(lst_fct->attribut) != 0)
      ft_attribut(args, lst_fct);
   if (flags > 0)
   {
      ft_conv_wf_2(args, flags, lst_fct->display);
      return (0);
   }
   d = (unsigned int)va_arg(args, unsigned int);
   lst_fct->display(d);
   return (0);
}

void    ft_conv_wf(va_list args, int flags, void(*display)(long long))
{  
   short int hd;
   char hhd;
   long ld;
   long long lld;

   if (flags == HH)
    {
       hhd = (char)va_arg(args, char*);
       display(hhd);
    }
    else if (flags == H)
    {
       hd = (short)va_arg(args, int);
       display(hd);
    }    
    else if (flags == L)
    {
       ld = (long)va_arg(args, long);
       display(ld);
    }
    else if (flags == LL)
    {
        lld = (long long)va_arg(args, long long);
         display(lld);
    }
}

int    ft_conv(va_list args, int flags, t_conv *lst_fct)
{
   int d;
     
   if (flags > 0)
   {
      ft_conv_wf(args, flags, lst_fct->display);
      return (0);
   }
   d = (int)va_arg(args, int);
   printf("attribut == %d",d);
   lst_fct->display(d);
   return (0);
}