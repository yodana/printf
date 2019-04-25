#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef union {
  long double f;
  struct {
  unsigned long long int mantissa:64;
	unsigned int exponent:15;
	unsigned int sign:1;
    unsigned int empty:16;
  } parts;
} float_cast;

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
char *ft_calc_i_bi(unsigned long long nbr)
{
    char *bi;
    int i = 0;
    bi = malloc(sizeof(char) *  64 + 1);
    while (nbr >= 1)
    {
        bi[i] = (nbr % 2) + '0';
        //bi = ft_realloc(bi, i + 1);
        nbr = nbr / 2;
        i++;
    }
    //bi[0] = '.';
    bi[i] = '\0';
    bi = strrev(bi);
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
        res = res + ((m[i] - '0') * (1 / (double)pow(2, power)));
        i++;
        power++;
    }
    return (res);
}

char *ft_calc_d_bi(double nbr)
{
    char *b;

    int i = 0;
    int i_nbr = nbr;
    b = malloc(sizeof(char) *  64 + 1);;
    while (i < 64)
    {   
        if (i_nbr < 10)
        {
            b[i] = '0';
        }
        else
        {
            b[i] = '1';
            i_nbr = i_nbr - 10;
        }
        i_nbr = i_nbr * 10;
        i++;
    }
    b[i] = '\0';
    return (b);
}
int main(void) 
{
    double i = 234.42;
    int biais = 16383;
    char *m;
  float_cast d1 = { .f = i };
  printf("sign = %x\n", d1.parts.sign);
  printf("exponent = %d\n", d1.parts.exponent);
  printf("mantisa = %llu\n", d1.parts.mantissa);
  unsigned int exposant = d1.parts.exponent - biais;
  m = ft_calc_i_bi(d1.parts.mantissa);
  printf("matisse = %s\n",m);
  printf("reel exponant = %u\n",exposant);
  double res_mantisse = ft_bi_to_dec(m) + 1;
  printf("res_mantisse == %f\n",res_mantisse);
  char *b = ft_calc_d_bi(res_mantisse);
  printf("matisse final binaire == %s\n",b);
 // printf("resultat i == %.9f\n",i);
}