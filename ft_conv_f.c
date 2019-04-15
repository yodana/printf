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
    b = ft_strnew(53);
    while (i <= 52)
    {
        nbr = nbr * 2;
        if (nbr < 1)
        {
            b[i] = '0';
        }
        else
        {
            b[i] = '1';
            nbr = nbr - 1;
        }
        i++;
    }
    b[i] = '\0';
    return (b);
}

char *ft_calc_i_bi(int nbr)
{
    char *bi;
    int i = 0;
    bi = malloc(sizeof(char) * 1);
    while (nbr >= 1)
    {
        bi[i] = (nbr % 2) + '0';
        bi = ft_realloc(bi, i + 1);
        nbr = nbr / 2;
        i++;
    }
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

#include <math.h>
double     ft_bi_to_dec(char *m)
{
    int i;
    double res;
    double power = 1;
    i = 0;
    res = 0;
    while(m[i])
    {
        res = res + ((m[i] - '0') * (1 / ft_power(2, power)));
        i++;
        power++;
    }
    printf("mantisse ? %f\n",res);
    return (res);
}


void ft_dtoa(double nbr, int size)
{
    int i;

    i = 0;
    //while (nbr > 1)
       // nbr = nbr / 10;
    printf("float test = %.64f\n",nbr);
    while (i != size)
    {
        nbr = nbr * 10;
       //printf("float dans while = %f\n",nbr);
        i++;
    }
}

int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
    double i;
    (void)flags;
    (void)(*display);
    t_float *f;
    char *bi_part;
    f = (t_float*)malloc(sizeof(t_float));
    i = va_arg(args, double);
    int d = (int)i;
    printf("tests == %d\n",d);
    i = i - (double)d;
    printf("| re == %f\n",i);
    printf("%s\n",ft_calc_i_bi(d));
    printf("%s\n",ft_calc_d_bi(i));
    bi_part = ft_strjoin(ft_calc_i_bi(d),ft_calc_d_bi(i));
    int exposant;
    exposant = 1023 - ft_strlen(ft_calc_i_bi(d)) - 1;
    f->mantisse = &bi_part[1];
    //ft_mantisse(bi_part);
        printf("toute la partie binaore == %s\n",bi_part);
        printf("matisse part == %s\n",f->mantisse);
        printf("exposant == %d\n",exposant);
   double res;
   res = ft_bi_to_dec(f->mantisse);
   printf("test power = %f\n",(1 / (double)ft_power(2,3)));
   printf("reel power = %f\n",(1 / (double)pow(2,3)));
   double res_final;
   res_final = (1 + res) * ft_power(2,7);
   printf("%s\n",ft_itoa(res_final));
   ft_dtoa(res_final,64);
   return (0);
}