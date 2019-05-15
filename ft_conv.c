#include "printf.h"
#include <stdio.h>

void    ft_conv_wf_2(va_list args, int flags, t_conv *lst_fct)
{  
   unsigned short int hd;
   unsigned char hhd;
   unsigned long ld;
   unsigned long long lld;

   if (flags == HH)
    {
       hhd = (unsigned char)va_arg(args,  unsigned  char*);
       lst_fct->final = lst_fct->display(hhd);
       lst_fct->final = ft_attribut(hhd, lst_fct);
    }
    else if (flags == H)
    {
       hd = (unsigned short)va_arg(args,  unsigned int);
       lst_fct->final = lst_fct->display(hd);
       lst_fct->final = ft_attribut(hd, lst_fct);
    }
    else if (flags == L)
    {
       ld = (unsigned long)va_arg(args,  unsigned long);
       lst_fct->final = lst_fct->display(ld);
       lst_fct->final = ft_attribut(ld, lst_fct);
    }
    else if (flags == LL)
    {
      lld = (unsigned long long)va_arg(args,  unsigned long long);
      lst_fct->final = lst_fct->display(lld);
      lst_fct->final = ft_attribut(lld, lst_fct);
    }
    ft_putstr(lst_fct->final);
}

int    ft_conv_2(va_list args, int flags, t_conv *lst_fct)
{
   unsigned int d;
   
   if (flags > 0)
   {
      ft_conv_wf_2(args, flags, lst_fct);
      return (0);
   }
   d = (unsigned int)va_arg(args, unsigned int);
   lst_fct->final = lst_fct->display(d);
   lst_fct->final = ft_attribut(d, lst_fct);
   ft_putstr(lst_fct->final);
   return (0);
}

void    ft_conv_wf(va_list args, int flags, t_conv *lst_fct)
{  
   short int hd;
   char hhd;
   long ld;
   long long lld;

   if (flags == HH)
    {
       hhd = (char)va_arg(args, char*);
       lst_fct->final = lst_fct->display(hhd);
       lst_fct->final = ft_attribut(hhd, lst_fct);
    }
    else if (flags == H)
    {
       hd = (short)va_arg(args, int);
       lst_fct->final = lst_fct->display(hd);
       lst_fct->final = ft_attribut(hd, lst_fct);
    }    
    else if (flags == L)
    {
       ld = (long)va_arg(args, long);
       lst_fct->final = lst_fct->display(ld);
       lst_fct->final = ft_attribut(ld, lst_fct);
    }
    else if (flags == LL)
    {
        lld = (long long)va_arg(args, long long);
         lst_fct->final = lst_fct->display(lld);
         lst_fct->final = ft_attribut(lld, lst_fct);
    }
    ft_putstr(lst_fct->final);
}

int    ft_conv(va_list args, int flags, t_conv *lst_fct)
{
   int d;
     
   if (flags > 0)
   {
      ft_conv_wf(args, flags, lst_fct);
      return (0);
   }
   d = (int)va_arg(args, int);
   lst_fct->final = lst_fct->display(d);
   lst_fct->final = ft_attribut(d, lst_fct);
   ft_putstr(lst_fct->final);
   return (0);
}