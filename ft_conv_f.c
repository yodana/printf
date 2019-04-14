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
#include <math.h>
double     ft_bi_to_dec(char *m)
{
    int i;
    double res;
    int power = 1;
    i = 0;
    res = 0;
    while(m[i])
    {
        res = res + ((m[i] - '0') * pow(2,-power));
        i++;
        power++;
    }
    printf("mantisse ? %.64f\n",res);
    return (res);
}
int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
    double i;
    (void)flags;
    (void)(*display);
    char *i_part;
    char *d_part;
    t_float *f;
    f = (t_float*)malloc(sizeof(t_float));
    i = va_arg(args, double);
    int d = (int)i;
    printf("tests == %d\n",d);
    i = i - (double)d;
    printf("| re == %f\n",i);
    printf("%s\n",ft_calc_i_bi(d));
    i_part = ft_calc_i_bi(d);
    printf("%s\n",ft_calc_d_bi(i));
    d_part = ft_calc_d_bi(i);
    char *bi_part;
    bi_part = malloc(sizeof(char) * (ft_strlen(i_part) + ft_strlen(d_part)) + 1);
    bi_part = ft_strjoin(i_part,d_part);
    char *exposant;
    exposant = ft_calc_i_bi(1023 + ft_strlen(i_part) - 1);
    f->mantisse = &bi_part[1];
    //ft_mantisse(bi_part);
        printf("toute la partie binaore == %s\n",bi_part);
        printf("matisse part == %s\n",f->mantisse);
        printf("exposant == %s\n",exposant);
   double res;
   res = ft_bi_to_dec(f->mantisse);
   double res_final;
   res_final = (1 + res) * pow(2,7);
    return (0);
}