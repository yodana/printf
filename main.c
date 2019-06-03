/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yofana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Createf: 2019/04/01 15:38:25 by yofana            #+#    #+#             */
/*   Upfatef: 2019/04/01 15:39:15 by yofana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>


/*int main()
{	//int nb = 0;
	char	*a = "trolol";
	char	b = '~';
long double c = 9223372036854775807;
	short int f = 32767;
//	printf("reel printf: %c\n",'f');
	//ft_printf("size + space:% 5d ", nb);
	ft_printf("mine: %5c|\n\n",'f');
	//printf("reel printf:  %s\n","lol");
	ft_printf("mine:  %s\n\n","lol");

	ft_printf("mine:  caractere = %c || chaine = %s\n\n",'f',"lol");

	//printf("reel printf: pointer -> %p\n",&a);
	ft_printf("mine: pointer -> %p\n\n",&a);

	printf("reel printf: f -> %d\n",2147483647);
	ft_printf("mine : f -> %d\n\n",2147483647);

	//printf("reel printf: hhf -> %hhd\n",b);
	ft_printf("mine : hhf -> %hhd\n\n",b);

	ft_printf("mine : f -> %d\n\n",-1);

	//printf("reel printf: hf -> %hd\n",f);
	ft_printf("mine : hf -> %hd\n\n",f);

	//printf("reel printf: lf -> %lf\n",2147483650);
	float nb = 1.0/0.0;
    
    ft_printf("space + prec + hash:%# .0f\n", nb);
    ft_printf("space + prec + hash:% #.0f\n", nb);
    ft_printf("Plus + prec / grande:%+.5f\n", nb);
    ft_printf("Plus + prec / petite:%+.0f\n", nb);
    ft_printf("Plus + prec + hash:%#+.0f\n", nb);
    ft_printf("Prec + 0:%0.5f\n", nb);
    ft_printf("Prec + minus:%-.5f\n", nb);
    ft_printf("size:%5f\n", nb);
    ft_printf("size + space:% 5f\n", nb);
    ft_printf("size + plus:%+5f\n", nb);
    ft_printf("size + space:%# 5f\n", nb);
    ft_printf("size + plus:%#+5f\n", nb);
    ft_printf("size + minus:%-5f\n", nb);
    ft_printf("size + 0:%05f\n", nb);
    ft_printf("size + 0 + plus:%+05f\n", nb);
    ft_printf("size + 0 + plus:%0+5f\n", nb);
    ft_printf("size + 0 + prec:%05.3f\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
    ft_printf("size + minus + prec:%-5.3f\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%+0#5.0f|\n", nb);
	printf("size + plus + 0 + prec + hash:%+0#5.0f|\n", nb);
   ft_printf("size + espace + zero + prec:%0 5.3f|\n", nb);
   printf("size + espace + zero + prec:%0 5.3f|\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3f|\n", nb);
	printf("size + espace + zero + prec:% 05.3f|\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("size + minus + plus + prec:%-+5.3f|\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	printf("size + minus + plus + prec + hash:%-#+5.0f|\n", nb);

	ft_printf("mine : llf -> %Lf\n\n",c);
	printf("reel : llf -> %Lf\n\n",c);
	printf("reel printf: i -> %i\n",033);
	ft_printf("mine : i -> %i\n\n",033);
	
	printf("reel printf: hi -> %hi\n",f);
	ft_printf("mine : hi -> %hi\n\n",f);

	printf("reel printf: li -> %li\n",2147483650);
	ft_printf("mine : li -> %li\n\n",2147483650);


	printf("reel printf: o -> %o\n",33);
	ft_printf("mine : o -> %o\n\n",33);

	printf("reel printf: o -> %o\n",27);
	ft_printf("mine : o -> %o\n\n",27);

	printf("reel printf: o -> %o\n",-1);
	ft_printf("mine : o -> %o\n\n",-1);

	 printf("reel printf: ho -> %ho\n",f);
	ft_printf("mine : ho -> %ho\n\n",f);

	printf("reel printf: hho -> %hho\n",b);
	ft_printf("mine : hho -> %hho\n\n",b);

	printf("reel printf: lo -> %lo\n",2147483650);
	ft_printf("mine : lo -> %lo\n\n",2147483650);

	printf("reel printf: u -> %u\n",-1);
	ft_printf("mine : u -> %u\n\n",-1);

	printf("reel printf: hu -> %hu\n",f);
	ft_printf("mine : hu -> %hu\n\n",f);

	printf("reel printf: hhu -> %hhu\n",b);
	ft_printf("mine : hhu -> %hhu\n\n",b);

	printf("reel printf: lu -> %lu\n",2147483650);
	ft_printf("mine : lu -> %lu\n\n",2147483650);


	printf("reel printf: x -> %x\n",2000);
	ft_printf("mine : x -> %x\n\n",2000);

	printf("reel printf: hx -> %hx\n",f);
	ft_printf("mine : hx -> %hx\n\n",f);

	printf("reel printf: hhx -> %hhx\n",b);
	ft_printf("mine : hhx -> %hhx\n\n",b);

	printf("reel printf: lx -> %lx\n",2147483650);
	ft_printf("mine : lx -> %lx\n\n",2147483650);

	
	
	printf("reel printf: X -> %X\n",2000);
	ft_printf("mine : X -> %X\n\n",2000);

	printf("reel printf: hX -> %hX\n",f);
	ft_printf("mine : hX -> %hX\n\n",f);

	printf("reel printf: hhX -> %hhX\n",b);
	ft_printf("mine : hhX -> %hhX\n\n",b);

	printf("reel printf: lX -> %lX\n",2147483650);
	ft_printf("mine : lX -> %lX\n\n",2147483650);


	double i = 253.99999;
	float k = 253.999999;
	double inf = 1.0/0.0;
	double inf_neg = -1.0/0.0;
	double test2 = 1.0/10.0;
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
	
	printf("reel printf : f ->%f\n",maxi + 10.0);
	ft_printf("mine: f -> %f\n\n",maxi + 10.0);
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

	printf("reel : 0 with f -> %0d\n",1);
	ft_printf("mine : 0 with f -> %0d\n\n",1);


	printf("reel : + with f -> %+d\n",2);
	ft_printf("mine : + with f -> %+d\n\n",2);


	printf("\nreel : espace with f -> % d|\n",0);
	ft_printf("mine : espace with f -> % d|\n\n",0);

	printf("reel : champ with f -> % 5f|\n",10.0);
	ft_printf("mine : champ with f -> % 5f|\n\n",10.0);

	printf("reel : champ anf - with f -> %-5f|\n",10.0);
	ft_printf("mine : champ anf - with f -> %-5f|\n\n",10.0);

	printf("reel : champ anf - with f neg -> %5f|\n",-10.0);
	ft_printf("mine : champ anf - with f neg -> %5f|\n\n",-10.0);

	printf("reel : champ anf + with f -> %+5f|\n",10.0);
	ft_printf("mine : champ anf + with f -> %+5f|\n\n",10.0);

	printf("reel : champ anf + with f neg -> %20x|\n",-10);
	ft_printf("mine : champ anf + with f neg -> %20x|\n\n",-10);

	printf("reel : champ with c -> %5c|\n",'s');
	ft_printf("mine : champ with c -> %5c|\n\n",'s');

	printf("reel : champ anf - with c -> %-5c|\n",'s');
	ft_printf("mine : champ anf - with c -> %-5c|\n\n",'s');

	printf("reel : champ with s -> %5s|\n","lol");
	ft_printf("mine : champ with s -> %5s|\n\n","lol");

	printf("reel : champ anf - with s -> %-5s|\n","lol");
	ft_printf("mine : champ anf - with s -> %-5s|\n\n","lol");

	int o = 10.0;
	printf("reel : champ with p -> %30p|\n",&o);
	ft_printf("mine : champ with p -> %30p|\n\n",&o);

	printf("reel : champ anf - with p -> %-30p|\n",&o);
	ft_printf("mine : champ anf - with p -> %-30p|\n\n",&o);

	printf("reel : champ anf + anf # with f -> %#5x|\n",10.0);
	ft_printf("mine : champ anf + anf # with f -> %#5x|\n\n",10.0);

	printf("reel : champ anf # anf - with f -> %#-5x|\n",10.0);
	ft_printf("mine : champ anf # anf - with f -> %#-5x|\n\n",10.0);

	printf("reel : champ with f -> %f|\n",1.0);
	ft_printf("mine : champ with f -> %f|\n\n",1.0);

	printf("reel : champ anf + with f -> % 010.0f|\n",1.0);
	ft_printf("mine : champ anf + with f -> % 010.0f|\n\n",1.0);

	printf("reel : champ with f -> %10.0f|\n",1.0);
	ft_printf("mine : champ with f -> %10.0f|\n\n",1.0);

	printf("reel : champ with f -> %-30f|\n",-1.0);
	ft_printf("mine : champ with f -> %-30f|\n\n",-1.0);

	printf("reel : champ anf 0 with f -> %05f|\n",10.0);
	ft_printf("mine : champ amf 0 with f -> %05f|\n\n",10.0);

	printf("reel : champ with c -> %5c|\n",'p');
	ft_printf("mine : champ with c -> %5c|\n\n",'p');

	printf("reel : champ anf 0 with f -> % 020f|\n",-10.0.0);
	ft_printf("mine : champ anf 0 with f -> % 020f|\n\n",-10.0.0);

	printf("reel : precision with f -> %10.0.05f|\n",-10.0);
	ft_printf("mine : precision with f -> %10.0.05f|\n\n",-10.0);
	
	printf("reel : precision with s-> %.5s|\n","10.0");
	ft_printf("mine : precision with s-> %.5s|\n","10.0");
	
	//printf("reel : precision with f -> %.5f|\n",10.0.0);
	
	printf("reel : %-20f|\n",42.42);
	ft_printf("mine : %-20f|\n",42.42);
	return (0);
}*/

/*int		main()
{

	double nb = -0;

    nb = -0.0;
	ft_printf("space:% f|\n", nb);
	printf("space:% f|\n", nb);
    ft_printf("plus:%+f|\n", nb);
	printf("plus:%+f|\n", nb);
    ft_printf("hash:%#f|\n", nb);
	printf("hash:%#f|\n", nb);
    ft_printf("precision:%.2f|\n", nb);
	printf("precision:%.2f|\n", nb);
    ft_printf("big prec:%.14f|\n", nb);
	printf("big prec:%.14f|\n", nb);
    ft_printf("precision + hash:%#.0f|\n", nb);
	printf("precision + hash:%#.0f|\n", nb);
    ft_printf("space + prec:% .5f|\n", nb);
	printf("space + prec:% .5f|\n", nb);
    ft_printf("space + prec + hash:%# .0f|\n", nb);
		printf("space + prec + hash:%# .0f|\n", nb);
    ft_printf("space + prec + hash:% #.0f|\n", nb);
	printf("space + prec + hash:% #.0f|\n", nb);
    ft_printf("Plus + prec / granfe:%+.5f|\n", nb);
	printf("Plus + prec / granfe:%+.5f|\n", nb);
    ft_printf("Plus + prec / petite:%+.0f|\n", nb);
	printf("Plus + prec / petite:%+.0f|\n", nb);
    ft_printf("Plus + prec + hash:%#+.0f|\n", nb);
	printf("Plus + prec + hash:%#+.0f|\n", nb);
    ft_printf("Prec + 0:%0.5f|\n", nb);
	printf("Prec + 0:%0.5f|\n", nb);
    ft_printf("Prec + minus:%-.5f|\n", nb);
	printf("Prec + minus:%-.5f|\n", nb);
    ft_printf("size:%5f|\n", nb);
	printf("size:%5f|\n", nb);
    ft_printf("size + space:% 5f|\n", nb);
	printf("size + space:% 5f|\n", nb);
    ft_printf("size + plus:%+5f|\n", nb);
		printf("size + plus:%+5f|\n", nb);
    ft_printf("size + space:%# 5f|\n", nb);
	printf("size + space:%# 5f|\n", nb);
    ft_printf("size + plus:%#+5f|\n", nb);
	printf("size + plus:%#+5f|\n", nb);
    ft_printf("size + minus:%-5f|\n", nb);
	printf("size + minus:%-5f|\n", nb);
    ft_printf("size + 0:%05f|\n", nb);
		printf("size + 0:%05f|\n", nb);
    ft_printf("size + 0 + plus:%+05f|\n", nb);
	printf("size + 0 + plus:%+05f|\n", nb);
    ft_printf("size + 0 + plus:%0+5f|\n", nb);
		printf("size + 0 + plus:%0+5f|\n", nb);
    ft_printf("size + 0 + prec:%05.3f|\n", nb);
	printf("size + 0 + prec:%05.3f|\n", nb);
    ft_printf("size + 0 + prec + hash:%0#5.0f|\n", nb);
	printf("size + 0 + prec + hash:%0#5.0f|\n", nb);
    ft_printf("size + minus + prec:%-5.3f|\n", nb);
	printf("size + minus + prec:%-5.3f|\n", nb);
    ft_printf("size + minus + prec + hash:%-#5.0f|\n", nb);
	printf("size + minus + prec + hash:%-#5.0f|\n", nb);
    ft_printf("size + plus + 0 + prec:%+05.3f|\n", nb);
	printf("size + plus + 0 + prec:%+05.3f|\n", nb);
    ft_printf("size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
	printf("size + plus + 0 + prec + hash:%0+#5.0f|\n", nb);
    ft_printf("size + espace + zero + prec:%0 5.3f|\n", nb);
	printf("size + espace + zero + prec:%0 5.3f|\n", nb);
    ft_printf("size + espace + zero + prec:% 05.3f|\n", nb);
		printf("size + espace + zero + prec:% 05.3f|\n", nb);
    ft_printf("size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
	printf("size + espace + zero + prec + hash:%#0 5.0f|\n", nb);
    ft_printf("size + minus + plus + prec:%-+5.3f|\n", nb);
	printf("size + minus + plus + prec:%-+5.3f|\n", nb);
    ft_printf("size + minus + plus + prec + hash:%-#+5.0f|\n", nb);	
	printf("size + minus + plus + prec + hash:%-#+5.0f|\n", nb);
	return (0);
}*/

/*int main()
{
int		nb;

	nb = 45;

	printf("precision:%.5u|\n", nb);
	ft_printf("precision:%.5u|\n", nb);
	printf("Prec + 0:%0.5u|\n", nb);
	ft_printf("Prec + 0:%0.5u|\n", nb);
	printf("Prec + minus:%-.5u|\n", nb);
	ft_printf("Prec + minus:%-.5u|\n", nb);
	printf("size:%5u|\n", nb);
	ft_printf("size:%5u|\n", nb);
	printf("size + minus:%-5u|\n", nb);
	ft_printf("size + minus:%-5u|\n", nb);
	printf("size + 0:%05u|\n", nb);
	ft_printf("size + 0:%05u|\n", nb);
	printf("size + 0 + prec:%05.3u|\n", nb);
	ft_printf("size + 0 + prec:%05.3u|\n", nb);
	printf("size + minus + prec:%-5.3u|\n", nb);
	ft_printf("size + minus + prec:%-5.3u|\n", nb);
	printf("%-5.3u|\n", nb);
	ft_printf("%050.u\n", nb);
	printf("%050.u\n", nb);
	ft_printf("%-5.3u|\n", nb);
	printf("%-1.45u|\n", nb);
	ft_printf("%-1.45u|\n", nb);
	printf("%-55.35u|\n", nb);	
	ft_printf("%-55.35u|\n", nb);

	return (0);
}*/

/*int main()
{
	char *str = "Okalmos Speculos";
	ft_printf("test basique:%s|\n",str);
	printf("test basique:%s|\n", str);
	ft_printf("precision / zero:%.0s|\n", str);
	printf("precision / zero:%.0s|\n", str);
	ft_printf("precision / petite:%.5s|\n", str);
	printf("precision / petite:%.5s|\n", str);
	ft_printf("precision / granfe:%.15s|\n", str);
	printf("precision / granfe:%.15s|\n", str);
	ft_printf("prec + minus:%-.5s|\n", str);
	printf("prec + minus:%-.5s|\n", str);
	ft_printf("size / petite:%5s|\n", str);
	printf("size / petite:%5s|\n", str);
	ft_printf("size / granfe:%15s|\n", str);
	printf("size / granfe:%15s|\n", str);
	ft_printf("Minus + size / petite:%-5s|\n", str);
	printf("Minus + size / petite:%-5s|\n", str);
	ft_printf("Minus + size / granfe:%-15s|\n", str);
	printf("Minus + size / granfe:%-15s|\n", str);
	ft_printf("Minus" GREEN "+ size + prec :%-15.5s|"END_COLOR"\n", str);
	printf("Minus + size + prec:%-15.5s|\n", str);
	ft_printf(GREEN"%Lf\n"END_COLOR,LDBL_MAX);
	ft_printf("NULL:%12s|\n", NULL);
	printf("NULL:%12s|\n", NULL);
	ft_printf("NULL:%1s|\n", NULL);
	printf("NULL:%1s|\n", NULL);
	ft_printf("NULL:%-5.6s|\n", NULL);
	printf("NULL:%-5.6s|\n", NULL);
	ft_printf("NULL:%-.8s|\n", NULL);
	printf("NULL:%-.8s|\n", NULL);
	ft_printf("NULL:%.12s|\n", NULL);
	printf("NULL:%.12s|\n", NULL);
	ft_printf("empty:%-.5s|\n", "");
	printf("empty:%-.5s|\n", "");
	ft_printf("empty:%-1.32s|\n", "");
	printf("empty:%-1.32s|\n", "");
	ft_printf("empty:%1.4s|\n", "");
	printf("empty:%1.4s|\n", "");
	ft_printf("empty:%23s|\n", "");
	printf("empty:%23s|\n", "");
	ft_printf("%.15f\n",1345.1);
	printf("%.15f",1345.1);
	ft_printf("%.0s|\n", "");
	printf("%.0s|\n", "");
	ft_printf("%.0s|\n", NULL);
	printf("%.0s|\n", NULL);
	ft_printf("%%|\n");
	printf("%%|\n\n");
	ft_printf("%5%|\n");
	printf("%5%|\n\n");
	ft_printf("%-5%|\n");
	printf("%-5%|\n\n");
	ft_printf("%.5%|\n");
	printf("%.5%|\n\n");
	ft_printf("% %|\n");
	printf("% %|\n\n");
	//int i = ft_printf("%.0s|\n", "Okalm");
	//ft_printf("%D %C %F\n", 123, 'A', 1235.123);
	
	return 0;
}*/

int main()
{
	double e;
	e = 42.07;
	printf("reel : e -> %.2e\n",e);
	ft_printf("mine : e -> %.2e\n",e);
	//ft_printf("mine : f -> %.2f\n\n",e);
}
