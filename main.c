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
	return (0);
}