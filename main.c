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
int main()
{
	/*char	*a = "trolol";
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
	printf("reel printf : lf ->%lf\n",t);
	ft_printf("mine : lf-> %lf\n\n",t);
*/
	//printf("reel printf : Lf-> %Lf\n",LDBL_MAX);
	//ft_printf("mine : f-> %f\n\n",-0.1);
	//ft_printf("mine : f -> %Lf\n\n",-0.1);
	
	double l = -42.42;
	ft_printf("mine: f->%f\n",l);
	return (0);
}