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

int main()
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
	
	double i = 253.000000099;
	double ss = 3.09;

	printf("reel printf: f -> %f\n",i);
	ft_printf("mine : f -> %f\n\n",i);

	printf("reel printf: f -> %.26f\n",i);
	printf("reel printf: f -> %f\n",ss);
	return (0);
}