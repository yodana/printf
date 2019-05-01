#include "printf.h"
#include <stdio.h>

char *ft_calc_i_bi(unsigned long long nbr)
{
    char *bi;
    int i = 0;
    bi = malloc(sizeof(char) * 64 + 1);
    while (nbr >= 1)
    {
        bi[i] = (nbr % 2) + '0';
        nbr = nbr / 2;
        i++;
    }
    bi[i] = '\0';
    bi = ft_strrev_fr(bi);
    return (bi);
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
            stop++;
     }
    while (i != stop)
    {
        integer = integer * 10;
        j = (int)integer;
        //printf("integer dans stop == %.64Lf || j == %d\n",integer,j);
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

char    *ft_dtoa(long double mantisse)
{

    int i;
    char *res;
    int j;

    i = 0;
    j = 0;
    res = ft_strnew(65);
    j = (int)mantisse;
    while (i != 65)
    {
        if (i == 1)
        {
            res[i] = '.';
            i++;
        }
        res[i] = j + '0';
        mantisse = mantisse - j;
        mantisse = mantisse * 10;
        j = (int)mantisse;
        i++;
    }
    return (res);
}

void    ft_print_float(char *res, int precision, int sign)
{
    int i;
    int stop;
    char *print;
    int comma;

    comma = 0;
    stop = 0;
    i = 0;
    print = ft_strnew(316);
    while (res[i] != '.')
    {
        print[i] = res[i];
        i++;
        comma++;
    }
    while (stop != precision + 2)
    {
         print[i] = res[i];
         stop++;
         i++;
    }
    i--;
    if (print[i] >= '5')
    {
        i--;
        while (i != 0 && (print[i] == '9' || print[i] == '.'))
        {
            if (print[i] != '.')   
                print[i] = '0';
            i--;
        }
        if (print[i] == '9' && i == 0)
        {
            print[i] = '0';
            print = ft_strjoin_fr("1",print,2);
        }
        else
            print[i] = print[i] + 1;
    }
    if (sign == 1)
        ft_putchar('-');
    res = ft_strsub(print, 0, comma + precision + 1);
    ft_putstr(res);
}

char    *ft_calc_exposant_neg(char *res, unsigned int exposant)
{
    int i;
    int j;
    int hold;
    int stop;
    
    hold = 0;
    i = 0;
    stop = exposant * -1;
    while (stop + 1 > 0)
    {
        while (res[i])
        {
            j = (hold + (res[i] - '0')) / 2;
            printf("j == %d\n",j);
            if (j >= 0)
                res[i] = (j % 10 + '0');
            if ((res[i] - '0') % 2 != 0)
                hold = 10;
            else
                hold = 0;
            i++;
        }
        if (hold == 10)
            res = ft_strjoin_fr(res, "5", 1);
        hold = 0;
        i = 0;
        stop--;
    }
    return (res);
}
char    *ft_calc_exposant_pos(char *res, int exposant)
{
    int i;
    int j;
    int hold;

    i = ft_strlen(res) - 1;
    hold = 0;
    while (exposant + 1 != 0)
    {
        while (i >= 0)
        {
            j = (res[i] - '0') * 2;
            if (j >= 0)
                res[i] = (j % 10 + '0') + hold;
            if (j >= 10)
                hold = 1;
            else if (j >= 0)
                hold = 0;
            if (i == 0 && j >= 10)
                res= ft_strjoin_fr("1",res, 2);
            i--;
        }
        i = ft_strlen(res) - 1;
        hold = 0;
        printf("exposant dans while == %d\n",exposant);
        exposant--;
    }
    return (res);
}

int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
    long double i;
    t_float *f;
    float_cast d1;
    char *final;
    char *res_final;

    f = (t_float*)malloc(sizeof(t_float));
    (void)flags;
    (void)(*display);    
    i = va_arg(args, double);
    d1.f = i;
    f->signe = d1.parts.sign;
    f->mantisse = ft_calc_i_bi(d1.parts.mantisse);
    f->exposant = d1.parts.exponent - 16383;
    f->res_mantisse = ft_bi_to_dec(f->mantisse);
    res_final = ft_dtoa(f->res_mantisse);
    printf("mantisse %s\n",res_final);
    printf("exposant == %u\n",f->exposant);
    final = ft_calc_exposant_neg(res_final,f->exposant);
    printf("final dans == %s\n",final);
    //final = ft_calc_exposant_pos(res_final,f->exposant);
    //ft_print_float(final, 6, f->signe);
    return (0);
}
