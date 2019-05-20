/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:38:25 by yodana            #+#    #+#             */
/*   Updated: 2019/04/01 15:39:15 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
/*int main()
{
	char	*a = "trolol";
	char	b = '~';
	long long c = 9223372036854775807;
	short int d = 32767;
	printf("reel printf: %c\n",'d');
	ft_printf("mine: %c\n\n",'d');

	printf("reel printf:  %s\n","lol");
	ft_printf("mine:  %s\n\n","lol");

	printf("reel printf:  caratctere = %c || chaine = %s\n",'d',"lol");
	ft_printf("mine:  caractere = %c || chaine = %s\n\n",'d',"lol");

	printf("reel printf: pointer -> %p\n",&a);
	ft_printf("mine: pointer -> %p\n\n",&a);

	printf("reel printf: d -> %d\n",2147483647);
	ft_printf("mine : d -> %d\n\n",2147483647);

	printf("reel printf: hhd -> %hhd\n",b);
	ft_printf("mine : hhd -> %hhd\n\n",b);

	printf("reel printf: d -> %d\n",-1);
	ft_printf("mine : d -> %d\n\n",-1);

	printf("reel printf: hd -> %hd\n",d);
	ft_printf("mine : hd -> %hd\n\n",d);

	printf("reel printf: ld -> %ld\n",2147483650);
	ft_printf("mine : ld -> %ld\n\n",2147483650);

	printf("reel printf: lld -> %lld\n",c);
	ft_printf("mine : lld -> %lld\n\n",c);

	printf("reel printf: i -> %i\n",033);
	ft_printf("mine : i -> %i\n\n",033);
	
	printf("reel printf: hi -> %hi\n",d);
	ft_printf("mine : hi -> %hi\n\n",d);

	printf("reel printf: li -> %li\n",2147483650);
	ft_printf("mine : li -> %li\n\n",2147483650);

	printf("reel printf: lli -> %lli\n",c);
	ft_printf("mine : lli -> %lli\n\n",c);

	printf("reel printf: o -> %o\n",33);
	ft_printf("mine : o -> %o\n\n",33);

	printf("reel printf: o -> %o\n",27);
	ft_printf("mine : o -> %o\n\n",27);

	printf("reel printf: o -> %o\n",-1);
	ft_printf("mine : o -> %o\n\n",-1);

	 printf("reel printf: ho -> %ho\n",d);
	ft_printf("mine : ho -> %ho\n\n",d);

	printf("reel printf: hho -> %hho\n",b);
	ft_printf("mine : hho -> %hho\n\n",b);

	printf("reel printf: lo -> %lo\n",2147483650);
	ft_printf("mine : lo -> %lo\n\n",2147483650);

	printf("reel printf: u -> %u\n",-1);
	ft_printf("mine : u -> %u\n\n",-1);

	printf("reel printf: hu -> %hu\n",d);
	ft_printf("mine : hu -> %hu\n\n",d);

	printf("reel printf: hhu -> %hhu\n",b);
	ft_printf("mine : hhu -> %hhu\n\n",b);

	printf("reel printf: lu -> %lu\n",2147483650);
	ft_printf("mine : lu -> %lu\n\n",2147483650);

	printf("reel printf: llu -> %llu\n",c);
	ft_printf("mine : llu -> %llu\n\n",c);

	printf("reel printf: x -> %x\n",2000);
	ft_printf("mine : x -> %x\n\n",2000);

	printf("reel printf: hx -> %hx\n",d);
	ft_printf("mine : hx -> %hx\n\n",d);

	printf("reel printf: hhx -> %hhx\n",b);
	ft_printf("mine : hhx -> %hhx\n\n",b);

	printf("reel printf: lx -> %lx\n",2147483650);
	ft_printf("mine : lx -> %lx\n\n",2147483650);

	printf("reel printf: llx -> %llx\n",c);
	ft_printf("mine : llx -> %llx\n\n",c);
	
	printf("reel printf: X -> %X\n",2000);
	ft_printf("mine : X -> %X\n\n",2000);

	printf("reel printf: hX -> %hX\n",d);
	ft_printf("mine : hX -> %hX\n\n",d);

	printf("reel printf: hhX -> %hhX\n",b);
	ft_printf("mine : hhX -> %hhX\n\n",b);

	printf("reel printf: lX -> %lX\n",2147483650);
	ft_printf("mine : lX -> %lX\n\n",2147483650);

	printf("reel printf: llX -> %llX\n",c);
	ft_printf("mine : llX -> %llX\n\n",c);

	double i = 253.99999;
	float k = 253.999999;
	double inf = 1.0/0.0;
	double inf_neg = -1.0/0.0;
	double test2 = 1.0/10;
	double zero = 0;
	double not_number = sqrt(-1);
	
	printf("reel printf: f -> %f\n",i);
	ft_printf("mine :    f -> %f\n\n",i);

	printf("reel printf: f -> %f\n",0.0);
	ft_printf("mine:     f -> %f\n\n",0.0);

	printf("reel printf : f -> %f\n",inf);
	ft_printf("mine : f -> %f\n\n",inf);

	printf("reel printf : f -> %f\n",inf_neg);
	ft_printf("mine : f -> %f\n\n",inf_neg);

	printf("reel printf : f -> %f\n",not_number);
	ft_printf("mine : f -> %f\n\n",not_number);
	printf("reel printf : f -> %f\n",test2);
	ft_printf("mine : f -> %f\n\n",test2);

	printf("reel printf : f -> %f\n",zero);
	ft_printf("mine : f -> %f\n\n",zero);

	printf("reel printf : f -> %f\n",k);
	ft_printf("mine : f -> %f\n\n",k);
	printf("reel printf : f -> %f\n",-92.0);
	ft_printf("mine : f -> %f\n\n",-92.0);

	printf("reel printf : f -> %f\n",-9223372036854775808.0);
	ft_printf("mine : f -> %f\n\n",-9223372036854775808.0);
	printf("reel printf : f -> %f\n",42.42);
	ft_printf("mine : f -> %f\n\n",42.42);

	printf("reel printf : f -> %f\n",0.1);
	ft_printf("mine : f -> %f\n\n",0.1);
	
	printf("reel print : f -> %f\n",253.999999);
	ft_printf("mine : f -> %f\n\n",253.999999);
	printf("reel printf : f -> %f\n",42.25648985585);
	ft_printf("mine : f -> %f\n\n",42.25648985585);
	double maxi = DBL_MAX;
	
	printf("reel printf : f ->%f\n",maxi + 10);
	ft_printf("mine: f -> %f\n\n",maxi + 10);
	float t = 23.9999999;
	printf("reel printf : lf ->%f\n",t);
	ft_printf("mine : lf-> %f\n\n",t);
	
	printf("reel printf : f-> %f\n",-0.1);
	ft_printf("mine : f -> %f\n\n",-0.1);
	long double l = LDBL_MAX;
	printf("mine: f ->%Lf\n",l);
	ft_printf("mine: f->%Lf\n",l);

	printf("reel printf : spe -> %%\n");
	ft_printf("mine : spe -> %%\n\n");

	printf("real : # with o -> %#o\n",0);
	ft_printf("mine : # with o -> %#o\n\n",0);

	printf("real : # with o -> %#o\n",-1);
	ft_printf("mine : # with o -> %#o\n\n",-1);
	
	printf("real : # with x -> %#x\n",0);
	ft_printf("mine : # with x -> %#x\n\n",0);

	printf("real : # with x -> %#x\n",192);
	ft_printf("mine : # with x -> %#x\n\n",192);

	printf("real : # with X -> %#X\n",0);
	ft_printf("mine : # with X -> %#X\n\n",0);

	printf("real : # with X -> %#X\n",192);
	ft_printf("mine : # with X -> %#X\n\n",192);

	printf("reel : # with f -> %#f\n",10.0);
	ft_printf("mine : # with f -> %#f\n\n",10.0);

	printf("reel : 0 with d -> %0d\n",1);
	ft_printf("mine : 0 with d -> %0d\n\n",1);


	printf("reel : + with d -> %+d\n",2);
	ft_printf("mine : + with d -> %+d\n\n",2);


	printf("\nreel : espace with d -> % d|\n",0);
	ft_printf("mine : espace with d -> % d|\n\n",0);

	printf("reel : champ with d -> % 5d|\n",10);
	ft_printf("mine : champ with d -> % 5d|\n\n",10);

	printf("reel : champ and - with d -> %-5d|\n",10);
	ft_printf("mine : champ and - with d -> %-5d|\n\n",10);

	printf("reel : champ and - with d neg -> %5d|\n",-10);
	ft_printf("mine : champ and - with d neg -> %5d|\n\n",-10);

	printf("reel : champ and + with d -> %+5d|\n",10);
	ft_printf("mine : champ and + with d -> %+5d|\n\n",10);

	printf("reel : champ and + with d neg -> %20x|\n",-10);
	ft_printf("mine : champ and + with d neg -> %20x|\n\n",-10);

	printf("reel : champ with c -> %5c|\n",'s');
	ft_printf("mine : champ with c -> %5c|\n\n",'s');

	printf("reel : champ and - with c -> %-5c|\n",'s');
	ft_printf("mine : champ and - with c -> %-5c|\n\n",'s');

	printf("reel : champ with s -> %5s|\n","lol");
	ft_printf("mine : champ with s -> %5s|\n\n","lol");

	printf("reel : champ and - with s -> %-5s|\n","lol");
	ft_printf("mine : champ and - with s -> %-5s|\n\n","lol");

	int o = 10;
	printf("reel : champ with p -> %30p|\n",&o);
	ft_printf("mine : champ with p -> %30p|\n\n",&o);

	printf("reel : champ and - with p -> %-30p|\n",&o);
	ft_printf("mine : champ and - with p -> %-30p|\n\n",&o);

	printf("reel : champ and + and # with d -> %#5x|\n",10);
	ft_printf("mine : champ and + and # with d -> %#5x|\n\n",10);

	printf("reel : champ and # and - with d -> %#-5x|\n",10);
	ft_printf("mine : champ and # and - with d -> %#-5x|\n\n",10);

	printf("reel : champ with f -> %f|\n",1.0);
	ft_printf("mine : champ with f -> %f|\n\n",1.0);

	printf("reel : champ and + with f -> % 010f|\n",1.0);
	ft_printf("mine : champ and + with f -> % 010f|\n\n",1.0);

	printf("reel : champ with f -> %10f|\n",1.0);
	ft_printf("mine : champ with f -> %10f|\n\n",1.0);

	printf("reel : champ with f -> %-30f|\n",-1.0);
	ft_printf("mine : champ with f -> %-30f|\n\n",-1.0);

	printf("reel : champ and 0 with d -> %05d|\n",10);
	ft_printf("mine : champ amd 0 with d -> %05d|\n\n",10);

	printf("reel : champ with c -> %5c|\n",'p');
	ft_printf("mine : champ with c -> %5c|\n\n",'p');

	printf("reel : champ and 0 with f -> % 020f|\n",-10.0);
	ft_printf("mine : champ and 0 with f -> % 020f|\n\n",-10.0);

	printf("reel : precision with d -> %10.05d|\n",-10);
	ft_printf("mine : precision with d -> %10.05d|\n\n",-10);
	
	printf("reel : precision with s-> %.5s|\n","10");
	ft_printf("mine : precision with s-> %.5s|\n","10");
	
	//printf("reel : precision with f -> %.5f|\n",10.0);

	return (0);
}*/

int		main()
{
	int		nb;
	
	nb = -45;

	ft_printf("----------ft_printf-test-i-d----------\n");

	ft_printf("space% i|\n", nb);
	printf("space% i|\n", nb);
	ft_printf("plus:%+i|\n", nb);
	printf("plus:%+i|\n", nb);
	ft_printf("precision:%.5i|\n", nb);
	printf("precision:%.5i|\n", nb);
	ft_printf("space + prec:% .5i|\n", nb);
	printf("space + prec:% .5i|\n", nb);
	ft_printf("Plus + prec / grande:%+.5i|\n", nb);
	printf("Plus + prec / grande:%+.5i|\n", nb);
	ft_printf("Prec + 0:%0.5i|\n", nb);
	printf("Prec + 0:%0.5i|\n", nb);
	ft_printf("Prec + minus:%-.5i|\n", nb);
	printf("Prec + minus:%-.5i|\n", nb);
	ft_printf("size:%5i|\n", nb);
	printf("size:%5i|\n", nb);
	ft_printf("size + space:% 5i|\n", nb);
	printf("size + space:% 5i|\n", nb);
	ft_printf("size + plus:%+5i|\n", nb);
	printf("size + plus:%+5i|\n", nb);
	ft_printf("size + minus:%-5i|\n", nb);
	printf("size + minus:%-5i|\n", nb);
	ft_printf("size + 0:%05i|\n", nb);
	printf("size + 0:%05i|\n", nb);
	ft_printf("size + 0 + plus:%+05i|\n", nb);
	printf("size + 0 + plus:%+05i|\n", nb);
	ft_printf("size + 0 + plus:%0+5i|\n", nb);
	printf("size + 0 + plus:%0+5i|\n", nb);
	ft_printf("size + 0 + prec:%05.3i|\n", nb);
	printf("size + 0 + prec:%05.3i|\n", nb);
	ft_printf("size + minus + prec:%-5.3i|\n", nb);
	printf("size + minus + prec:%-5.3i|\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3i|\n", nb);
	printf("size + plus + 0 + prec:%+05.3i|\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3i|\n", nb);
	printf("size + espace + zero + prec:%0 5.3i|\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3i|\n", nb);
	printf("size + espace + zero + prec:% 05.3i|\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3i|\n", -45);
	printf("size + minus + plus + prec:%-+5.3i|\n", -45);
	


	ft_printf("precision:%.0d|\n", 0);
	printf("precision:%.0d|\n", 0);

	return (0);
}
