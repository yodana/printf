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
    b = ft_strnew(54);
    while (i < 54)
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

char *ft_calc_i_bi(int nbr)
{
    char *bi;
    int i = 0;
    bi = malloc(sizeof(char) * 1);
    while (nbr >= 1)
    {
        bi[i] = (nbr % 2) + '0';
        //bi = ft_realloc(bi, i + 1);
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

int     ft_test(double i)
{
    if (i * 10 >= 10)
        return 1;
    return 0;
}
void ft_dtoa(int d, double i, int size)
{
    int k;

    k = 0;
    int j;
    int comma;

    comma = ft_strlen(ft_itoa(d));
    char *res;
    res = malloc(sizeof(char) * (size + comma + 1));
    j = 0;
    res = ft_itoa(d);
    k = comma;
   // nbr = nbr * 10;
    //ft_putnbr(nbr);
    while (k - comma != size)
    {
        i = i * 10;
        j = (int)i;
        res[k] = j  + '0';
        k++;
        /*(if (k == size)
        {
            i = i - j;
            i = i * 10;
            if (i >= 5)
                j++;
        }*/
       // ft_putnbr(j);
       i = i - j;
       j = 0;
    }
    res[k] ='\0';
    printf("res == %s",res);
    char *rev_res = ft_strrev_fr(res);
    k = 0;
    while(rev_res[0] == '9'  || rev_res[k] == '9' + 1)
    {
        rev_res[k] = '0';
        rev_res[k + 1] = rev_res[k + 1] + 1;
        k++;
    }
    printf("res == %s",ft_strrev_fr(rev_res));
}

int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
    double i;
    (void)flags;
    (void)(*display);
    /*char *bi_part;
    f = (t_float*)malloc(sizeof(t_float));*/
    i = va_arg(args, double);
    int d = (int)i;
    i = i - (double)d;
    printf("i == %f\n",i);
    /*bi_part = ft_strjoin(ft_calc_i_bi(d),ft_calc_d_bi(i));
    int exposant;
    exposant = ft_strlen(ft_calc_i_bi(d)) - 1;
    f->mantisse = &bi_part[1];
    double res;
    res = ft_bi_to_dec(f->mantisse);
    double res_final;
    res_final = (1 + res) * ft_power(2,(double)exposant);*/
    ft_dtoa(d, i, 6);
   // printf("example = %d",j);
    return (0);
}