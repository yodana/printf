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
	printf("reel printf: %c\n",'d');
	ft_printf("mine: %c\n",'d');

	printf("reel printf:  %s\n","lol");
	ft_printf("mine:  %s\n","lol");

	printf("reel printf:  caratctere = %c || chaine = %s\n",'d',"lol");
	ft_printf("mine:  caractere = %c || chaine = %s\n",'d',"lol");

	printf("reel printf: pointer -> %p\n",&a);
	ft_printf("mine: pointer -> %p\n",&a);

	printf("reel printf: d -> %d\n",2147483647);
	ft_printf("mine : d -> %d\n",2147483647);

	printf("reel printf: hhd -> %hhd\n",b);
	ft_printf("mine : hhd -> %hhd\n",b);

	printf("reel printf: d -> %d\n",-1);
	ft_printf("mine : d -> %d\n",-1);

	//printf("reel printf: hd -> %hd\n",32768);
	//ft_printf("mine : hd -> %hd\n",32768);

	printf("reel printf: ld -> %ld\n",2147483650);
	ft_printf("mine : ld -> %ld\n",2147483650);
	return (0);
}