#include "printf.h"
#include <stdio.h>

char    *ft_realloc(char *buf, int new)
{
    char *tmp;
    int i;

    i = 0;
    tmp = malloc(sizeof(char) * new);
    while (buf[i])
    {
        tmp[i] = buf[i];
        i++;
    }
    tmp[i] = '\0';
    ft_strdel(&buf);
    buf = ft_strdup(tmp);
    ft_strdel(&tmp);
    return (buf);
}

char *ft_calc_d_bi(double nbr)
{
    char *b;

    int i = 0;
    int i_nbr = nbr * 10;
    b = ft_strnew(65);
    while (i < 65)
    {
        i_nbr = i_nbr * 2;   
        if (i_nbr < 10)
        {
            b[i] = '0';
        }
        else
        {
            b[i] = '1';
            i_nbr = i_nbr - 10;
        }
        i++;
    }
    b[i] = '\0';
    return (b);
}

char *ft_calc_i_bi(unsigned long long nbr)
{
    char *bi;
    int i = 0;
    bi = malloc(sizeof(char) * 64 + 1);
    while (nbr >= 1)
    {
        bi[i] = (nbr % 2) + '0';
        //bi = ft_realloc(bi, i + 1);
        nbr = nbr / 2;
        i++;
    }
    //bi[0] = '.';
    bi[i] = '\0';
    bi = ft_strrev_fr(bi);
    return (bi);
}

double         ft_power(double nbr, double power)
{
    int i;
    double res;

    res = 1;
    i = 1;
    while (i <= power)
    {
        res = res * nbr;
        i++;
    }
    return (res);
}

double     ft_bi_to_dec(char *m)
{
    int i;
    double res;
    double power = 1;
    i = 0;
    res = 0;
    while(m[i])
    {
        res = res + ((m[i] - '0') * (1 / (double)ft_power(2, power)));
        i++;
        power++;
    }
    return (res);
}

void ft_putfloat(char *res, int comma)
{
    int i;

    i = 0;
    while (res[i])
    {
        if (i == comma)
            ft_putchar('.');
        ft_putnbr(res[i] - '0');
        i++;
    }
}

void ft_dtoa(long long d, long double i, int size, int signe)
{
    int k;

    k = 0;
    int j;
    int comma;

    comma = ft_strlen(ft_itoa(d));
    char *res;
    res = malloc(sizeof(char) * (size + comma + 1));
    j = 0;
    //ft_putnbr(d);
    res = ft_itoa(d);
    k = comma;
    if (signe == 0)
        ft_putchar('-');
    while (k - comma != size)
    {
        i = i * 10;
        j = (int)i;
        res[k] = j  + '0';
        k++;
       i = i - (double)j;
       j = 0;
    }
    res[k] ='\0';
    char *rev_res = ft_strrev_fr(res);
    k = 0;
    while((rev_res[0] == '9'  || rev_res[k] == '9' + 1) && size <= 6)
    {
        rev_res[k] = '0';
        rev_res[k + 1] = rev_res[k + 1] + 1;
        k++;
    }
     ft_putfloat(ft_strrev_fr(rev_res),comma);
}

int     ft_test_nan(long long d)
{
    long long test;
    test = d;
    printf("before == %lld\n",d);
    if (d < 0)
        d = d * -1;
    printf("after == %lld\n",d);
    if (test < 0 && test == d)
        return (1);
    return (0);
}


int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
    double i;
    t_float *f;
    float_cast d1;

    f = (t_float*)malloc(sizeof(t_float));
    (void)flags;
    (void)(*display);    
    i = va_arg(args, double);
    /*f (i < 0)
    {
        signe = 0;
        i = i * -1;
    }
    else
        signe = 1;*/
    d1.f = i;
    f->signe = d1.parts.sign;
    f->mantisse = ft_calc_i_bi(d1.parts.mantissa);
    printf("matissea before === %s",f->mantisse);
    f->exposant = d1.parts.exponent - 16383;
    f->res_mantisse = ft_bi_to_dec(f->mantisse) + 1;
  printf("sign = %d\n", f->signe);
  printf("exponent = %d\n", f->exposant);
  printf("mantisa = %f\n", f->res_mantisse);
    //i = i - d;
    //bi_part = ft_calc_i_bi(d);
    //printf("size of == %lu\n",sizeof(long double));
    //printf("bi_part == %s\n",bi_part);
    //if (ft_test_nan(d) == 1)
    //{
     //   ft_putstr("nan\n");
      //  return (0);
    //}
   // printf("d == %lld\n",d);
    //bi_part = ft_strjoin(ft_calc_i_bi(d),ft_calc_d_bi(i));
    //printf("bi_part == %s\n",bi_part);
   /* f->exposant = 1023 + ft_strlen(ft_calc_i_bi(d)) - 1;
    f->mantisse = &bi_part[1];
    //printf("mantisse == %s\n",f->mantisse);
    //printf("exposant == %d\n",f->exposant);
   if (f->exposant == 1023 && signe == 0 && i >= 1)
    {
        ft_putstr("-inf");
        return (0);
    }
    else if (f->exposant == 1023 && signe == 1 && i >= 1)
     {
        ft_putstr("inf");
        return (0);
     }
    ft_dtoa(d, i, 6, signe);*/
    return (0);
}
