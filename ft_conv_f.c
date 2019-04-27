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

char    *ft_bi_comma(double res, int exposant)
{
    char *bi;
    int j;
    int i;
    int size;
    (void)exposant;
    if (exposant <= 64)
        size = 66;
    else
        size = exposant;
    i = 0;
    j = 0;
    j = (int)res;
    res = res - j;
    bi = ft_strnew(size);
    while (i != 64)
    {
        res = res * 2;
        j = (int)res;
        if (j == 0)
            bi[i] = '0';
        else
            bi[i] = '1';
        if (exposant == i)
         {
            i++;
            bi[i] = '.';
         }
        res = res - j;
        i++;
    }
    printf("bi == %s\n",bi);
    return (bi);
} 

long double ft_bi_to_tabd(char *res)
{
    int i;
    double power;
    long double res_final;

    res_final = 0;
    power = 5;
    i = 0;
    while (res[i] != '.')
        i++;
    power = i - 1;
    i = 0;
    while (res[i] != '.')
    {
        res_final = res_final + (res[i] - '0') * (double)ft_power(2,power);
        power--;
        i++;
    }
    return (res_final);
}

double ft_decimal(char *res)
{
    int i;
    double res_final;

    i = 0;
    res_final = 0;
    double power = 1;
   // while (res[i] != '.')
      //  i++;
    //i++;
    while (res[i])
    {
        res_final = res_final + (res[i] - '0') * (1 / (double)ft_power(2, power));
        power++;
        i++;
    }
    return (res_final);
}

char    *ft_joindouble(long double integer, double decimal)
{
    int i = 0;
    char *final = malloc(sizeof(char) * 10000000);
    int stop = 0;
    int j;
    (void)decimal;
    j = 0;
    while (integer >= 1)
     {
            integer = integer / 10;
            printf("integer == %Lf\n",integer);
            stop++;
     }
     printf("stop == %d\n",stop);
    while (i != stop)
    {
        integer = integer * 10;
        j = (int)integer;
        printf("integer dans stop == %Lf\n",integer);
        final[i] = (integer + '0');
        integer = integer - j;
        i++;
    }
    final[i] = '.';
    i++;
    stop = 0;
    while (stop != 6)
    {
        decimal = decimal * 10;
        j = (int)decimal;
        final[i] = decimal + '0';
        decimal = decimal - j;
        stop++;
        i++;
    }
    final[i] = '\0';
    return (final);
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
    char *res_final;
    d1.f = i;
    f->signe = d1.parts.sign;
    f->mantisse = ft_calc_i_bi(d1.parts.mantissa);
    printf("mantisse decimal == %llu\n",d1.parts.mantissa);
    printf("matissea before === %s\n",f->mantisse);
    printf("exposant before == %u\n",d1.parts.exponent);
    f->exposant = d1.parts.exponent - 16383;
    f->res_mantisse = ft_bi_to_dec(f->mantisse) + 1;
  printf("sign = %d\n", f->signe);
  printf("exponent = %d\n", f->exposant);
  printf("mantisa = %f\n", f->res_mantisse);
  res_final = ft_bi_comma(f->res_mantisse,f->exposant);
  long double tab_double = ft_bi_to_tabd(res_final);
    printf("tab double == %Lf\n",tab_double);
    int j = 0;
    while (res_final[j] != '.')
        j++;
        j++;
double decimal = ft_decimal(&res_final[j]);
printf("decinal == %.64f\n",decimal);
char *final = ft_joindouble(tab_double,decimal);
ft_putstr(final);
    return (0);
}
